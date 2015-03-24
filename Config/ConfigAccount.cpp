#include "ConfigAccount.h"


void CAccount::ParseAccount(xmlDocPtr doc, xmlNodePtr cur)
{
	CAccountField accValue;
	xmlNodePtr propNodePtr = cur->xmlChildrenNode;	
	propNodePtr = propNodePtr->next;
	while(propNodePtr!=NULL)
	{
		//ͨ������accValue���������Ϣpush��vector
		if (!xmlStrcmp(propNodePtr->name,BAD_CAST "item"))
		{
			xmlAttrPtr attrPtr = propNodePtr->properties;
			while (attrPtr != NULL)
			{
				//���Ҵ�������userid�Ľڵ㣬�Դ������ļ��Ľ���
				if (!xmlStrcmp(attrPtr->name, BAD_CAST "userid"))
				{
					xmlChar* szAttr = xmlGetProp(propNodePtr,attrPtr->name);
					strcpy(accValue.m_szUserId,(char*)szAttr);
					xmlFree(szAttr);
				} 
				else 
				{
					//��ȡpwd����
					xmlChar* szAttr = xmlGetProp(propNodePtr,attrPtr->name);
					strcpy(accValue.m_szPwd,(char*)szAttr);
					xmlFree(szAttr);
				}
				attrPtr = attrPtr->next;
			}
			//�����⣺�ظ��˺����ö�ȡʱ��־��ӡ��ֱ�ӿ���̨�ϴ�ӡ���
			int t=1;
			for (vector<string>::size_type i=0; i< m_vecAccount.size(); i++)
			{
				if (!strcmp(m_vecAccount[i].m_szUserId,accValue.m_szUserId))
				{
					cerr<<"account user id "<<m_vecAccount[i].m_szUserId<<" must not be the same"<<endl;
					t=0;
				}
			}
			if(t)
				m_vecAccount.push_back(accValue);
		}	
		propNodePtr = propNodePtr->next;
	}
	return ;
}

void CAccount::ParseDoc(string docname)
{
	xmlDocPtr doc;           //��������ĵ�ָ��
    xmlNodePtr curNode;      //������ָ��

	doc = xmlParseFile(docname.c_str()); //�����ļ�
	//�������ĵ��Ƿ�ɹ���������ɹ���libxml��ָһ��ע��Ĵ���ֹͣ��
    if (NULL == doc)
    { 
       fprintf(stderr,"Document not parsed successfully.\n");    
       return ;
    }

    curNode = xmlDocGetRootElement(doc); //ȷ���ĵ���Ԫ��   
    if (NULL == curNode)
    {
       fprintf(stderr,"empty document\n");
       xmlFreeDoc(doc);
       return ;
    }
   
    if (xmlStrcmp(curNode->name, BAD_CAST "root"))	//��#define BAD_CAST (xmlChar *)
    {
       fprintf(stderr,"document of the wrong type, root node != root");
       xmlFreeDoc(doc);
       return ;
    }

    curNode = curNode->xmlChildrenNode;
    while(curNode != NULL)
    {
       //ȡ���ڵ��е����ݣ�ParseAccount()�����������
	   if ((!xmlStrcmp(curNode->name, BAD_CAST "account")))
       {
           ParseAccount(doc, curNode);
       }
       curNode = curNode->next;
    }    
    xmlFreeDoc(doc);
    return ;
}

