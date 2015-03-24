//�����ļ�
#include "IConfig.h"
#include "UserApiStruct.h"
#include "CConfig.h"
#include "ConfigAccount.h"
#include "ConfigServer.h"

int main(int argc, char* argv[])	
{
	//fund����������
    IConfig *account = new CConfig();
	vector<CAccountField> vecAccountValue;
	vector<CServerField> vecServerValue;
	vector<CStrategyField> vecStrategyValue;
	CStrategyField* strStrategy;
	vector<string> vecInstrument;
	vector<string> vecAllInstrument;
	vector<string> vecCode;
	vector<string> vecAllCode;

	account->GetAccount(vecAccountValue);
	//���÷���������,error??
	account->GetAccount("111111");
	cout<<account->GetAccount("111111")->m_szPwd<<endl;
	int tt=account->GetBrokerId();
	account->GetStrategy(vecStrategyValue);

	//how test?GetStrategy("arbitrage")������
	account->GetStrategy("arbitrage");
	cout<<account->GetStrategy("arbitrage")->m_szUserId<<endl;

	account->GetInstrument("arbitrage",vecInstrument);
	account->GetInstrument(vecAllInstrument);
	account->GetCode("arbitrage",vecCode);
	account->GetCode(vecAllCode);
	
}