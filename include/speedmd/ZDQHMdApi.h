/////////////////////////////////////////////////////////////////////////
///@system ��һ��������ϵͳ
///@company  �д��ڻ�
///@file ZDQHMdApi.h
///@brief �����˿ͻ�������ӿ�
///@history 
///20130923	�쵩		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef ZDQHMDAPIH
#define ZDQHMDAPIH

#include "ZDQHUserApiStruct.h"




class CZDQHFtdcMdSpi
{
public:
	///���ͻ����뽻�׺�̨������ͨ������ʱ
	virtual void OnFrontConnected(){};
	
	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӡ�
	virtual void OnFrontDisconnected(){};
		
	///��������Ӧ��
	virtual void OnRspSubMarketData(CZDQHFtdcSpecificInstrumentField *pSpecificInstrument, CZDQHFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ȡ����������Ӧ��
	virtual void OnRspUnSubMarketData(CZDQHFtdcSpecificInstrumentField *pSpecificInstrument, CZDQHFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�������֪ͨ
	virtual void OnRtnDepthMarketData(CZDQHFtdcDepthQuoteDataField *pDepthMarketData) {};

	///�۲�����֪ͨ
	virtual void OnRtnBasisQuote(CZDQHFtdcRspBasisQuoteField *pDepthMarketData) {};

	///level2��Ʊ����
	virtual void OnRtnLevel2StockQuote(CLevel2ZDQHFtdcLevel2MarketDataField* pDepthMarketData){};

	///level2ָ������
	virtual void OnRtnLevel2IndexQuote(CLevel2ZDQHFtdcNGTSIndexField* pDepthMarketData){};
};



class API_EXPORT CZDQHFtdcMdApi
{
public:
	
	///ɾ���ӿڶ�����
	///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
	virtual void Release() = 0;
	
	///�����ֻ����鿪��
	///@param bEnable true����  false ������
	virtual void EnableGetStockQuote(bool bEnable=true) = 0;

	///��ʼ��,���ӷ�����
	virtual void Init() = 0;	
	
	///ע��ص��ӿ�
	///@param pSpi �����Իص��ӿ����ʵ��
	virtual void RegisterSpi(CZDQHFtdcMdSpi *pSpi) = 0;
	
	///�������顣
	///@param exchangeID ������ID  
	///@param ppInstrumentID ��ԼID  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark   ����0 �ɹ�  ��0ʧ��
	virtual int SubscribeMarketData(TZDQHExchangeType exchangeID[] ,char *ppInstrumentID[], int nCount) = 0;
	
	///�˶����顣
	///@param exchangeID ������ID  
	///@param ppInstrumentID ��ԼID  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark 
	virtual int UnSubscribeMarketData(TZDQHExchangeType exchangeID[],char *ppInstrumentID[], int nCount) = 0;

	///���ļ۲�����
	///@param pReqBasisQuote ���ļ۲����� 
	///@return 0 �ɹ� ��0ʧ��
	///@remark 
	virtual int SubscribeBasisQuote(CZDQHFtdcReqBasisQuoteField* pReqBasisQuote) = 0 ;

	///�˶��۲�����
	///@param pReqBasisQuote �˶��۲����� 
	///@return 0 �ɹ� ��0ʧ��
	///@remark  ���û�������Լ�����˶����ж�������
	virtual int UnSubscribeBasisQuote(CZDQHFtdcReqBasisQuoteField* pReqBasisQuote) = 0;

	///���Ĺ�Ʊlevel2����
	///@param pReqSubLevel2 ���ĵĹ�Ʊ��Ϣ  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@param bIndex �Ƿ���ָ��
	///@return 0 �ɹ� ��0ʧ��
	///@remark 
	virtual int SubStockLevel2Quote(CZDQHStockLevel2Field* pReqSubLevel2, int nCount, bool bIndex=false) = 0;

	///�˶���Ʊlevel2����
	///@param pReqSubLevel2 �˶��Ĺ�Ʊ��Ϣ  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@param bIndex �Ƿ���ָ��
	///@return 0 �ɹ� ��0ʧ��
	///@remark 
	virtual int UnSubStockLevel2Quote(CZDQHStockLevel2Field* pReqSubLevel2, int nCount, bool bIndex=false) = 0;


protected:
	virtual ~CZDQHFtdcMdApi(){};
};

extern "C"
{
	CZDQHFtdcMdApi* CDECL CreateFtdcMdApi(const char *pszFlowPath = "");
}

#endif