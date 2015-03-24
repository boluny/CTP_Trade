/////////////////////////////////////////////////////////////////////////
///@system ��һ�������̨ϵͳ
///@company �㽭�д��ڻ����޹�˾
///@file ftdcMdApi.h
///@brief �����˿ͻ��˽ӿ�
///@history 
///20141202	����	�������ļ�
/////////////////////////////////////////////////////////////////////////

#if !defined(ZDQHv2_FTDCMDAPI_H)
#define ZDQHv2_FTDCMDAPI_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ftdcfieldstruct.h"

#if defined(ISLIB) && defined(WIN32)
#ifdef LIB_MD_API_EXPORT
#define MD_API_EXPORT __declspec(dllexport)
#else
#define MD_API_EXPORT __declspec(dllimport)
#endif
#else
#define MD_API_EXPORT 
#endif

class CFtdcMdSpi
{
public:
	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected(){};

	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	virtual void OnFrontDisconnected(int nReason){};

	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
	virtual void OnHeartBeatWarning(int nTimeLapse){};


	///��¼������Ӧ
	virtual void OnRspUserLogin(CFtdcRspUserLoginField *pRspUserLogin, CFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};

	///�ǳ�������Ӧ
	virtual void OnRspUserLogout(CFtdcUserLogoutField *pUserLogout, CFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����Ӧ��
	virtual void OnRspError(CFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������Ӧ��
	virtual void OnRspSubMarketData(CFtdcSpecificInstrumentField *pSpecificInstrument, CFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};
	///ȡ����������Ӧ��
	virtual void OnRspUnSubMarketData(CFtdcSpecificInstrumentField *pSpecificInstrument, CFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�������֪ͨ
	virtual void OnRtnDepthMarketData(CFtdcDepthMarketDataField *pDepthMarketData) {};

	///��ѯ��ʷtickӦ��
	virtual void OnRspQryHisTick(CFtdcRspQryHisTickField *pRspQryHisTick, CFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ʷtick֪ͨ
	//virtual void OnRtnHisTick(CFtdcRspQryHisTickField *pRspQryHisTick, int nRequestID, bool bIsLast) {};
	virtual void OnRtnHisTick(CFtdcHisTickField *pRspQryHisTick) {};

	///��ѯ��K��Ӧ��
	virtual void OnRspQryKLineDay(CFtdcRspQryKLineDayField *pRspQryKLineDay, CFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��K��֪ͨ
	//virtual void OnRtnKLineDay(CFtdcRspQryHisTickField *pRspQryHisTick, int nRequestID, bool bIsLast) {};
	virtual void OnRtnKLineDay(CFtdcKLineDayField *pKLineDay) {};

	///��ѯ1����K��Ӧ��
	virtual void OnRspQryKLine1Minute(CFtdcRspQryKLine1MinuteField *pRspQryKLine1Minute, CFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///1����K��֪ͨ
	//virtual void OnRtnKLine1Minute(CFtdcRspQryHisTickField *pRspQryHisTick, int nRequestID, bool bIsLast) {};
	virtual void OnRtnKLine1Minute(CFtdcKLine1MinuteField *pKLine1Minute) {};
};

class MD_API_EXPORT CFtdcMdApi
{
public:
	///����MdApi
	///@param pszFlowPath ����������Ϣ�ļ���Ŀ¼��Ĭ��Ϊ��ǰĿ¼
	///@return ��������UserApi
	///modify for udp marketdata
	static CFtdcMdApi *CreateFtdcMdApi(const char *pszFlowPath = "", const bool bIsUsingUdp=false);

	///ɾ���ӿڶ�����
	///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
	virtual void Release() = 0;

	///��ʼ��
	///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
	virtual void Init() = 0;

	///�ȴ��ӿ��߳̽�������
	///@return �߳��˳�����
	virtual int Join() = 0;

	///��ȡ��ǰ������
	///@retrun ��ȡ���Ľ�����
	///@remark ֻ�е�¼�ɹ���,���ܵõ���ȷ�Ľ�����
	virtual const char *GetTradingDay() = 0;

	///ע��ǰ�û������ַ
	///@param pszFrontAddress��ǰ�û������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001���� 
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
	virtual void RegisterFront(char *pszFrontAddress) = 0;

	///ע��ص��ӿ�
	///@param pSpi �����Իص��ӿ����ʵ��
	virtual void RegisterSpi(CFtdcMdSpi *pSpi) = 0;

	///�������顣
	///@param ppInstrumentID ��ԼID  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark 
	virtual int SubscribeMarketData(char *ppInstrumentID[], int nCount) = 0;

	///�˶����顣
	///@param ppInstrumentID ��ԼID  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark 
	virtual int UnSubscribeMarketData(char *ppInstrumentID[], int nCount) = 0;

	///�ǳ�����
	virtual int ReqUserLogout(CFtdcUserLogoutField *pUserLogout, int nRequestID) = 0;

	///������������Ӳ�ѯK�߽ӿ�

	///�û���¼����
	virtual int ReqUserLogin(CFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;

	///��ѯ��ʷtick
	virtual int ReqQryHisTick(CFtdcReqQryHisTickField *pReqQryHisTickField, int nRequestID) = 0;

	///��ѯ��K��
	virtual int ReqQryKLineDay(CFtdcReqQryKLineDayField *pReqQryHisTickField, int nRequestID) = 0;

	///��ѯ1����K��
	virtual int ReqQryKLine1Minute(CFtdcReqQryKLine1MinuteField *pReqQryKLine1MinuteField, int nRequestID) = 0;
protected:
	~CFtdcMdApi(){};
};

#endif
