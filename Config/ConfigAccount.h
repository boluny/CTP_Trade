//�����xml�ļ�����������Account�ֶ�

#ifndef CONFIG_API_H
#define CONFIG_API_H

#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xmlmemory.h>  
#include <libxml/parser.h>
#include <iostream>
#include "UserApiStruct.h"

class CAccount 
{
public:
	//�ĵ���ȡ
	void ParseDoc(string docname);
	//�����ֶζ�ȡ
	void ParseAccount(xmlDocPtr doc, xmlNodePtr cur);
		
	//��������
	vector<CAccountField>& GetAccountField()
	{return m_vecAccount;}
private:
	vector<CAccountField> m_vecAccount;
};

#endif
