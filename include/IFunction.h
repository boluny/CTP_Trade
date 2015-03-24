#ifndef IFUNCTIONH
#define IFUNCTIONH
#include "QuantStruct.h"
class IFunction
{
public:
	virtual void Release() = 0;

	//���length�������¼����
	virtual double Sum(const char* lpInstrument, int length, TQuantDataPeriod period = QUANT_DATA_TICK) = 0;
	//length���ƶ�ƽ��
	virtual double MA(const char* lpInstrument ,int length, TQuantDataPeriod period = QUANT_DATA_TICK) = 0;
	//ƽ������ƫ��
	virtual double AVEDEV(const char* lpInstrument ,int length, TQuantDataPeriod period = QUANT_DATA_TICK) = 0;
	//ƫ��ƽ���� 
	virtual double DEVSQ(const char* lpInstrument ,int length, TQuantDataPeriod period = QUANT_DATA_TICK) = 0;
	//���Իع�ֵ
	virtual double FORCAST(const char* lpInstrument ,int length, TQuantDataPeriod period = QUANT_DATA_TICK) = 0;
	//��׼��
	virtual double STD(const char* lpInstrument ,int length, TQuantDataPeriod period = QUANT_DATA_TICK) = 0;
	//����
	virtual double VAR(const char* lpInstrument ,int length, TQuantDataPeriod period = QUANT_DATA_TICK) = 0;
};

extern "C"
{
	IFunction* _cdecl GetFunction();
};

#endif