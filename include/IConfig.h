#ifndef ICONFIG_H
#define ICONFIG_H

#include "InnerStruct.h"

#define RISK_ID_MAXDEFICIT 0x0001

enum EServerType
{
	ctp,
	ustp
};

class IConfig {
public:
	virtual EServerType GetServerType() = 0;

	virtual void Release() = 0;

	//��ȡ�˺����������
	virtual void GetAccount(vector<CAccountField> &vecAccountField)=0;

	//��ȡ�����˺����������
	virtual CAccountField* GetAccount(const char * name)=0;

	//��ȡBroker Id
	virtual const char* GetBrokerId()=0;

	//��ȡ�������������
	virtual void GetServer(vector<CServerField> &vecServerField)=0;

	//��ȡ��������
	virtual void GetStrategy(vector<CStrategyField> & vecStrategyField)=0;

	//��ȡ������������
	virtual CStrategyField* GetStrategy(const char *name)=0;

	//��ȡ���������ڻ���Լ����
	virtual void GetInstrument(const char *name, vector<string>& vecInstrument)=0;

	//��ȡȫ���ڻ���Լ����
	virtual void GetInstrument(vector<string>& vecInstrument)=0;

	//��ȡcode����
	virtual void GetCode(const char *name, vector<string>& vecCode)=0;

	//��ȡȫ��code����
	virtual void GetCode(vector<string>& vecCode)=0;
};


extern "C"
{
	IConfig* _cdecl GetConfig();
};

#endif