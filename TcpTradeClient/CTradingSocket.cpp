#include "CTradingSocket.h"
#include "TradingHeadField.h"
#include "CSocket.h"
#include <wtypes.h>
#include <comutil.h>

//#include <Winsock2.h>
//#include <Windows.h>
//#include <sstream>
//
//#pragma comment(lib,"Ws2_32.lib")

#pragma comment(lib, "comsuppw.lib")
#pragma comment(lib, "kernel32.lib")

extern map<order_id_t,KOrderResponse> g_mapResponseOrders;

//LPCTSTR��const char*
//Direciton,LimitPrice,StopPrice,Duration,Transit_Now,HedgeFlagδʹ��
LONG CTradingSocket::ReqOrder(LPCTSTR InstrumentID, LPCTSTR Direciton, LONG Volumn,LPCTSTR Type, DOUBLE LimitPrice,DOUBLE StopPrice,LPCTSTR Duration,BOOL Transit_Now,  LPCTSTR OffsetFlag, LPCTSTR HedgeFlag, LPCTSTR Account)
{
	KOrderRequest strOrderRequest;
	//��ʼ��
	strcpy(strOrderRequest.account_id,Account);
	strcpy(strOrderRequest.instrument_id,InstrumentID);
	strOrderRequest.action=INSERT;
	strOrderRequest.volume_original=Volumn;
	int nDireciton=atoi(Direciton);
	strOrderRequest.side=(KORDER_SIDE)nDireciton;
	int nType=atoi(Type);
	strOrderRequest.order_type=(KORDER_TYPE)nType;
	int nOffsetFlag=atoi(OffsetFlag);
	strOrderRequest.open_close=(KOPENCLOSE_TYPE)nOffsetFlag;
	int nHedgeFlag=atoi(HedgeFlag);
	strOrderRequest.speculator=(KSPECULATOR_TYPE)nHedgeFlag;
	strOrderRequest.price_original=LimitPrice;

	//ֱ�ӷ������ݽṹ
	bool flag=m_CTtcp.SendOrder(strOrderRequest);
	if(flag)  
		return strOrderRequest.orderid;
	else	
		return 0;
	
}

SHORT CTradingSocket::Cancel(LONG orderID)
{
	KOrderRequest strOrderRequest;
	strOrderRequest.orderid=orderID;
	strOrderRequest.action=CANCEL;
	
	bool flag=m_CTtcp.SendOrder(strOrderRequest);

	if(flag)  return 1;
	else	return 0;
}

BSTR CTradingSocket::GetExecInfo(LONG OrderID, LPCTSTR Type)
{
	KOrderResponse  orderResponse;
	//m_CTtcp.GetRecvOrders()����Map��������,map<order_id_t,KOrderResponse>
	//orderResponse=m_CTtcp.GetRecvOrders()[OrderID];
	orderResponse=g_mapResponseOrders[OrderID];
	
	//str���ڱ����м����ݣ�Ȼ��ת����BSTR����
	char str[20]={NULL};
	if (!strcmp(Type,"Fills"))
	{
		itoa(orderResponse.price_traded,str,10);
	}
	else if(!strcmp(Type,"FilledQuantity"))
	{
		itoa(orderResponse.volume_original,str,10);
	}
	//(order_status)��ȡ����״̬ ��osRejectGW�������ܾ� ��osCanceled������
	//��osFilled���ɽ� ��osPending���ѱ� ��osPartCanceled�����ֳ���  "osPartFilled"���ֳɽ�
	//ͨ��switch���ж�ѡ����Ӧ��enum����
	else if (!strcmp(Type,"GWStatus"))
	{
		switch(orderResponse.order_status)
		{
		case CANCELED:
			strcpy(str,"osCanceled");
			break;
		case ALL_TRADED:
			strcpy(str,"osFilled");
			break;
		}
	}
	else if (!strcmp(Type,"CanBeCanceled"))
	{
		if (orderResponse.rsp_type==RT_CANCEL_REJECTED)
		{
			strcpy(str,"1");
		}
		else
			strcpy(str,"0");		
	}

	BSTR returnText = _com_util::ConvertStringToBSTR(str);
	return returnText;
}