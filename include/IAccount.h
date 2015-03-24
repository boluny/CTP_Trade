#ifndef IACCOUNTH
#define IACCOUNTH

#include "ctp\ThostFtdcTraderApi.h"
#include "femas\USTPFtdcTraderApi.h"

class IAccount
{
public:
	//�Ƿ��Ѿ���¼
	virtual bool  IsLogined() = 0;

	virtual void OnConnected() = 0;

	virtual void OnDisconnected() = 0;

	virtual void OnLogined() = 0;

	//ctp trade api
	virtual void  SetCtpTradeApi(CThostFtdcTraderApi* api) = 0;

	//femas trade api
	virtual void  SetUstpTradeApi(CUstpFtdcTraderApi* api) = 0;
};

extern "C"
{
	int  InitAccount();
	IAccount*   GetAccount(const char* lpAccount);
}
#endif