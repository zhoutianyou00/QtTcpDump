#pragma once
#include <list>
#include <mutex>
#include <string>
#include <thread>
#include "pcap.h"
#include "tcp_header.h"
class CWinPcap
{
public:
	CWinPcap();
	~CWinPcap();


public:
	bool Init();
	void UnInit();
	int GetMacsCnt();
	std::string GetMac(int id);

public:
	bool StartCapture(int id, std::string file, const char * filter);
	void StopCapture();

public:
	void WriteFile(void * data, int len);
private:
	std::list < std::string> m_macs;
	pcap_if_t *alldevs;

private:
	pcap_if_t * GetMacFromID(int id);
	pcap_t *adhandle;
	pcap_dumper_t *dumpfile;
	int bRun;
	std::thread th;
	std::string file;
private:
	void WriteFileTcp(tcp_header * tcp, int len);
	void Run();

};

