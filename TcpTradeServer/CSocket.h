#pragma once

#include <iostream>
#include <sstream>
#include <exception>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <winsock.h>
#include <io.h>
#include "TradingHeadField.h"
using namespace std;

/* Ҫʹ��winsock API����Ҫ����ws2_32.lib����� */
#pragma comment(lib, "ws2_32.lib")

typedef int SocketId;
typedef string Ip;
typedef unsigned int Port;
typedef int socklen_t;


//������Ϣ�ṹ��
struct RecvMsgStruct
{
	SOCKET  clientSocket;
	struct sockaddr_in ServerAddr;
};
DWORD WINAPI RecvOrderThread(LPVOID lpParameter);
DWORD WINAPI RecvHeartBeatThread(LPVOID lpParameter);


//�������ݽṹ����ʼ��sockaddr_in���ݣ����ظ�������ֵ
struct Address : protected sockaddr_in
{
private:
	void InitAddress(Ip, Port);

public:
	//���ֲ�ͬ�����Ĺ��캯�����ֱ����InitAddress
	//Ĭ��IP��port��ʼ����"0.0.0.0", 0
	Address();
	//server��ֻ����port
	Address(Port);
	//����IP��port��ʼ��
	Address(Ip, Port);
	
	//����IP
	Ip GetIp();
	Ip GetIp(Ip);
	//���ض˿�
	Port GetPort();
	Port GetPort(Port);
};

class CommonSocket
{
private:
	//��ʼ�� Winsock.dll
	void InitSocket(void);

protected:
	SocketId m_nSocketId;
	int m_nSocketType;
	bool m_bOpened;
	bool m_bBinded;

public:
	//���캯��,��ʼ��׼������
	//Winsock.dll,flag��ʼ��,����socket
	CommonSocket(int);
	//��������clean socket
	~CommonSocket(void);

	//����socket
	void Open(void);
	//�ر�socket
	void Close(void);
};

class TCP : public CommonSocket
{
private:
	Address m_strAddress;
	//map������յ�������
	map<order_id_t,KOrderResponse>  m_vecResponseOrders;
public:
	TCP();

	SocketId GetSocketId();
	Ip GetIp();
	Port GetPort();
	Address GetAddress();

	//server����;��������˿ں�listeners
	void BindListenPort(Port port, unsigned int listeners);
	TCP AcceptClient();

	void ServerReceive();

	//���պ�Ȼ�������ݲ���
	bool RecvOrder();

};


