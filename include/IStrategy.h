#ifndef ISTRATEGYH
#define ISTRATEGYH
#include "IFactor.h"
#include "IFunction.h"
#include "QuantStruct.h"

class IStrategy;
typedef void (*OnZDQHOrderRsp)(CQuantOrderField*, IStrategy* pStrategy);
typedef void (*OnZDQHTradeRsp)(CQuantTradeField*, IStrategy* pStrategy);
typedef void (*OnZDQHMarkerDataRsp)(CQuantDepthQuoteDataField*, IStrategy* pStrategy);
typedef void (*OnZDQHErrInfoRsp)(void*, IStrategy* pStrategy);

class IStrategy
{
public:
	virtual void Release() = 0;

	//����
	virtual unsigned long ReqOrderInsert(const char* pIntrument,double dLimitPrice, int nOrderNum, TQuantBSDirection bs, TQuantOpenFlag of,TQuantHedgeType ht, TQuantPriceOrderType ordertype, TQuantTimeConditionType tcType) = 0;

	//����
	virtual unsigned long ReqOrderDelete(unsigned long ulOrderID) = 0;

	//��ȡ�����ʽ���Ϣ
	virtual CQuantInvestorAccountField* GetAccountFund() = 0;

	//��ȡ���Գֲ���Ϣ
	virtual void GetAccountPosition(CQuantPositionField** ppPosition, int& nCount) = 0;

	//��ȡ��ʷtick����
	virtual long GetMarketData(const char* lpInstrument,CQuantDepthQuoteDataField** ppMarketData, long lDataNum) = 0;

	//��ȡ��ʷk������
	virtual long GetKLineData(const char* lpInstrument,CQuantKLineDataField** ppMarketData, long lDataNum, TQuantDataPeriod period) = 0;

	//��ȡ��Լ��Ϣ
	virtual CQuantInstrumentField* GetInstrument(const char* pInstrumentUD) = 0;

	//ע�ᱨ���ر�
	virtual void RegOrderRsp(OnZDQHOrderRsp fOrderRsp) = 0;

	//ע��ɽ��ر�
	virtual void RegTradeRsp(OnZDQHTradeRsp fTradeRsp) = 0;

	//ע���ڻ�����֪ͨ
	virtual void RegMarketDataRsp(OnZDQHMarkerDataRsp fMarketDataRsp) = 0;	

	//��ȡ������ӿ�
	virtual IFunction* GetFunction() = 0;

	//��ȡ���ӿ�ӿ�
	virtual IFactor* GetFactor() = 0;
};

extern "C"
{
	void _cdecl InitQuant();
	IStrategy* _cdecl CreateStrategy(const char* pStrategyName);
};


#endif