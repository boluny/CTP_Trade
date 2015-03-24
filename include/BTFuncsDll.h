
#ifndef BT_FUNCSDLL_H
#define BT_FUNCSDLL_H

#include <windows.h>
#include "QuantStruct.h"

#ifdef LIB_API_EXPORT
#define API_EXPORT __declspec(dllexport)
#else
#define API_EXPORT __declspec(dllimport)
#endif

//������Ӧ
typedef int(*BTOrderRsp)(CQuantOrderField*, const char*);
//�ɽ��ر�
typedef int(*BTBarginRsp)(CQuantTradeField*, const char*);


/*******************************************************************************
* Function: BTMarketDataInsert
* -----------------------------------------------------------------------------
* Description: ��������¼��ӿ�
* Function:
******************************************************************************/
int API_EXPORT BTMarketDataInsert(CQuantDepthQuoteDataField* stmarket);

/*******************************************************************************
* Function: BTOrderInsert
* -----------------------------------------------------------------------------
* Description: ����¼��ӿ�
* Function:
******************************************************************************/
int API_EXPORT BTOrderInsert(CQuantOrderField * stOrder,const char* strName);

/*******************************************************************************
* Function: BTOrderCancel
* -----------------------------------------------------------------------------
* Description: ��������¼��ӿ�
* Function:
******************************************************************************/
int  API_EXPORT BTOrderCancel(CQuantOrderField * stOrder,const char* strName);
/*******************************************************************************
* Function: BTRegOrderRsp
* -----------------------------------------------------------------------------
* Description: ������Ӧ�ص�ע�ắ��
* Function:
******************************************************************************/
bool API_EXPORT BTRegOrderRsp(BTOrderRsp call);
/*******************************************************************************
* Function: BTRegBarginRsp
* -----------------------------------------------------------------------------
* Description: �ɽ��ر��ص�ע�ắ��
* Function:
******************************************************************************/
bool API_EXPORT BTRegBarginRsp(BTBarginRsp call);


/*******************************************************************************
* Class:  CBTJob
* -----------------------------------------------------------------------------
* Description:  �ز������
*
* Function:
*
******************************************************************************/
class API_EXPORT CBTJob
{
public:
	CBTJob();
	~CBTJob();
	//��ʼ��
	void init();
	//��ȡxml����
	void ReadConfig();
	//Python
	int Python();
	//���ף����飬�ز�
	void ProxyStart();
	//����
	void destroy();

	void Join();
};

#endif