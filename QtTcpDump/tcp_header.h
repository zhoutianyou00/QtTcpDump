#ifndef __TCP_HEADER_H__
#define __TCP_HEADER_H__
#include <stdint.h>

typedef struct ether_header {
	uint8_t ether_dhost[6];   //目的MAC地址
	uint8_t ether_shost[6];   //源MAC地址
	uint16_t ether_type;     //协议类型
}ETHHEADER, *PETHHEADER;

typedef struct ipv4_header {
	uint8_t ver_ihl;          //版本 (4 bits) + 首部长度 (4 bits)
	uint8_t tos;			//服务类型
	uint16_t tlen;            //数据报总长度
	uint16_t identification;    //标识
	uint16_t flags_fo;        //标志 (3 bits) + 片偏移 (13 bits)
	uint8_t ttl;             //生存时间
	uint8_t proto;           //协议
	uint16_t crc;            //首部校验和
	uint8_t ip_src[4];              //源IP地址
	uint8_t ip_dst[4];              //目的IP地址
}IPHEADER, *PIPHEADER;


typedef struct tcp_header {
	uint16_t SourPort;       //源端口号　　
	uint16_t DestPort;       //目的端口号
	uint32_t SeqNo;       //序号
	uint32_t AckNo;       //确认序号
	uint8_t HLen;          //首部长度（保留位）
	uint8_t Flag;           //标识（保留位）
	uint16_t Window;       //窗口大小
	uint16_t ChkSum;       //校验和
	uint16_t UrgPtr;        //紧急指针
}TCPHEADER, *PTCPHEADER;

typedef struct udp_header {
	uint16_t sport;          //源端口号
	uint16_t dport;          //目的端口号
	uint16_t len;            //数据报长度
	uint16_t crc;            //校验和
}UDPHEADER, *PUDPHEADER;

#endif