/////////////////////////////////////////////////////////////////////////
///@system   ������������ƽ̨
///@company  �д��ڻ�
///@file IData.h
///@brief    ��������������ӿ�
///@history 
///20141015	�쵩		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef IDATAH
#define IDATAH

#include "QuantStruct.h"

typedef void (*OnRecvFuturesMarketData)(CQuantDepthQuoteDataField*, long lHandle);


class IDataCore
{
public:
	//ע���ڻ����ݻص�
	virtual bool ReqRecvMarketData(OnRecvFuturesMarketData fRecv,  long lHandle) = 0;

	virtual long GetMarketData(const char* lpInstrument,CQuantDepthQuoteDataField** ppMarketData, long lDataNum) = 0;

	virtual long GetKLineData(const char* lpInstrument,CQuantKLineDataField** ppMarketData, long lDataNum, TQuantDataPeriod period) = 0;

	virtual void Release() = 0;

};

extern "C"
{
	IDataCore* GetDataCore();
};

#endif