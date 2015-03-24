//�ӿڲ��֣�IConfig���࣬������ģ���ṩ�ӿ�
//���幦�ܣ�ʵ�ֶ������ļ�server.xml��strategy.xml�ļ���ȡ����������ģ���ṩ�ӿ�

#ifndef ICONFIG_H
#define ICONFIG_H

#include "UserApiStruct.h"

#define STRATEGY_CANNOT_FIND_ERROR 1

using namespace std;

class IConfig {
public:
	//��ȡ�˺����������
	virtual void GetAccount(vector<CAccountField> &vecAccountField)=0;

	//��ȡ�����˺����������
	virtual CAccountField* GetAccount(const char * name)=0;

	//��ȡBroker Id
	virtual int GetBrokerId()=0;

	//��ȡ�������������
	virtual void GetServer(vector<CServerField> &vecServerField)=0;

	//��ȡ��������
	virtual void GetStrategy(vector<CStrategyField> &vecStrategyField)=0;

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

//ȫ�ֺ������� IConfig*�����ؼ̳е�ʵ��ͷ�ļ���ͨ��һ��ȫ�ֺ������ṩ�ӿ��ļ�
extern IConfig* GetConfig();

/*
extern "C"
{
	IConfig*  GetConfig();
};*/

#endif