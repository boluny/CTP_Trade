#include "CConfig.h"

//ȫ�ֺ������� IConfig*�����ؼ̳е�ʵ��ͷ�ļ���ͨ��һ��ȫ�ֺ������ṩ�ӿ��ļ�
IConfig* GetConfig()
{
	IConfig* config=new CConfig();
	return config;
}

void CConfig::GetAccount(vector<CAccountField> &vecAccountField)
{
	vecAccountField=m_account.GetAccountField();
}

//ָ�뷵�ض�������
CAccountField* CConfig::GetAccount(const char * name)
{
	for(vector<CAccountField>::size_type i=0;i<m_account.GetAccountField().size();i++)
	{
		if(!strcmp(m_account.GetAccountField().at(i).m_szUserId,name))
		{
			return &m_account.GetAccountField().at(i);
		}
	}
	return NULL;
}

int CConfig::GetBrokerId()
{
	return m_server.GetBrokerId();
}

void CConfig::GetServer(vector<CServerField> &vecServerField)
{
	vecServerField=m_server.GetServerField();
}

void CConfig::GetStrategy(vector<CStrategyField> & vecStrategyField)
{
	vecStrategyField=m_strategy.GetStrategyField();
}

CStrategyField* CConfig::GetStrategy(const char *name)
{
	for(vector<CStrategyField>::size_type i=0;i<m_strategy.GetStrategyField().size();i++)
	{
		if(!strcmp(m_strategy.GetStrategyField().at(i).m_szStrategyName,name))
		{
			return &m_strategy.GetStrategyField().at(i);
		}
	}
	return NULL;
}

void CConfig::GetInstrument(const char *name, vector<string>& vecInstrument)
{
	for(vector<CStrategyField>::size_type i=0;i<m_strategy.GetStrategyField().size();i++)
	{
		if(!strcmp(m_strategy.GetStrategyField().at(i).m_szStrategyName,name))
		{
			vecInstrument=m_strategy.GetStrategyField().at(i).m_vecInstrument;
			return ;
		}
	}
	return ;
}

void CConfig::GetInstrument(vector<string>& vecInstrument)
{
	for(vector<CStrategyField>::size_type i=0;i<m_strategy.GetStrategyField().size();i++)
	{
		//Instrument�ϲ�
		vector<string> myCopy=m_strategy.GetStrategyField().at(i).m_vecInstrument;
		vecInstrument.insert(vecInstrument.end(), myCopy.begin(), myCopy.end());
		//����
		sort(vecInstrument.begin(), vecInstrument.end()); 
		//ȥ��
	    vecInstrument.erase(unique(vecInstrument.begin(), vecInstrument.end()),vecInstrument.end());
	}
	return ;
}
	
void CConfig::GetCode(const char *name, vector<string>& vecCode)
{
	for(vector<CStrategyField>::size_type i=0;i<m_strategy.GetStrategyField().size();i++)
	{
		if(!strcmp(m_strategy.GetStrategyField().at(i).m_szStrategyName,name))
		{
			vecCode=m_strategy.GetStrategyField().at(i).m_vecCode;
			return ;
		}
	}
	return ;
}
	
void CConfig::GetCode(vector<string>& vecCode)
{
	for(vector<CStrategyField>::size_type i=0;i<m_strategy.GetStrategyField().size();i++)
	{
		vector<string> myCopy=m_strategy.GetStrategyField().at(i).m_vecCode;
		vecCode.insert(vecCode.end(), myCopy.begin(), myCopy.end());
		//����
		sort(vecCode.begin(), vecCode.end() ); 
		//ȥ��
		vecCode.erase(unique(vecCode.begin(), vecCode.end()),vecCode.end());
	}
	return ;
}



