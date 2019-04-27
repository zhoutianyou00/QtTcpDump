#include "WinPcap.h"
#include "tcp_header.h"
CWinPcap::CWinPcap()
{
	alldevs = NULL;
	adhandle = NULL;
	//f = NULL;
}


CWinPcap::~CWinPcap()
{
	UnInit();
}


bool CWinPcap::Init()
{
	pcap_if_t *d =  NULL;
	int inum;
	int i = 0;
	pcap_t *adhandle;
	char errbuf[PCAP_ERRBUF_SIZE];

	if (pcap_findalldevs(&alldevs, errbuf) == -1)
	{
		fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
		exit(1);
	}

	/* Print the list */
	for (d = alldevs; d; d = d->next)
	{
		d->name;
		printf("%d. %s", ++i, d->name);
		if (d->description)
			printf(" (%s)\n", d->description);
		else
			printf(" (No description available)\n");
	}

	if (i == 0)
	{
		printf("\nNo interfaces found! Make sure WinPcap is installed.\n");
		return false;
	}
	return true;

}
void CWinPcap::UnInit()
{
	if (adhandle)
	{
		StopCapture();
	}

	if (alldevs)
	{
		pcap_freealldevs(alldevs);
		alldevs = NULL;
	}
	
}


std::string CWinPcap::GetMac(int id)
{

	if (alldevs == NULL)
		return 0;
	pcap_if_t *d = NULL;
	int i = 0;
	for (d = alldevs; d; d = d->next)
	{

		if (id == i)
		{
			return d->description;
		}

		printf("%d. %s", ++i, d->name);
		if (d->description)
			printf(" (%s)\n", d->description);
		else
			printf(" (No description available)\n");
	}

	return "";
}

int CWinPcap::GetMacsCnt()
{
	if (alldevs == NULL)
		return 0;
	pcap_if_t *d = NULL;
	int i = 0;
	for (d = alldevs; d; d = d->next)
	{
		printf("%d. %s", ++i, d->name);
		if (d->description)
			printf(" (%s)\n", d->description);
		else
			printf(" (No description available)\n");
	}

	return i;
}


pcap_if_t * CWinPcap::GetMacFromID(int id)
{
	if (alldevs == NULL)
		return 0;
	pcap_if_t *d = NULL;
	int i = 0;
	for (d = alldevs; d; d = d->next)
	{
		if (id == i)
			return d;
		i++;
	}
	return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{




	/*CWinPcap *pcap = (CWinPcap*)param;


	pcap->WriteFile((void*)pkt_data, 0);
	*/

	pcap_dump(param, header, pkt_data);

	return;

	


	struct tm *ltime;
	char timestr[16];
	time_t local_tv_sec;

	/*
	* unused parameters
	*/
	(VOID)(param);
	(VOID)(pkt_data);

	/* convert the timestamp to readable format */
	local_tv_sec = header->ts.tv_sec;
	ltime = localtime(&local_tv_sec);
	strftime(timestr, sizeof timestr, "%H:%M:%S", ltime);

	printf("%s,%.6d len:%d\n", timestr, header->ts.tv_usec, header->len);

}

bool CWinPcap::StartCapture(int id, std::string file, const char * filter)
{

	pcap_if_t * d = GetMacFromID(id);
	if (d == NULL)
		return false;
	char errbuf[PCAP_ERRBUF_SIZE];
	
	if ((adhandle = pcap_open_live(d->name,	// name of the device
		65536,			// portion of the packet to capture. 
		// 65536 grants that the whole packet will be captured on all the MACs.
		1,				// promiscuous mode (nonzero means promiscuous)
		1000,			// read timeout
		errbuf			// error buffer
		)) == NULL)
	{
		return false;
	}
	struct bpf_program fcode;
	u_int netmask;
	/* compile the filter */

	//char* filterString = "ether src D8:5D:4C:36:76:83 or ether dst D8:5D:4C:36:76:83";

	if (pcap_compile(adhandle, &fcode, filter, 1, netmask) < 0) {

		
		printf("Error\n");
		pcap_close(adhandle);
		adhandle = NULL;
		return false;
	}

	/* set the filter */
	if (pcap_setfilter(adhandle, &fcode) < 0) {
		printf("Error\n");
		pcap_close(adhandle);
		adhandle = NULL;
		return false;
	}

	this->file = file;

	bRun = true;
	th = std::thread(&CWinPcap::Run, this);
	return true;
}

void CWinPcap::StopCapture()
{
	if (adhandle)
	{
		pcap_close(adhandle);
		adhandle = NULL;
	}

	bRun = false;
	if (th.joinable())
		th.join();

	
	/*if (f)
	{
		fclose(f);
		f = NULL;
	}*/
	
}

void CWinPcap::WriteFile(void * data, int len)
{


	ipv4_header * ipv4 = (ipv4_header*)((uint8_t*)data + 14);


	int ipHeaderLen = (ipv4->ver_ihl & 0x0F) * 4;

	//TCP=6£¬ICMP=1£¬UDP=17
	if (ipv4->proto == 6)
	{
		//tcp
		tcp_header * tcp = (tcp_header *)((uint8_t*)data + 14 + ipHeaderLen);
		WriteFileTcp(tcp, ipv4->tlen - ipHeaderLen);
	}
}


void CWinPcap::WriteFileTcp(tcp_header * tcp, int len)
{

	int tcpHeadLen = ((tcp->HLen & 0xF0) >> 4 )*4;


	uint8_t *data = (uint8_t*)tcp;
	data += tcpHeadLen;

	/*if (f)
	{
		fwrite(data, 1, len - tcpHeadLen, f);
	}*/
}


void CWinPcap::Run()
{
	dumpfile = pcap_dump_open(adhandle, file.c_str());
	pcap_loop(adhandle, -1, packet_handler, (u_char*)dumpfile);
	while (bRun)
	{
		Sleep(30);
	}

	pcap_dump_close(dumpfile);
}