#ifndef DEFINEH
#define  DEFINEH


#if defined(ISLIB) && defined(WIN32)
#ifdef LIB_API_EXPORT
#define API_EXPORT __declspec(dllexport)
#else
#define API_EXPORT __declspec(dllimport)
#endif
#else
#define API_EXPORT 
#endif

//////////////////////////////////////////////////////////////////////////
//��������
typedef char TQuantBSDirection;
#define QUANT_D_Buy     '0'
#define QUANT_D_Sell     '1'
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//��ƽ����
typedef char TQuantOpenFlag;
///����
#define QUANT_OF_Open '0'
///ƽ��
#define QUANT_OF_Close '1'
///ǿƽ
#define QUANT_OF_ForceClose '2'
///ƽ��
#define QUANT_OF_CloseToday '3'
///ƽ��
#define QUANT_OF_CloseYesterday '4'
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
//�ױ�
typedef char TQuantHedgeType;
///Ͷ��
#define QUANT_HT_Speculation '1'
///����
#define QUANT_HT_Arbitrage '2'
///�ױ�
#define QUANT_HT_Hedge '3'

/////////////////////////////////////////////////////////////////////////
///��Ч����������
typedef char TQuantTimeConditionType;
///������ɣ�������
#define QUANT_TC_IOC '1'
///������Ч
#define QUANT_TC_GFS '2'
///������Ч
#define QUANT_TC_GFD '3'
///ָ������ǰ��Ч
#define QUANT_TC_GTD '4'
///����ǰ��Ч
#define QUANT_TC_GTC '5'
///���Ͼ�����Ч
#define QUANT_TC_GFA '6'

/////////////////////////////////////////////////////////////////////////
///�������
typedef char TQuantPriceOrderType;
///�����
#define QUANT_OPT_AnyPrice '1'
///�޼�
#define QUANT_OPT_LimitPrice '2'

//////////////////////////////////////////////////////////////////////////
//����״̬
typedef char TQuantOrderStatusType;
///ȫ���ɽ�
#define QUANT_OST_AllTraded '0'
///���ֳɽ����ڶ�����
#define QUANT_OST_PartTradedQueueing '1'
///���ֳɽ����ڶ�����
#define QUANT_OST_PartTradedNotQueueing '2'
///δ�ɽ����ڶ�����
#define QUANT_OST_NoTradeQueueing '3'
///δ�ɽ����ڶ�����
#define QUANT_OST_NoTradeNotQueueing '4'
///����
#define QUANT_OST_Canceled '5'


//////////////////////////////////////////////////////////////////////////
///�����б�
typedef char TQuantActionType;
//����
#define QUANT_AT_INSERT  '1'
//����
#define QUANT_AT_DELETE  '2'

//////////////////////////////////////////////////////////////////////////
///k������
typedef char TQuantDataPeriod;
//����
#define QUANT_DATA_DAY   '1'
//60����
#define QUANT_DATA_HOUR  '2'
//30����
#define QUANT_DATA_30MIN  '3'
//15����
#define QUANT_DATA_15MIN  '4'
//1����
#define QUANT_DATA_1MIN  '5'
//tick
#define QUANT_DATA_TICK   '6'

///�������
struct CQuantDepthQuoteDataField
{
	///������
	char	TradingDay[9];
	///��Լ����
	char	InstrumentID[31];
	///����������
	char	ExchangeID[9];
	///��Լ�ڽ������Ĵ���
	char	ExchangeInstID[9];
	///���¼�
	double 	LastPrice;
	///�ϴν����
	double	PreSettlementPrice;
	///������
	double	PreClosePrice;
	///��ֲ���
	double	PreOpenInterest;
	///����
	double	OpenPrice;
	///��߼�
	double	HighestPrice;
	///��ͼ�
	double	LowestPrice;
	///����
	int 	Volume;
	///�ɽ����
	double	Turnover;
	///�ֲ���
	double	OpenInterest;
	///������
	double	ClosePrice;
	///���ν����
	double	SettlementPrice;
	///��ͣ���
	double	UpperLimitPrice;
	///��ͣ���
	double	LowerLimitPrice;
	///����ʵ��
	double	PreDelta;
	///����ʵ��
	double	CurrDelta;
	///����޸�ʱ��
	char	UpdateTime[9];
	///����޸ĺ���
	int 	UpdateMillisec;
	///�����һ
	double	BidPrice1;
	///������һ
	int 	BidVolume1;
	///������һ
	double	AskPrice1;
	///������һ
	int 	AskVolume1;
	///����۶�
	double	BidPrice2;
	///��������
	int 	BidVolume2;
	///�����۶�
	double	AskPrice2;
	///��������
	int 	AskVolume2;
	///�������
	double	BidPrice3;
	///��������
	int 	BidVolume3;
	///��������
	double	AskPrice3;
	///��������
	int 	AskVolume3;
	///�������
	double	BidPrice4;
	///��������
	int 	BidVolume4;
	///��������
	double	AskPrice4;
	///��������
	int 	AskVolume4;
	///�������
	double	BidPrice5;
	///��������
	int 	BidVolume5;
	///��������
	double	AskPrice5;
	///��������
	int 	AskVolume5;
	///���վ���
	double	AveragePrice;
};

struct CQuantKLineDataField 
{
	//����
    TQuantDataPeriod  KLinePeriod;
	///������
	char	TradingDay[9];
	//ʱ��
	char    TradingTime[9];  
	///��Լ����
	char	InstrumentID[31];
	///���¼�
	double	LastPrice;
	///�ϴν����
	double	PreSettlementPrice;
	///������
	double	PreClosePrice;
	///����
	double	OpenPrice;
	///��߼�
	double	HighestPrice;
	///��ͼ�
	double	LowestPrice;
	///����
	int Volume;
	///�ɽ����
	double	Turnover;
	///�ֲ���
	int businessAmount;
	///������
	double	ClosePrice;
	///���ν����
	double	SettlementPrice;
	///��ͣ���
	double	UpperLimitPrice;
	///��ͣ���
	double	LowerLimitPrice;
};

//����
struct CQuantOrderField
{
	///���͹�˾����
	char	BrokerID[11];
	///Ͷ���ߴ���
	char	InvestorID[13];
	///�ͻ�����
	char    UserID[20];	
	///��Լ����
	char	InstrumentID[31];
	///��������
	unsigned long	OrderRef;
	///��������
	TQuantBSDirection	Direction;
	///��ƽ��־
	TQuantOpenFlag	    OffsetFlag;
	///Ͷ���ױ���־
	TQuantHedgeType	    HedgeFlag;
	///�۸�
	double          	LimitPrice;
	///����
	int	                VolumeTotalOriginal;
	///ֹ���
	double           	StopPrice;
	///������
	char				TradingDay[9];
	///�������
	char				OrderSysID[21];
	//����״̬
	TQuantOrderStatusType	OrderStatus;
	///��ɽ�����
	int					VolumeTraded;
	///��������
	char				InsertDate[9];
	///ί��ʱ��
	char				InsertTime[9];
	///����޸�ʱ��
	char				UpdateTime[9];
	///����ʱ��
	char				CancelTime[9];
	///�������
	TQuantActionType    ActionType;                
	///�����
    int					ErrorID;
	///״̬��Ϣ
	char				StatusMsg[81];
};

///�ɽ�
struct CQuantTradeField
{
	///���͹�˾����
	char		BrokerID[11];
	///Ͷ���ߴ���
	char	InvestorID[13];
	///��Լ����
	char	InstrumentID[31];
	///��������
	unsigned long	OrderRef;
	///�û�����
	char	UserID[20];
	///�ɽ����
	char	TradeID[21];
	///��������
	TQuantBSDirection	Direction;
	///��ƽ��־
	TQuantOpenFlag	    OffsetFlag;
	///Ͷ���ױ���־
	TQuantHedgeType	    HedgeFlag;
	///�������
	char				OrderSysID[21];
	///�۸�
	double	Price;
	///����
	int	Volume;
	///�ɽ�ʱ��
	char	TradeDate[9];
	///�ɽ�ʱ��
	char	TradeTime[9];
	///������
	char	TradingDay[9];
	///������
	int	SettlementID;
};

///Ͷ�����ʽ�
struct CQuantInvestorAccountField
{
	///���͹�˾����
	char		BrokerID[11];
	///Ͷ���ߴ���
	char	InvestorID[13];
	///�ʽ��ʺ�
	char	AccountID[20];
	///�ϴν���׼����
	double	PreBalance;
	///�����
	double	Deposit;
	///������
	double	Withdraw;
	///����ı�֤��
	double	FrozenMargin;
	///����������
	double	FrozenFee;
	///����Ȩ����
	double	FrozenPremium;
	//������
	double Fee;
	///ƽ��ӯ��
	double	CloseProfit;
	///�ֲ�ӯ��
	double	PositionProfit;
	///�����ʽ�
	double	Available;
	///��ͷ����ı�֤��
	double	LongFrozenMargin;
	///��ͷ����ı�֤��
	double	ShortFrozenMargin;
	///��ͷռ�ñ�֤��
	double	LongMargin;
	///��ͷռ�ñ�֤��
	double	ShortMargin;
	///�����ͷű�֤��
	double	ReleaseMargin;
	///��̬Ȩ��
	double	DynamicRights;
	///���ճ����
	double	TodayInOut;
	///ռ�ñ�֤��
	double	Margin;
	///��ȨȨ������֧
	double	Premium;
	///���ն�
	double	Risk;
};
//�ֲ�
struct CQuantPositionField
{
	///���͹�˾����
	char		BrokerID[11];
	///Ͷ���ߴ���
	char	InvestorID[13];
	///��Լ����
	char	InstrumentID[31];
	///�û�����
	char	UserID[20];
	///��������
	TQuantBSDirection	Direction;
	///Ͷ���ױ���־
	TQuantHedgeType	HedgeFlag;
	///ռ�ñ�֤��
	double	UsedMargin;
	///��ֲ���
	int	Position;
	///���ճֲֳɱ�
	double	PositionCost;
	//�ֲ־���
	double AvePrice;
	///��ֲ���
	int	YdPosition;
	///���ճֲֳɱ�
	double	YdPositionCost;
	///����ı�֤��
	double	FrozenMargin;
	///���ֶ���ֲ�
	int	FrozenPosition;
	///ƽ�ֶ���ֲ�
	int	FrozenClosing;
	///�����Ȩ����
	double	FrozenPremium;
};

//����
struct CQuantFeeField
{
	//Ͷ����
	char	InvestorID[13];
	///��Լ����
	char	InstrumentID[31];
	///�û�����
	char	UserID[20];
	///���������Ѱ�����
	double	OpenFeeRate;
	///���������Ѱ�����
	double	OpenFeeAmt;
	///ƽ�������Ѱ�����
	double	OffsetFeeRate;
	///ƽ�������Ѱ�����
	double	OffsetFeeAmt;
	///ƽ��������Ѱ�����
	double	OTFeeRate;
	///ƽ��������Ѱ�����
	double	OTFeeAmt;
};

//��֤��
struct CQuantMarginField
{
	///��Լ����
	char	InstrumentID[31];
	///�û�����
	char	UserID[20];
	///��ͷռ�ñ�֤�𰴱���
	double	LongMarginRate;
	///��ͷ��֤������
	double	LongMarginAmt;
	///��ͷռ�ñ�֤�𰴱���
	double	ShortMarginRate;
	///��ͷ��֤������
	double	ShortMarginAmt;
};
//��Լ
struct CQuantInstrumentField
{
	///����������
	char	ExchangeID[11];
	///Ʒ������
	char	ProductName[41];
	///��Լ����
	char	InstrumentID[31];
	///��Լ����
	char	InstrumentName[21];
	///�������
	int	DeliveryYear;
	///������
	int	DeliveryMonth;
	///�޼۵�����µ���
	int	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	int	MinLimitOrderVolume;
	///�м۵�����µ���
	int	MaxMarketOrderVolume;
	///�м۵���С�µ���
	int	MinMarketOrderVolume;
	///��������
	int	VolumeMultiple;
	///���۵�λ
	double	PriceTick;
	///����
	char	Currency;
	///��ͷ�޲�
	int	LongPosLimit;
	///��ͷ�޲�
	int	ShortPosLimit;
	///��ͣ���
	double	LowerLimitPrice;
	///��ͣ���
	double	UpperLimitPrice;
	///�����
	double	PreSettlementPrice;
	///��Լ����״̬
	char	InstrumentStatus;
	///������
	char	CreateDate[9];
	///������
	char	OpenDate[9];
	///������
	char	ExpireDate[9];
	///��ʼ������
	char	StartDelivDate[9];
	///��󽻸���
	char	EndDelivDate[9];
	///���ƻ�׼��
	double	BasisPrice;
	///��ǰ�Ƿ���
	int	IsTrading;
};
#endif