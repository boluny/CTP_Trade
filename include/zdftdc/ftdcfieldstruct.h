/////////////////////////////////////////////////////////////////////////
///@system ��һ�������̨ϵͳ
///@company �㽭�д��ڻ����޹�˾
///@file ftdcfieldstruct.h
///@brief �����˿ͻ��˽ӿ�ʹ�õ�ҵ�����ݽṹ
///@history 
///20141202	����	�������ļ�
/////////////////////////////////////////////////////////////////////////


#ifndef FTDC_FIELD_STRUCT_H
#define FTDC_FIELD_STRUCT_H

#include "ftdctypes.h"

//namespace ftdclib
//{
	///�û���¼����
	struct CFtdcReqUserLoginField
	{
		///������
		TFtdcDateType	TradingDay;
		///���͹�˾����
		TFtdcBrokerIDType	BrokerID;
		///�û�����
		TFtdcUserIDType	UserID;
		///����
		TFtdcPasswordType	Password;
		///�û��˲�Ʒ��Ϣ
		TFtdcProductInfoType	UserProductInfo;
		///�ӿڶ˲�Ʒ��Ϣ
		TFtdcProductInfoType	InterfaceProductInfo;
		///Э����Ϣ
		TFtdcProtocolInfoType	ProtocolInfo;
		///Mac��ַ
		TFtdcMacAddressType	MacAddress;
		///��̬����
		TFtdcPasswordType	OneTimePassword;
		///�ն�IP��ַ
		TFtdcIPAddressType	ClientIPAddress;
	};

	///�û���¼Ӧ��
	struct CFtdcRspUserLoginField
	{
		///������
		TFtdcDateType	TradingDay;
		///��¼�ɹ�ʱ��
		TFtdcTimeType	LoginTime;
		///���͹�˾����
		TFtdcBrokerIDType	BrokerID;
		///�û�����
		TFtdcUserIDType	 UserID;
		///����ϵͳ����
		TFtdcSystemNameType	SystemName;
		///ǰ�ñ��
		TFtdcFrontIDType	FrontID;
		///�Ự���
		TFtdcSessionIDType	SessionID;
		///��󱨵�����
		TFtdcOrderRefType	MaxOrderRef;
		///������ʱ��
		TFtdcTimeType	SHFETime;
		///������ʱ��
		TFtdcTimeType	DCETime;
		///֣����ʱ��
		TFtdcTimeType	CZCETime;
		///�н���ʱ��
		TFtdcTimeType	FFEXTime;
	};

	///�û��ǳ�����
	struct CFtdcUserLogoutField
	{
		///���͹�˾����
		TFtdcBrokerIDType	BrokerID;
		///�û�����
		TFtdcUserIDType	UserID;
	};


	///�ͻ�����֤����
	struct CFtdcReqAuthenticateField
	{
		///���͹�˾����
		TFtdcBrokerIDType	BrokerID;
		///�û�����
		TFtdcUserIDType	UserID;
		///�û��˲�Ʒ��Ϣ
		TFtdcProductInfoType	UserProductInfo;
		///��֤��
		TFtdcAuthCodeType	AuthCode;
	};

	///�ͻ�����֤��Ӧ
	struct CFtdcRspAuthenticateField
	{
		///���͹�˾����
		TFtdcBrokerIDType	BrokerID;
		///�û�����
		TFtdcUserIDType	UserID;
		///�û��˲�Ʒ��Ϣ
		TFtdcProductInfoType	UserProductInfo;
	};

	///�ͻ�����֤��Ϣ
	struct CFtdcAuthenticationInfoField
	{
		///���͹�˾����
		TFtdcBrokerIDType	BrokerID;
		///�û�����
		TFtdcUserIDType	UserID;
		///�û��˲�Ʒ��Ϣ
		TFtdcProductInfoType	UserProductInfo;
		///��֤��Ϣ
		TFtdcAuthInfoType	AuthInfo;
		///�Ƿ�Ϊ��֤���
		TFtdcBoolType	IsResult;
	};

	///��Ӧ��Ϣ
	struct CFtdcRspInfoField
	{
		///�������
		TFtdcErrorIDType	ErrorID;
		///������Ϣ
		TFtdcErrorMsgType	ErrorMsg;
	};

	///��Ʒ
	struct CFtdcProductField
	{
		///��Ʒ����
		TFtdcInstrumentIDType	ProductID;
		///��Ʒ����
		TFtdcProductNameType	ProductName;
		///����������
		TFtdcExchangeIDType	ExchangeID;
		///��Ʒ����
		TFtdcProductClassType	ProductClass;
		///��Լ��������
		TFtdcVolumeMultipleType	VolumeMultiple;
		///��С�䶯��λ
		TFtdcPriceType	PriceTick;
		///�м۵�����µ���
		TFtdcVolumeType	MaxMarketOrderVolume;
		///�м۵���С�µ���
		TFtdcVolumeType	MinMarketOrderVolume;
		///�޼۵�����µ���
		TFtdcVolumeType	MaxLimitOrderVolume;
		///�޼۵���С�µ���
		TFtdcVolumeType	MinLimitOrderVolume;
		///�ֲ�����
		TFtdcPositionTypeType	PositionType;
		///�ֲ���������
		TFtdcPositionDateTypeType	PositionDateType;
	};

	///��Լ
	struct CFtdcInstrumentField
	{
		///��Լ����
		TFtdcInstrumentIDType	InstrumentID;
		///����������
		TFtdcExchangeIDType	ExchangeID;
		///��Լ����
		TFtdcInstrumentNameType	InstrumentName;
		///��Լ�ڽ������Ĵ���
		TFtdcExchangeInstIDType	ExchangeInstID;
		///��Ʒ����
		TFtdcInstrumentIDType	ProductID;
		///��Ʒ����
		TFtdcProductClassType	ProductClass;
		///�������
		TFtdcYearType	DeliveryYear;
		///������
		TFtdcMonthType	DeliveryMonth;
		///�м۵�����µ���
		TFtdcVolumeType	MaxMarketOrderVolume;
		///�м۵���С�µ���
		TFtdcVolumeType	MinMarketOrderVolume;
		///�޼۵�����µ���
		TFtdcVolumeType	MaxLimitOrderVolume;
		///�޼۵���С�µ���
		TFtdcVolumeType	MinLimitOrderVolume;
		///��Լ��������
		TFtdcVolumeMultipleType	VolumeMultiple;
		///��С�䶯��λ
		TFtdcPriceType	PriceTick;
		///������
		TFtdcDateType	CreateDate;
		///������
		TFtdcDateType	OpenDate;
		///������
		TFtdcDateType	ExpireDate;
		///��ʼ������
		TFtdcDateType	StartDelivDate;
		///����������
		TFtdcDateType	EndDelivDate;
		///��Լ��������״̬
		TFtdcInstLifePhaseType	InstLifePhase;
		///��ǰ�Ƿ���
		TFtdcBoolType	IsTrading;
		///�ֲ�����
		TFtdcPositionTypeType	PositionType;
		///�ֲ���������
		TFtdcPositionDateTypeType	PositionDateType;
		///��ͷ��֤����
		TFtdcRatioType	LongMarginRatio;
		///��ͷ��֤����
		TFtdcRatioType	ShortMarginRatio;
	};


	///�������³ɽ�����
	struct CFtdcMarketDataLastMatchField
	{
		///���¼�
		TFtdcPriceType	LastPrice;
		///����
		TFtdcVolumeType	Volume;
		///�ɽ����
		TFtdcMoneyType	Turnover;
		///�ֲ���
		TFtdcLargeVolumeType	OpenInterest;
	};

	///�������ʱ������
	struct CFtdcMarketDataUpdateTimeField
	{
		///��Լ����
		TFtdcInstrumentIDType	InstrumentID;
		///����޸�ʱ��
		TFtdcTimeType	UpdateTime;
		///����޸ĺ���
		TFtdcMillisecType	UpdateMillisec;
	};

	///ָ���ĺ�Լ
	struct CFtdcSpecificInstrumentField
	{
		///��Լ����
		TFtdcInstrumentIDType	InstrumentID;
	};

	///������ӣ��߲�ѯ��ṹ��

	//��ʷtick
	struct CFtdcReqQryHisTickField
	{
		///��Լ����
		TFtdcInstrumentIDType	InstrumentID;
		///���β�ѯʱ��
		TFtdcStartQryTimeType LastQryTime;
		///��ѯ����
		TFtdcQryNumType QryNum;
	};

	struct CFtdcRspQryHisTickField 
	{
		///��Լ����
		TFtdcInstrumentIDType	InstrumentID;
	};

	struct CFtdcHisTickField
	{
		///������
		TFtdcDateType	TradingDay;
		///��Լ����
		TFtdcInstrumentIDType	InstrumentID;
		///����������
		TFtdcExchangeIDType	ExchangeID;
		///���¼�
		TFtdcPriceType	LastPrice;
		///�ϴν����
		TFtdcPriceType	PreSettlementPrice;
		///������
		TFtdcPriceType	PreClosePrice;
		///��ֲ���
		TFtdcLargeVolumeType	PreOpenInterest;
		///����
		TFtdcPriceType	OpenPrice;
		///��߼�
		TFtdcPriceType	HighestPrice;
		///��ͼ�
		TFtdcPriceType	LowestPrice;
		///����
		TFtdcVolumeType	Volume;
		///�ɽ����
		TFtdcMoneyType	Turnover;
		///�ֲ���
		TFtdcVolumeType businessAmount;
		///������
		TFtdcPriceType	ClosePrice;
		///���ν����
		TFtdcPriceType	SettlementPrice;
		///��ͣ���
		TFtdcPriceType	UpperLimitPrice;
		///��ͣ���
		TFtdcPriceType	LowerLimitPrice;
		///����޸�ʱ��
		TFtdcTimeType	UpdateTime;
		///����޸ĺ���
		TFtdcMillisecType	UpdateMillisec;
		///�����һ
		TFtdcPriceType	BidPrice1;
		///������һ
		TFtdcVolumeType	BidVolume1;
		///������һ
		TFtdcPriceType	AskPrice1;
		///������һ
		TFtdcVolumeType	AskVolume1;
		///����۶�
		TFtdcPriceType	BidPrice2;
		///��������
		TFtdcVolumeType	BidVolume2;
		///�����۶�
		TFtdcPriceType	AskPrice2;
		///��������
		TFtdcVolumeType	AskVolume2;
		///�������
		TFtdcPriceType	BidPrice3;
		///��������
		TFtdcVolumeType	BidVolume3;
		///��������
		TFtdcPriceType	AskPrice3;
		///��������
		TFtdcVolumeType	AskVolume3;
		///�������
		TFtdcPriceType	BidPrice4;
		///��������
		TFtdcVolumeType	BidVolume4;
		///��������
		TFtdcPriceType	AskPrice4;
		///��������
		TFtdcVolumeType	AskVolume4;
		///�������
		TFtdcPriceType	BidPrice5;
		///��������
		TFtdcVolumeType	BidVolume5;
		///��������
		TFtdcPriceType	AskPrice5;
		///��������
		TFtdcVolumeType	AskVolume5;
	};

	struct CFtdcReqQryKLineDayField 
	{
		///��Լ����
		TFtdcInstrumentIDType	InstrumentID;
		///������
		TFtdcStartQryTimeType TradingDay;
		///��ѯ����
		TFtdcQryNumType QryNum;
	};
	
	struct CFtdcRspQryKLineDayField 
	{
		///��Լ����
		TFtdcInstrumentIDType	InstrumentID;
	};

	struct CFtdcKLineDayField 
	{
		///������
		TFtdcDateType	TradingDay;
		///��Լ����
		TFtdcInstrumentIDType	InstrumentID;
		///����������
		TFtdcExchangeIDType	ExchangeID;
		///���¼�
		TFtdcPriceType	LastPrice;
		///�ϴν����
		TFtdcPriceType	PreSettlementPrice;
		///������
		TFtdcPriceType	PreClosePrice;
		///����
		TFtdcPriceType	OpenPrice;
		///��߼�
		TFtdcPriceType	HighestPrice;
		///��ͼ�
		TFtdcPriceType	LowestPrice;
		///����
		TFtdcVolumeType Volume;
		///�ɽ����
		TFtdcMoneyType	Turnover;
		///�ֲ���
		TFtdcVolumeType businessAmount;
		///������
		TFtdcPriceType	ClosePrice;
		///���ν����
		TFtdcPriceType	SettlementPrice;
		///��ͣ���
		TFtdcPriceType	UpperLimitPrice;
		///��ͣ���
		TFtdcPriceType	LowerLimitPrice;
		///����޸�ʱ��
		//TFtdcTimeType	UpdateTime;
		///����޸ĺ���
		//TFtdcMillisecType	UpdateMillisec;
	};

	struct CFtdcReqQryKLine1MinuteField
	{
		///��Լ����
		TFtdcInstrumentIDType	InstrumentID;
		///�ϴβ�ѯʱ��
		TFtdcStartQryTimeType StartQryKLine1MinuteTime;
		///��ѯ����
		TFtdcQryNumType QryNum;
	};

	struct CFtdcRspQryKLine1MinuteField 
	{
		///��Լ����
		TFtdcInstrumentIDType	InstrumentID;
	};

	struct CFtdcKLine1MinuteField
	{
		///������
		TFtdcDateType	TradingDay;
		///��Լ����
		TFtdcInstrumentIDType	InstrumentID;
		///����������
		TFtdcExchangeIDType	ExchangeID;
		///���¼�
		TFtdcPriceType	LastPrice;
		///�ϴν����
		TFtdcPriceType	PreSettlementPrice;
		///������
		TFtdcPriceType	PreClosePrice;
		///����
		TFtdcPriceType	OpenPrice;
		///��߼�
		TFtdcPriceType	HighestPrice;
		///��ͼ�
		TFtdcPriceType	LowestPrice;
		///����
		TFtdcVolumeType Volume;
		///�ɽ����
		TFtdcMoneyType	Turnover;
		///�ֲ���
		TFtdcVolumeType businessAmount;
		///������
		TFtdcPriceType	ClosePrice;
		///���ν����
		TFtdcPriceType	SettlementPrice;
		///��ͣ���
		TFtdcPriceType	UpperLimitPrice;
		///��ͣ���
		TFtdcPriceType	LowerLimitPrice;
		///����޸�ʱ��
		TFtdcTimeType	UpdateTime;
		///����޸ĺ���
		//TFtdcMillisecType	UpdateMillisec;
	};

//}//end namespace
	////��Ҫ���ֽṹ��
	///�������
#ifdef VERSION2
	struct CFtdcDepthMarketDataField
	{
		//char test[2];
		///����޸�ʱ��
		///����޸�ʱ��
		TFtdcTimeType	UpdateTime;
		///����޸ĺ���
		TFtdcMillisecType UpdateMillisec;


	};
#else
	struct CFtdcDepthMarketDataField //LEVEL_5
	{
		///������
		TFtdcDateType	TradingDay;
		///��Լ����
		TFtdcInstrumentIDType	InstrumentID;
		///����������
		TFtdcExchangeIDType	ExchangeID;
		///��Լ�ڽ������Ĵ���
		TFtdcExchangeInstIDType	ExchangeInstID;
		///���¼�
		TFtdcPriceType	LastPrice;
		///�ϴν����
		TFtdcPriceType	PreSettlementPrice;
		///������
		TFtdcPriceType	PreClosePrice;
		///��ֲ���
		TFtdcLargeVolumeType	PreOpenInterest;
		///����
		TFtdcPriceType	OpenPrice;
		///��߼�
		TFtdcPriceType	HighestPrice;
		///��ͼ�
		TFtdcPriceType	LowestPrice;
		///����
		TFtdcVolumeType	Volume;
		///�ɽ����
		TFtdcMoneyType	Turnover;
		///�ֲ���
		//TFtdcVolumeType businessAmount;
		TFtdcLargeVolumeType	OpenInterest; //yangpeng
		///������
		TFtdcPriceType	ClosePrice;
		///���ν����
		TFtdcPriceType	SettlementPrice;
		///��ͣ���
		TFtdcPriceType	UpperLimitPrice;
		///��ͣ���
		TFtdcPriceType	LowerLimitPrice;
		///����ʵ��
		TFtdcRatioType	PreDelta;
		///����ʵ��
		TFtdcRatioType	CurrDelta;
		///����޸�ʱ��
		TFtdcTimeType	UpdateTime;
		///����޸ĺ���
		TFtdcMillisecType	UpdateMillisec;
		///�����һ
		TFtdcPriceType	BidPrice1;
		///������һ
		TFtdcVolumeType	BidVolume1;
		///������һ
		TFtdcPriceType	AskPrice1;
		///������һ
		TFtdcVolumeType	AskVolume1;
		///����۶�
		TFtdcPriceType	BidPrice2;
		///��������
		TFtdcVolumeType	BidVolume2;
		///�����۶�
		TFtdcPriceType	AskPrice2;
		///��������
		TFtdcVolumeType	AskVolume2;
		///�������
		TFtdcPriceType	BidPrice3;
		///��������
		TFtdcVolumeType	BidVolume3;
		///��������
		TFtdcPriceType	AskPrice3;
		///��������
		TFtdcVolumeType	AskVolume3;
		///�������
		TFtdcPriceType	BidPrice4;
		///��������
		TFtdcVolumeType	BidVolume4;
		///��������
		TFtdcPriceType	AskPrice4;
		///��������
		TFtdcVolumeType	AskVolume4;
		///�������
		TFtdcPriceType	BidPrice5;
		///��������
		TFtdcVolumeType	BidVolume5;
		///��������
		TFtdcPriceType	AskPrice5;
		///��������
		TFtdcVolumeType	AskVolume5;
		///���վ���
		TFtdcPriceType	AveragePrice;
	};
#endif

struct CFtdcMarketDataField  //LEVEL_1
	{
		///������
		TFtdcDateType	TradingDay;
		///��Լ����
		TFtdcInstrumentIDType	InstrumentID;
		///����������
		TFtdcExchangeIDType	ExchangeID;
		///��Լ�ڽ������Ĵ���
		TFtdcExchangeInstIDType	ExchangeInstID;
		///���¼�
		TFtdcPriceType	LastPrice;
		///�ϴν����
		TFtdcPriceType	PreSettlementPrice;
		///������
		TFtdcPriceType	PreClosePrice;
		///��ֲ���
		TFtdcLargeVolumeType	PreOpenInterest;
		///����
		TFtdcPriceType	OpenPrice;
		///��߼�
		TFtdcPriceType	HighestPrice;
		///��ͼ�
		TFtdcPriceType	LowestPrice;
		///����
		TFtdcVolumeType	Volume;
		///�ɽ����
		TFtdcMoneyType	Turnover;
		///�ֲ���
		//TFtdcVolumeType businessAmount;
		TFtdcLargeVolumeType	OpenInterest; //yangpeng
		///������
		TFtdcPriceType	ClosePrice;
		///���ν����
		TFtdcPriceType	SettlementPrice;
		///��ͣ���
		TFtdcPriceType	UpperLimitPrice;
		///��ͣ���
		TFtdcPriceType	LowerLimitPrice;
		///����ʵ��
		TFtdcRatioType	PreDelta;
		///����ʵ��
		TFtdcRatioType	CurrDelta;
		///����޸�ʱ��
		TFtdcTimeType	UpdateTime;
		///����޸ĺ���
		TFtdcMillisecType	UpdateMillisec;
		///�����һ
		TFtdcPriceType	BidPrice1;
		///������һ
		TFtdcVolumeType	BidVolume1;
		///������һ
		TFtdcPriceType	AskPrice1;
		///������һ
		TFtdcVolumeType	AskVolume1;
	};

struct CFTDMarketDataUpdateTimeField
	{
		///\u5408\u7ea6\u4ee3\u7801
		TFtdcInstrumentIDType	InstrumentID;
		///\u6700\u540e\u4fee\u6539\u65f6\u95f4
		TFtdcTimeType	UpdateTime;
		///\u6700\u540e\u4fee\u6539\u6beb\u79d2
		TFtdcMillisecType	UpdateMillisec;
	};
struct CFTDMarketDataStaticField
	{
     	///\u4eca\u5f00\u76d8
		TFtdcPriceType	OpenPrice;
		///\u6700\u9ad8\u4ef7
		TFtdcPriceType	HighestPrice;
		///\u6700\u4f4e\u4ef7
		TFtdcPriceType	LowestPrice;
		///\u4eca\u6536\u76d8
		TFtdcPriceType	ClosePrice;
		///\u6da8\u505c\u677f\u4ef7
		TFtdcPriceType	UpperLimitPrice;
		///\u8dcc\u505c\u677f\u4ef7
		TFtdcPriceType	LowerLimitPrice;
        ///\u672c\u6b21\u7ed3\u7b97\u4ef7
		TFtdcPriceType	SettlementPrice;
	};
#if 1
struct CFTDMarketDataLastMatchField
	{
      	///\u6700\u65b0\u4ef7
		TFtdcPriceType	LastPrice;
		///\u6570\u91cf
		TFtdcVolumeType	Volume;
		///\u6210\u4ea4\u91d1\u989d
		TFtdcMoneyType	Turnover;
		///\u6301\u4ed3\u91cf
		TFtdcLargeVolumeType	OpenInterest;
	};
#endif

#if 0
struct CFTDMarketDataBestPriceField
	{
     	///\u7533\u4e70\u4ef7\u4e00
		TFtdcPriceType	BidPrice1;
		///\u7533\u4e70\u91cf\u4e00
		TFtdcVolumeType	BidVolume1;
		///\u7533\u5356\u4ef7\u4e00
		TFtdcPriceType	AskPrice1;
		///\u7533\u5356\u91cf\u4e00
		TFtdcVolumeType	AskVolume1;

	};
#endif

struct CFTDMarketDataBestPriceField   //�ֽڶ��� yanpeng
{	
	///\u7533\u4e70\u91cf\u4e00
	TFtdcVolumeType	BidVolume1;
	///\u7533\u5356\u91cf\u4e00
	TFtdcVolumeType	AskVolume1;	
	///\u7533\u4e70\u4ef7\u4e00
	TFtdcPriceType	BidPrice1;
	///\u7533\u5356\u4ef7\u4e00
	TFtdcPriceType	AskPrice1;
};
struct CFTDMarketDataPreStaticField
	{
        ///\u4ea4\u6613\u65e5
		TFtdcDateType	TradingDay;
		///\u4e0a\u6b21\u7ed3\u7b97\u4ef7
		TFtdcPriceType	PreSettlementPrice;
		///\u6628\u6536\u76d8
		TFtdcPriceType	PreClosePrice;
		///\u6628\u6301\u4ed3\u91cf
		TFtdcLargeVolumeType	PreOpenInterest;
	};

#if 0
struct CFTDMarketData5BestPriceField
	{
		///\u7533\u4e70\u4ef7\u4e00
		TFtdcPriceType	BidPrice1;
		///\u7533\u4e70\u91cf\u4e00
		TFtdcVolumeType	BidVolume1;
		///\u7533\u5356\u4ef7\u4e00
		TFtdcPriceType	AskPrice1;
		///\u7533\u5356\u91cf\u4e00
		TFtdcVolumeType	AskVolume1;
		///\u7533\u4e70\u4ef7\u4e8c
		TFtdcPriceType	BidPrice2;
		///\u7533\u4e70\u91cf\u4e8c
		TFtdcVolumeType	BidVolume2;
		///\u7533\u5356\u4ef7\u4e8c
		TFtdcPriceType	AskPrice2;
		///\u7533\u5356\u91cf\u4e8c
		TFtdcVolumeType	AskVolume2;
		///\u7533\u4e70\u4ef7\u4e09
		TFtdcPriceType	BidPrice3;
		///\u7533\u4e70\u91cf\u4e09
		TFtdcVolumeType	BidVolume3;
		///\u7533\u5356\u4ef7\u4e09
		TFtdcPriceType	AskPrice3;
		///\u7533\u5356\u91cf\u4e09
		TFtdcVolumeType	AskVolume3;
		///\u7533\u4e70\u4ef7\u56db
		///�������
		TFtdcPriceType	BidPrice4;
		///��������
		TFtdcVolumeType	BidVolume4;
		///��������
		TFtdcPriceType	AskPrice4;
		///��������
		TFtdcVolumeType	AskVolume4;
		///�������
		TFtdcPriceType	BidPrice5;
		///��������
		TFtdcVolumeType	BidVolume5;
		///��������
		TFtdcPriceType	AskPrice5;
		///��������
		TFtdcVolumeType AskVolume5;
};
#endif
#if 1
struct CFTDMarketData5BestPriceField  //�ֽڶ��� yanpeng
{
	TFtdcVolumeType	BidVolume1;	
	TFtdcVolumeType	AskVolume1;	
	TFtdcVolumeType	BidVolume2;	
	TFtdcVolumeType	AskVolume2;
	TFtdcVolumeType	BidVolume3;
	TFtdcVolumeType	AskVolume3;
	///��������
	TFtdcVolumeType	BidVolume4;
	///��������
	TFtdcVolumeType	AskVolume4;
	///��������
	TFtdcVolumeType	BidVolume5;
	///��������
	TFtdcVolumeType AskVolume5;

	TFtdcPriceType	BidPrice1;
	TFtdcPriceType	AskPrice1;
	TFtdcPriceType	BidPrice2;
	TFtdcPriceType	AskPrice2;
	TFtdcPriceType	BidPrice3;
	TFtdcPriceType	AskPrice3;
	TFtdcPriceType	BidPrice4;
	TFtdcPriceType	AskPrice4;
	TFtdcPriceType	BidPrice5;
	TFtdcPriceType	AskPrice5;
};
#endif

#endif