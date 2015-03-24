#include "CSocket.h"

//ȫ�ֱ���������CPP��
//������������Ϊȫ�ֺ���
map<order_id_t,KOrderResponse>  g_mapResponseOrders;
//����һ�����̣߳����ڽ��մӷ������˷��͹�������Ϣ
DWORD WINAPI RecvOrderThread(LPVOID lpParameter)
{
	//socket������Ϣ��ȡ
	RecvMsgStruct *recvStruct=(RecvMsgStruct *)lpParameter;
	SOCKET clientSocket = recvStruct->clientSocket;
	struct sockaddr_in ServerAddr = recvStruct->ServerAddr;

	KOrderResponse orderResponse;
	order_id_t OrderId;
	while (1)
	{
		recv(clientSocket,(char*)&orderResponse,1024,0);

		OrderId=orderResponse.orderid;
		g_mapResponseOrders.insert(make_pair (OrderId, orderResponse));

		//Map���ݲ��ԣ�orderResponse.volume_original��������
		cout<<orderResponse.account_id<<endl<<orderResponse.instrument_id<<endl
			<<orderResponse.volume_original<<endl
			<<orderResponse.open_close<<endl<<endl;
	}
	return 0;
}

DWORD WINAPI RecvHeartBeatThread(LPVOID lpParameter)
{
	//socket������Ϣ��ȡ
	RecvMsgStruct *recvStruct=(RecvMsgStruct *)lpParameter;
	SOCKET clientSocket = recvStruct->clientSocket;
	struct sockaddr_in ServerAddr = recvStruct->ServerAddr;

	char heartbeat[15]="heart beat";
	while (1)
	{
		int flag=send(clientSocket ,heartbeat ,strlen(heartbeat),0);
		if (flag!=SOCKET_ERROR)
		{
			cout<<"yes , heartbeat is ok"<<endl;
			Sleep(4000);
		}
		else
		{
			//??����ش���
			if(connect(clientSocket, (struct sockaddr*)&ServerAddr, sizeof(struct sockaddr_in))<0)
			{
				Sleep(4000);
				cout<<"reconnect error"<<endl;
				continue;
			}
			cout<<"reconnect ok"<<endl;
			Sleep(4000);
		}
	}
	return 0;
}


void Address::InitAddress(Ip ip, Port port)
{
	sin_family = AF_INET;
	GetPort(port);		//sin_port = htons(port);
	GetIp(ip);		//sin_addr.s_addr = inet_addr ("127.0.0.1");
}

Address::Address()
{
	InitAddress("0.0.0.0", 0);
}

Address::Address(Ip ip, Port port)
{
	InitAddress(ip, port);
}

Port Address::GetPort()
{
	return ntohs(sin_port);
}

Port Address::GetPort(Port port)
{
	sin_port = htons(port);
	return GetPort();
}

Ip Address::GetIp()
{
	return inet_ntoa(sin_addr);
}

Ip Address::GetIp(Ip ip)
{
	unsigned long address = inet_addr(ip.c_str());

	if (address == INADDR_NONE)
	{
		cerr<< "[ip] with [ip=" << ip << "] Invalid ip address provided";
	}
	else
	{
		sin_addr.S_un.S_addr = address;
	}

	return GetIp();
}


void CommonSocket::InitSocket()
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("fail to init winsock.dll!\n");
		exit(-1);
	}
}

CommonSocket::CommonSocket(int socket_type)
{
	InitSocket();
	m_nSocketType = socket_type;
	m_bOpened = false;
	m_bBinded = false;
	Open();
}

CommonSocket::~CommonSocket()
{
	WSACleanup();
}


void CommonSocket::Open()
{
	if (!m_bOpened)
	{
		if ((m_nSocketId = socket(AF_INET, m_nSocketType, 0)) == -1)
			cerr<<"[open] Cannot create socket"<<endl;
		m_bOpened = true;
		m_bBinded = false;
	}
}

void CommonSocket::Close()
{
	if (m_bOpened)
	{
		closesocket(m_nSocketId);
		m_bOpened = false;
		m_bBinded = false;
	}
}

//���캯������ʼ���б�
TCP::TCP() : CommonSocket(SOCK_STREAM)
{
}

SocketId TCP::GetSocketId()
{
	return m_nSocketId;
}

Ip TCP::GetIp()
{
	return m_strAddress.GetIp();
};

Port TCP::GetPort()
{
	return m_strAddress.GetPort();
};

Address TCP::GetAddress()
{
	return m_strAddress;
}

void TCP::Connect(Address address)
{
	//�ڲ���Ա������ʼ��������Get���ز���
	m_strAddress=address;

	if (m_bBinded)	cerr<<"[Connect] Socket already binded to a port, use another socket"<<endl;
	if (!m_bOpened)	Open();	
	if (connect(m_nSocketId, (struct sockaddr*)&address, sizeof(struct sockaddr_in))<0)
	{
		cerr<<"[Connect] Cannot connect to the specified address"<<endl;
	}
	m_bBinded = true;
}

void TCP::ClientSend()
{
	char buf[4096];
	while (1)
	{
		int count = _read (0, buf, 1024);//�ӱ�׼�������
		if(count<=0)break;
		int sendCount,currentPosition=0;
		while( count>0 && (sendCount=send(m_nSocketId ,buf+currentPosition,count,0))!=SOCKET_ERROR)
		{
			count-=sendCount;
			currentPosition+=sendCount;
		}
		if(sendCount==SOCKET_ERROR)break;

		count =recv(m_nSocketId ,buf,1024,0);
		if(count==0)break;//���Է��ر�
		if(count==SOCKET_ERROR)break;//����count<0
		buf[count]='\0';
		printf("%s",buf);
	}
}

bool TCP::SendOrder(KOrderRequest orderRequest)
{
	//TCP����KOrderRequest�����ͻ�������������
	int sendCount,currentPosition=0;
	int count=sizeof(orderRequest);
	while( count>0 && (sendCount=send(m_nSocketId ,(char*)&orderRequest+currentPosition,count,0))!=SOCKET_ERROR)
	{
		count-=sendCount;
		currentPosition+=sendCount;
	}
	if(sendCount==SOCKET_ERROR)  
	{
		cerr<<"[Send]Socket send error"<<endl;
		return false;
	}
	return true;
}

//KOrderRequestͬһ���յ�vector�У��Թ�ҵ��������
bool TCP::RecvOrder()
{
	KOrderResponse orderResponse;
	order_id_t OrderId;
	while (1)
	{
		if ( recv(m_nSocketId,(char*)&orderResponse,1024,0) == SOCKET_ERROR)
		{
			printf("recv error!\n");
			return 0;
		}
		OrderId=orderResponse.orderid;
		m_vecResponseOrders.insert(make_pair (OrderId, orderResponse));
	}
}

bool TCP::RecvThreadOrder()
{
	//����һ�����̣߳����ڽ��մӷ������˷��͹�������Ϣ;��ʼ��������Ϣ
	struct RecvMsgStruct *msgRecv = new struct RecvMsgStruct();
	msgRecv->clientSocket = GetSocketId();
	msgRecv->ServerAddr.sin_family = AF_INET;
	msgRecv->ServerAddr.sin_port = htons(GetPort());
	//GetIp()����string����,��Ҫ��string����ת��const char*  
	string IP=GetIp();
	msgRecv->ServerAddr.sin_addr.s_addr = inet_addr(IP.c_str());

	HANDLE hRevcThread = CreateThread(NULL,0,RecvOrderThread,(LPVOID)msgRecv,0,NULL);
	//HANDLE hHeartBeatThread = CreateThread(NULL,0,RecvHeartBeatThread,(LPVOID)msgRecv,0,NULL);
	//�ȴ��߳̽���
	//WaitForSingleObject(hRevcThread, INFINITE);
	//WaitForSingleObject(hHeartBeatThread, INFINITE);

	return 0;
}

/*map<order_id_t,KOrderResponse>& TCP::GetRecvOrders()
{
	return g_mapResponseOrders;
}*/