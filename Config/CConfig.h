//��̬�̳��ļ�����IConfig�ļ��ļ̳�
//ͨ��CAccount m_account; CServer m_server; CStrategy m_strategy;ʵ����ʵ�ֺ������ﵽʵ�ֺͼ̳з���Ĺ���

#ifndef CONFIG_CONFIG_H
#define CONFIG_CONFIG_H

#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xmlmemory.h>  
#include <libxml/parser.h>
#include <algorithm>
#include "UserApiStruct.h"
#include "ConfigAccount.h"
#include "ConfigServer.h"
#include "ConfigStrategy.h"
#include "IConfig.h"

class CConfig : public IConfig
{
public:
	//���캯����ʼ��private��Ա
	CConfig()
	{
		//���������ļ���ʼ��
		m_account.ParseDoc("server.xml");
	    m_server.ParseDoc("server.xml");
		m_strategy.ParseDoc("strategy.xml",&m_account.GetAccountField());
	}	
	//Get����ʵ�������ļ��Ķ�ȡ����
	void GetAccount(vector<CAccountField> &vecAccountField);
	CAccountField* GetAccount(const char * name);
	int GetBrokerId();
	void GetServer(vector<CServerField> &vecServerField);

	void GetStrategy(vector<CStrategyField> & vecStrategyField);
	CStrategyField* GetStrategy(const char *name);
	void GetInstrument(const char *name, vector<string>& vecInstrument);
	void GetInstrument(vector<string>& vecInstrument);
	void GetCode(const char *name, vector<string>& vecCode);
	void GetCode(vector<string>& vecCode);

private:
	//��ʵ������Ȼ��ʵ�ֵ���ͳһ�̳к�����ȡ��ͬ���ʵ�ֺ���
	CAccount m_account;
	CServer m_server;
	CStrategy m_strategy;
};

#endif