#ifndef __TCP_HEADER_H__
#define __TCP_HEADER_H__
#include <stdint.h>

typedef struct ether_header {
	uint8_t ether_dhost[6];   //Ŀ��MAC��ַ
	uint8_t ether_shost[6];   //ԴMAC��ַ
	uint16_t ether_type;     //Э������
}ETHHEADER, *PETHHEADER;

typedef struct ipv4_header {
	uint8_t ver_ihl;          //�汾 (4 bits) + �ײ����� (4 bits)
	uint8_t tos;			//��������
	uint16_t tlen;            //���ݱ��ܳ���
	uint16_t identification;    //��ʶ
	uint16_t flags_fo;        //��־ (3 bits) + Ƭƫ�� (13 bits)
	uint8_t ttl;             //����ʱ��
	uint8_t proto;           //Э��
	uint16_t crc;            //�ײ�У���
	uint8_t ip_src[4];              //ԴIP��ַ
	uint8_t ip_dst[4];              //Ŀ��IP��ַ
}IPHEADER, *PIPHEADER;


typedef struct tcp_header {
	uint16_t SourPort;       //Դ�˿ںš���
	uint16_t DestPort;       //Ŀ�Ķ˿ں�
	uint32_t SeqNo;       //���
	uint32_t AckNo;       //ȷ�����
	uint8_t HLen;          //�ײ����ȣ�����λ��
	uint8_t Flag;           //��ʶ������λ��
	uint16_t Window;       //���ڴ�С
	uint16_t ChkSum;       //У���
	uint16_t UrgPtr;        //����ָ��
}TCPHEADER, *PTCPHEADER;

typedef struct udp_header {
	uint16_t sport;          //Դ�˿ں�
	uint16_t dport;          //Ŀ�Ķ˿ں�
	uint16_t len;            //���ݱ�����
	uint16_t crc;            //У���
}UDPHEADER, *PUDPHEADER;

#endif