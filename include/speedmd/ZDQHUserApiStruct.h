/////////////////////////////////////////////////////////////////////////
///@system ��һ��������ϵͳ
///@company  �д��ڻ�
///@file ZDQHUserApiStruct.h
///@brief �����˿ͻ��˽ӿ�ҵ�����ݽṹ
///@history 
///20130923	�쵩		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef ZDQHUSERAPISTRUCTH
#define ZDQHUSERAPISTRUCTH

#include "ZDQHUserApiType.h"

#if defined(ISLIB) && defined(WIN32)
#ifdef LIB_MD_API_EXPORT
#define API_EXPORT __declspec(dllexport)
#else
#define API_EXPORT __declspec(dllimport)
#endif
#else
#define API_EXPORT 
#endif

#if defined(ISLIB) && defined(WIN32)
#ifdef LIB_MD_API_EXPORT
#define CDECL    __cdecl
#else
#define CDECL __cdecl
#endif
#else
#define CDECL 
#endif

///�г� CZCE-֣��,DCE-����,SHFE-�Ϻ�,CFFEX-�н�
typedef char TZDQHExchangeType[9];

#pragma  pack(1)

struct CZDQHAddressField
{
    TZDQHIpType						Ip;     ///< ���׷�����IP��ַ
    TZDQHPortType					Port;   ///< ���׷������˿ں�
};

///�۲����鶩������
struct CZDQHFtdcReqBasisQuoteField
{
	///�������� 1 ���� 2�˶�
	TZDQHFtdcSubType  SubType;
	///��һ�Ⱥ�Լ�г�ID
	TZDQHFtdcExchangeIDType	ExchangeID1;
	///��һ�Ⱥ�Լ������Ƕ��Ļ���300ָ�������飬Ĭ��ȡ000300��ExchangeID1��Ϊ��
	TZDQHFtdcInstrumentIDType	InstrumentID1;
	///�ڶ��Ⱥ�Լ�г�ID
	TZDQHFtdcExchangeIDType	ExchangeID2;
	///�ڶ��Ⱥ�Լ
	TZDQHFtdcInstrumentIDType	InstrumentID2;
};

///�۲�����֪ͨ
struct CZDQHFtdcRspBasisQuoteField
{
	///��һ�Ⱥ�Լ�г�ID
	TZDQHFtdcExchangeIDType	ExchangeID1;
	///��һ�Ⱥ�Լ������Ƕ��Ļ���300ָ�������飬Ĭ��ȡ000300��ExchangeID1��Ϊ��
	TZDQHFtdcInstrumentIDType	InstrumentID1;
	///�ڶ��Ⱥ�Լ�г�ID
	TZDQHFtdcExchangeIDType	ExchangeID2;
	///�ڶ��Ⱥ�Լ
	TZDQHFtdcInstrumentIDType	InstrumentID2;
	///�۲� ����һ�Ⱥ�Լ - �ڶ��Ⱥ�Լ��
	TZDQHFtdcBasisQuoteType		BasisQuote;
};


///�û���¼����
struct CZDQHFtdcReqUserLoginField
{
	///������
	TZDQHFtdcDateType	TradingDay;
	///���͹�˾����
	TZDQHFtdcBrokerIDType	BrokerID;
	///�û�����
	TZDQHFtdcUserIDType	UserID;
	///����
	TZDQHFtdcPasswordType	Password;
	///�û��˲�Ʒ��Ϣ
	TZDQHFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TZDQHFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TZDQHFtdcProtocolInfoType	ProtocolInfo;
	///Mac��ַ
	TZDQHFtdcMacAddressType	MacAddress;
	///��̬����
	TZDQHFtdcPasswordType	OneTimePassword;
	///�ն�IP��ַ
	TZDQHFtdcIPAddressType	ClientIPAddress;
};

///�û���¼Ӧ��
struct CZDQHFtdcRspUserLoginField
{
	///������
	TZDQHFtdcDateType	TradingDay;
	///��¼�ɹ�ʱ��
	TZDQHFtdcTimeType	LoginTime;
	///���͹�˾����
	TZDQHFtdcBrokerIDType	BrokerID;
	///�û�����
	TZDQHFtdcUserIDType	UserID;
	///����ϵͳ����
	TZDQHFtdcSystemNameType	SystemName;
	///ǰ�ñ��
	TZDQHFtdcFrontIDType	FrontID;
	///�Ự���
	TZDQHFtdcSessionIDType	SessionID;
	///��󱨵�����
	TZDQHFtdcOrderRefType	MaxOrderRef;
	///������ʱ��
	TZDQHFtdcTimeType	SHFETime;
	///������ʱ��
	TZDQHFtdcTimeType	DCETime;
	///֣����ʱ��
	TZDQHFtdcTimeType	CZCETime;
	///�н���ʱ��
	TZDQHFtdcTimeType	FFEXTime;
};

///�û��ǳ�����
struct CZDQHFtdcUserLogoutField
{
	///���͹�˾����
	TZDQHFtdcBrokerIDType	BrokerID;
	///�û�����
	TZDQHFtdcUserIDType	UserID;
};

///ָ���ĺ�Լ
struct CZDQHFtdcSpecificInstrumentField
{
	///��Լ����
	TZDQHFtdcInstrumentIDType	InstrumentID;
};



///�������
struct CZDQHFtdcDepthQuoteDataField
{
	///������
	TZDQHFtdcDateType	TradingDay;
	///��Լ����
	TZDQHFtdcInstrumentIDType	InstrumentID;
	///����������
	TZDQHFtdcExchangeIDType	ExchangeID;
	///��Լ�ڽ������Ĵ���
	TZDQHFtdcExchangeInstIDType	ExchangeInstID;
	///���¼�
	TZDQHFtdcPriceType	LastPrice;
	///�ϴν����
	TZDQHFtdcPriceType	PreSettlementPrice;
	///������
	TZDQHFtdcPriceType	PreClosePrice;
	///��ֲ���
	TZDQHFtdcLargeVolumeType	PreOpenInterest;
	///����
	TZDQHFtdcPriceType	OpenPrice;
	///��߼�
	TZDQHFtdcPriceType	HighestPrice;
	///��ͼ�
	TZDQHFtdcPriceType	LowestPrice;
	///����
	TZDQHFtdcVolumeType	Volume;
	///�ɽ����
	TZDQHFtdcMoneyType	Turnover;
	///�ֲ���
	TZDQHFtdcLargeVolumeType	OpenInterest;
	///������
	TZDQHFtdcPriceType	ClosePrice;
	///���ν����
	TZDQHFtdcPriceType	SettlementPrice;
	///��ͣ���
	TZDQHFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TZDQHFtdcPriceType	LowerLimitPrice;
	///����ʵ��
	TZDQHFtdcRatioType	PreDelta;
	///����ʵ��
	TZDQHFtdcRatioType	CurrDelta;
	///����޸�ʱ��
	TZDQHFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TZDQHFtdcMillisecType	UpdateMillisec;
	///�����һ
	TZDQHFtdcPriceType	BidPrice1;
	///������һ
	TZDQHFtdcVolumeType	BidVolume1;
	///������һ
	TZDQHFtdcPriceType	AskPrice1;
	///������һ
	TZDQHFtdcVolumeType	AskVolume1;
	///����۶�
	TZDQHFtdcPriceType	BidPrice2;
	///��������
	TZDQHFtdcVolumeType	BidVolume2;
	///�����۶�
	TZDQHFtdcPriceType	AskPrice2;
	///��������
	TZDQHFtdcVolumeType	AskVolume2;
	///�������
	TZDQHFtdcPriceType	BidPrice3;
	///��������
	TZDQHFtdcVolumeType	BidVolume3;
	///��������
	TZDQHFtdcPriceType	AskPrice3;
	///��������
	TZDQHFtdcVolumeType	AskVolume3;
	///�������
	TZDQHFtdcPriceType	BidPrice4;
	///��������
	TZDQHFtdcVolumeType	BidVolume4;
	///��������
	TZDQHFtdcPriceType	AskPrice4;
	///��������
	TZDQHFtdcVolumeType	AskVolume4;
	///�������
	TZDQHFtdcPriceType	BidPrice5;
	///��������
	TZDQHFtdcVolumeType	BidVolume5;
	///��������
	TZDQHFtdcPriceType	AskPrice5;
	///��������
	TZDQHFtdcVolumeType	AskVolume5;
	///���վ���
	TZDQHFtdcPriceType	AveragePrice;
};

///��Ӧ��Ϣ
struct CZDQHFtdcRspInfoField
{
	///�������
	TZDQHFtdcErrorIDType	ErrorID;
	///������Ϣ
	TZDQHFtdcErrorMsgType	ErrorMsg;
};

///�ֻ�level2���鶩��
struct CZDQHStockLevel2Field
{
	///֤ȯ����
	TZDQHFtdcStockIDType	SecurityID;
	///����������    �Ϻ�"SSE"  ���� "SZE"
	TZDQHFtdcStockExchangeIDType	ExchangeID;
};

///Level2��Ʊ�������
struct CLevel2ZDQHFtdcLevel2MarketDataField
{
	///������
	TZDQHFtdcDateType	TradingDay;
	///ʱ���
	TZDQHFtdcTimeType	DataTimeStamp;
	///����������
	TZDQHFtdcExchangeIDType	ExchangeID;
	///֤ȯ����
	TZDQHFtdcStockIDType	SecurityID;
	///�����̼�
	TZDQHFtdcPriceType	PreClosePx;
	///���̼�
	TZDQHFtdcPriceType	OpenPx;
	///��߼�
	TZDQHFtdcPriceType	HighPx;
	///��ͼ�
	TZDQHFtdcPriceType	LowPx;
	///�ּ�
	TZDQHFtdcPriceType	LastPx;
	///���̼�
	TZDQHFtdcPriceType	ClosePx;
	///�ɽ�����
	TZDQHFtdcVolumeType	NumTrades;
	///�ɽ�����
	TZDQHFtdcLargeVolumeType	TotalVolumeTrade;
	///�ɽ��ܽ��
	TZDQHFtdcMoneyType	TotalValueTrade;
	///ί����������
	TZDQHFtdcLargeVolumeType	TotalBidQty;
	///��Ȩƽ��ί���
	TZDQHFtdcPriceType	WeightedAvgBidPx;
	///ծȯ��Ȩƽ��ί���
	TZDQHFtdcPriceType	AltWeightedAvgBidPx;
	///ί����������
	TZDQHFtdcLargeVolumeType	TotalOfferQty;
	///��Ȩƽ��ί����
	TZDQHFtdcPriceType	WeightedAvgOfferPx;
	///ծȯ��Ȩƽ��ί���۸�
	TZDQHFtdcPriceType	AltWeightedAvgOfferPx;
	///��ֵ��ֵ
	TZDQHFtdcPriceType	IOPV;
	///����������
	TZDQHFtdcRatioType	YieldToMaturity;
	///Ȩִ֤��������
	TZDQHFtdcLargeVolumeType	TotalWarrantExecQty;
	///Ȩ֤��ͣ�۸�
	TZDQHFtdcPriceType	WarLowerPx;
	///Ȩ֤��ͣ�۸�
	TZDQHFtdcPriceType	WarUpperPx;
	///������
	TZDQHFtdcPriceLevelType	BidPriceLevel;
	///�����һ
	TZDQHFtdcPriceType	BidPx1;
	///������һ
	TZDQHFtdcVolumeType	BidOrderQty1;
	///ʵ������ί�б���һ
	TZDQHFtdcVolumeType	BidNumOrder1;
	///����۶�
	TZDQHFtdcPriceType	BidPx2;
	///��������
	TZDQHFtdcVolumeType	BidOrderQty2;
	///ʵ������ί�б�����
	TZDQHFtdcVolumeType	BidNumOrder2;
	///�������
	TZDQHFtdcPriceType	BidPx3;
	///��������
	TZDQHFtdcVolumeType	BidOrderQty3;
	///ʵ������ί�б�����
	TZDQHFtdcVolumeType	BidNumOrder3;
	///�������
	TZDQHFtdcPriceType	BidPx4;
	///��������
	TZDQHFtdcVolumeType	BidOrderQty4;
	///ʵ������ί�б�����
	TZDQHFtdcVolumeType	BidNumOrder4;
	///�������
	TZDQHFtdcPriceType	BidPx5;
	///��������
	TZDQHFtdcVolumeType	BidOrderQty5;
	///ʵ������ί�б�����
	TZDQHFtdcVolumeType	BidNumOrder5;
	///�������
	TZDQHFtdcPriceType	BidPx6;
	///��������
	TZDQHFtdcVolumeType	BidOrderQty6;
	///ʵ������ί�б�����
	TZDQHFtdcVolumeType	BidNumOrder6;
	///�������
	TZDQHFtdcPriceType	BidPx7;
	///��������
	TZDQHFtdcVolumeType	BidOrderQty7;
	///ʵ������ί�б�����
	TZDQHFtdcVolumeType	BidNumOrder7;
	///����۰�
	TZDQHFtdcPriceType	BidPx8;
	///��������
	TZDQHFtdcVolumeType	BidOrderQty8;
	///ʵ������ί�б�����
	TZDQHFtdcVolumeType	BidNumOrder8;
	///����۾�
	TZDQHFtdcPriceType	BidPx9;
	///��������
	TZDQHFtdcVolumeType	BidOrderQty9;
	///ʵ������ί�б�����
	TZDQHFtdcVolumeType	BidNumOrder9;
	///�����ʮ
	TZDQHFtdcPriceType	BidPxA;
	///������ʮ
	TZDQHFtdcVolumeType	BidOrderQtyA;
	///ʵ������ί�б���ʮ
	TZDQHFtdcVolumeType	BidNumOrderA;
	///�������
	TZDQHFtdcPriceLevelType	OfferPriceLevel;
	///������һ
	TZDQHFtdcPriceType	OfferPx1;
	///������һ
	TZDQHFtdcVolumeType	OfferOrderQty1;
	///ʵ������ί�б���һ
	TZDQHFtdcVolumeType	OfferNumOrder1;
	///�����۶�
	TZDQHFtdcPriceType	OfferPx2;
	///��������
	TZDQHFtdcVolumeType	OfferOrderQty2;
	///ʵ������ί�б�����
	TZDQHFtdcVolumeType	OfferNumOrder2;
	///��������
	TZDQHFtdcPriceType	OfferPx3;
	///��������
	TZDQHFtdcVolumeType	OfferOrderQty3;
	///ʵ������ί�б�����
	TZDQHFtdcVolumeType	OfferNumOrder3;
	///��������
	TZDQHFtdcPriceType	OfferPx4;
	///��������
	TZDQHFtdcVolumeType	OfferOrderQty4;
	///ʵ������ί�б�����
	TZDQHFtdcVolumeType	OfferNumOrder4;
	///��������
	TZDQHFtdcPriceType	OfferPx5;
	///��������
	TZDQHFtdcVolumeType	OfferOrderQty5;
	///ʵ������ί�б�����
	TZDQHFtdcVolumeType	OfferNumOrder5;
	///��������
	TZDQHFtdcPriceType	OfferPx6;
	///��������
	TZDQHFtdcVolumeType	OfferOrderQty6;
	///ʵ������ί�б�����
	TZDQHFtdcVolumeType	OfferNumOrder6;
	///��������
	TZDQHFtdcPriceType	OfferPx7;
	///��������
	TZDQHFtdcVolumeType	OfferOrderQty7;
	///ʵ������ί�б�����
	TZDQHFtdcVolumeType	OfferNumOrder7;
	///�����۰�
	TZDQHFtdcPriceType	OfferPx8;
	///��������
	TZDQHFtdcVolumeType	OfferOrderQty8;
	///ʵ������ί�б�����
	TZDQHFtdcVolumeType	OfferNumOrder8;
	///�����۾�
	TZDQHFtdcPriceType	OfferPx9;
	///��������
	TZDQHFtdcVolumeType	OfferOrderQty9;
	///ʵ������ί�б�����
	TZDQHFtdcVolumeType	OfferNumOrder9;
	///������ʮ
	TZDQHFtdcPriceType	OfferPxA;
	///������ʮ
	TZDQHFtdcVolumeType	OfferOrderQtyA;
	///ʵ������ί�б���ʮ
	TZDQHFtdcVolumeType	OfferNumOrderA;
};


///Level2ָ������
struct CLevel2ZDQHFtdcNGTSIndexField
{
	///������
	TZDQHFtdcDateType	TradingDay;
	///����ʱ�䣨�룩
	TZDQHFtdcTimeType	TimeStamp;
	///����������
	TZDQHFtdcExchangeIDType	ExchangeID;
	///ָ������
	TZDQHFtdcStockIDType	SecurityID;
	///ǰ����ָ��
	TZDQHFtdcIndexType	PreCloseIndex;
	///����ָ��
	TZDQHFtdcIndexType	OpenIndex;
	///���������Ӧָ���ĳɽ���Ԫ��
	TZDQHFtdcMoneyType	TurnOver;
	///���ָ��
	TZDQHFtdcIndexType	HighIndex;
	///���ָ��
	TZDQHFtdcIndexType	LowIndex;
	///����ָ��
	TZDQHFtdcIndexType	LastIndex;
	///��������ָ��
	TZDQHFtdcIndexType	CloseIndex;
	///�ɽ�ʱ��
	TZDQHFtdcTimeType	TradeTime;
	///���������Ӧָ���Ľ����������֣�
	TZDQHFtdcLargeVolumeType	TotalVolumeTraded;
};

#pragma  pack()
#endif

