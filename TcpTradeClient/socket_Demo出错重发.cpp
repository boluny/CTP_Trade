// WindowsSocketClient.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <Winsock2.h>
#include <Windows.h>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include "tinystr.h"
#include "tinyxml.h"
#pragma comment(lib,"Ws2_32.lib")

using namespace std;

#define PORT 8080
#define IP_ADDRESS "172.16.20.181"

#define LISTEN_PORT 8081
#define LISTEN_IP_ADDRESS "172.16.20.181"
//������Ϣ�ṹ��
struct SendMsgStruct
{
    SOCKET clientSocket;
    string msg;
    struct sockaddr_in ServerAddr;
};

//������Ϣ�ṹ��
struct RecvMsgStruct
{
    SOCKET  clientSocket;
    struct sockaddr_in ServerAddr;
};

//������Ϣ���߳�
DWORD WINAPI SendThread(LPVOID lpParameter);

//������Ϣ���߳�
DWORD WINAPI RecvThread(LPVOID lpParameter);

//ȥ���ַ�����β�ո�
void trim(string &str);

//����������������
DWORD WINAPI ListenServerThread(LPVOID lpParameter);

int _tmain(int argc, _TCHAR* argv[])
{
    //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN); 

    WSADATA  Ws;
     SOCKET ClientSocket,ServerSocket;
     struct sockaddr_in ServerAddr;
     int Ret = 0;
     int AddrLen = 0;
     HANDLE hThread = NULL;
     HANDLE hSendThread = NULL;
     HANDLE hRevcThread = NULL;
     HANDLE hListenThread = NULL;
     //The WSAStartup function initiates use of WS2_32.DLL by a process.
     //��ʼ�� Windows Socket
     if ( WSAStartup(MAKEWORD(2,2), &Ws) != 0 )
     {
         cout<<"��ʼ�� Socket ʧ��:"<<GetLastError()<<endl;
         return -1;
     }
 
     //���� Socket
     ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
     if ( ClientSocket == INVALID_SOCKET )
     {
         cout<<"���� Socket ʧ��:"<<GetLastError()<<endl;
         return -1;
     }
 
     ServerAddr.sin_family = AF_INET;
     ServerAddr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
     ServerAddr.sin_port = htons(PORT);
    
     //����ServerAddr��ǰ8���ַ�Ϊ0x00
     memset(ServerAddr.sin_zero, 0x00, 8);

     Ret = connect(ClientSocket,(struct sockaddr*)&ServerAddr, sizeof(ServerAddr));

    if( Ret == SOCKET_ERROR )
    {
        cout<<"�������ӹ��̷�������:"<<GetLastError()<<endl;
    }
    else
    {
        cout<<"���ӽ����ɹ�"<<endl;
    }
    //����һ�����̣߳������ӷ���������������
    /*hListenThread = CreateThread(NULL, 0, ListenServerThread, NULL, 0, NULL);
    WaitForSingleObject(hListenThread,INFINITE);
    if( hListenThread == NULL )
    {
        cout<<"���������������Կͻ��˵��������߳�ʧ��"<<endl;
        system("pause");
        return -1;
    }*/
    //����һ�����̣߳�������������˷�����Ϣ
    struct SendMsgStruct *msgSend = new struct SendMsgStruct();
    msgSend->clientSocket = ClientSocket;
    msgSend->msg = "���,Msg From Client";
    msgSend->ServerAddr = ServerAddr;
    //����һ��struct
    hSendThread = CreateThread(NULL, 0, SendThread, (LPVOID)msgSend, 0, NULL);
    WaitForSingleObject(hSendThread, INFINITE);

    if( hSendThread == NULL )
    {
        cout<<"����������Ϣ���߳�ʧ��"<<endl;
        system("pause");
        return -1;
    }

    //����һ�����̣߳����ڽ��մӷ������˷��͹�������Ϣ
    struct RecvMsgStruct *msgRecv = new struct RecvMsgStruct();
    msgRecv->clientSocket = ClientSocket;
    msgRecv->ServerAddr = ServerAddr;
    //����һ��structָ�����
    hRevcThread = CreateThread(NULL,0,RecvThread,(LPVOID)msgRecv,0,NULL);
    WaitForSingleObject(hRevcThread, INFINITE);

    if( hRevcThread == NULL )
    {
        cout<<"����������Ϣ���߳�ʧ��"<<endl;
        system("pause");
        return -1;
    }

    //�ͻ�������exit���˳�
    string  clientString ;
    do
    {
        getline(cin,clientString);

    }while( clientString != "exit" && clientString !="EXIT");
     closesocket(ClientSocket);
     WSACleanup();
    system("pause");
     return 0;
 }

//�����������������߳�
DWORD WINAPI ListenServerThread(LPVOID lpParameter)
{
     //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      //SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN); 

      //system("ipconfig /all >log.txt");
      //WSADATA �ṹ����Ҫ������ϵͳ��֧�ֵ�Winsock�汾��Ϣ
      WSADATA  Ws;
      SOCKET ServerSocket, ClientSocket;
      //TCP/IP �׽���ָ���׽��ֵĵ�ַ
      struct sockaddr_in LocalAddr, ServerAddr;
      int Ret = 0;
      int AddrLen = 0;
      HANDLE hThread = NULL;
  
      //��ʼ��Winsock2.2.ʹ��WSAStartup����
      //��һ����������Ҫ�õ�Winsock�汾��
      //The MAKEWORD macro creates a WORD value by concatenating the specified values. 
      //�ڶ�����������WSADATA �ṹ���ָ�롣�����ʼ���ɹ��򷵻�0
      //Ҫע���κ�WinsockAPI�����������ڳ�ʼ����ʹ�ã����������麯��
      if ( WSAStartup(MAKEWORD(2,2), &Ws) != 0 )
      {
          cout<<"��ʼ�� Socket ʧ��:"<<GetLastError()<<endl;
          return 0;
      }
      //Create Socket
      ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
      if ( ClientSocket == INVALID_SOCKET )
      {
          cout<<"�����ͻ��� Socket ʧ��:"<<GetLastError()<<endl;
          system("pause");
          return 0;
      }

      //the address of family specification
      LocalAddr.sin_family = AF_INET;

      //The inet_addr function converts a string containing an (Ipv4) Internet Protocol dotted address into a proper address for the IN_ADDR structure.
      LocalAddr.sin_addr.s_addr = inet_addr(LISTEN_IP_ADDRESS); 

      //The htons function converts a u_short from host to TCP/IP network byte order (which is big-endian).
      LocalAddr.sin_port = htons(LISTEN_PORT);

      //Sets buffers to a specified character.
      memset(LocalAddr.sin_zero, 0x00, 8);
  
      //Bind Socket,The bind function associates a local address with a socket.
      Ret = bind(ClientSocket, (struct sockaddr*)&LocalAddr, sizeof(LocalAddr));
      if ( Ret != 0 )
      {
          cout<<"�� Socket ʧ��:"<<GetLastError()<<endl;
          return 0;
      }
    
      //listen �����׽��ּ������Է���˵�����.
      //�ڶ������������������.
      Ret = listen(ClientSocket, 10);
      if ( Ret != 0 )
      {
          cout<<"���� Server Socket ʧ��:"<<GetLastError()<<endl;
          return 0;
      }
    
      cout<<"�ͻ����Ѿ����������ڼ���"<<endl;

          AddrLen = sizeof(ServerAddr);

          //The accept function permits an incoming connection attempt on a socket.
          //���ռ��������Ŀͻ������ӡ�
          ServerSocket = accept(ClientSocket, (struct sockaddr*)&ServerAddr, &AddrLen);
        
          if ( ClientSocket == INVALID_SOCKET )
          {
              cout<<"���շ���������Ϣʧ�� :"<<GetLastError()<<endl;
              system("pause");
             // break;
          }
          else
          {
              //The inet_ntoa function converts an (Ipv4) Internet network address into a string in Internet standard dotted format.
              cout<<"\n������������ :"<<inet_ntoa(ServerAddr.sin_addr)<<":"<<ServerAddr.sin_port<<endl;
          }
     string cmdstr ; 
     do
     {
         getline(cin,cmdstr);
     }while(cmdstr != "exit" && cmdstr != "EXIT");
     closesocket(ClientSocket);
     //����������Ҳ����Щӵ�أ����ڱ�����ֻ��Ϊ�������ݡ�
     //���ǵ��������ܻ����ȫ������ĳЩʵ�ֻ�ʹ����������ws2_32.DLL
     WSACleanup();

    return 0;
}

//������Ϣ���߳�
DWORD WINAPI SendThread(LPVOID lpParameter)
{    
    SendMsgStruct *myStruct = (SendMsgStruct *)lpParameter;
    SOCKET ClientSocket = myStruct->clientSocket;
    string SendMsg = myStruct->msg;
    struct sockaddr_in ServerAddr = myStruct->ServerAddr;

    while( true )
    {    
        int flag = 0;
        int bufSize = SendMsg.length();
        char * buf = const_cast<char*>(SendMsg.c_str());
        flag = send(ClientSocket, buf, bufSize, 0);

        //�жϵ�ǰʱ����ڿ�������,���û�У��ٴ�����
        while( flag == -1 || flag == 0)
        {
            cout<<"׼������"<<endl;
            //shutdown(ClientSocket,2);
            closesocket(ClientSocket);
            ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            int cunnectFlag = connect(ClientSocket,(struct sockaddr*)&ServerAddr, sizeof(ServerAddr));
            
            if( cunnectFlag == SOCKET_ERROR )
            {
                cout<<"����ʧ�� :"<<GetLastError()<<endl;
                Sleep(5000);
                //cunnectFlag = connect(ClientSocket,(struct sockaddr*)&ServerAddr, sizeof(ServerAddr));
            }
            else
            {
                break;
            }
        }

        //��������б���
        //if( flag == SOCKET_ERROR )
        //{
        //        cout<<"��Ϣ���͹����б���:"<<GetLastError()<<endl;
        //}
        //û�д������
        //else if( flag < bufSize )
        if( flag < bufSize )
        {
            flag = send(ClientSocket, buf, bufSize - flag, 0);
        }
        //����ɹ�
        else
        {
            cout<<"\n��Ϣ����ɹ�"<<endl;
        }

        //ÿ5�뷢��һ��
        Sleep(5000);
    }
    return 0;
}

//������Ϣ���߳�
DWORD WINAPI RecvThread(LPVOID lpParameter)
{

    RecvMsgStruct *recvStruct=(RecvMsgStruct *)lpParameter;
    SOCKET clientSocket = recvStruct->clientSocket;
    struct sockaddr_in ServerAddr = recvStruct->ServerAddr;
    char recvBuf[500]={"0"}; 
     int byteRecv = recv(clientSocket, recvBuf, 500, 0);
     int connectState;
     while( byteRecv == 0 )
     {
         //���ӶϿ�������
        cout<<"byteRecv == 0"<<endl;
        shutdown(clientSocket,2);
        //closesocket(ClientSocket);
        clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        connectState = connect(clientSocket,(struct sockaddr*)&ServerAddr, sizeof(ServerAddr));

        if( connectState == SOCKET_ERROR )
        {
            cout<<"�������ӷ�������,�������:"<<GetLastError()<<endl;
        }
        else
        {
            cout<<"-----------------------------------------------In"<<endl;
            byteRecv = recv(clientSocket, recvBuf, 500, 0);//�������Ӻ����»�ȡһ����Ϣ
            recvBuf[byteRecv]=0;
        }
        Sleep(5000);
     }
    cout<<recvBuf<<endl;
    return 0;
}

//�Ƴ��ַ�����β�ո�
void trim(string &str)
{
      str.erase(str.find_last_not_of(' ')+1,string::npos);
      str.erase(0,str.find_first_not_of(' '));
}