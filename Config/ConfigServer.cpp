#include "ConfigServer.h"


void CServer::ParseServer(xmlDocPtr doc, xmlNodePtr cur)
{
	//��ȡBrokerId����
	if (!xmlStrcmp(cur->properties->name, BAD_CAST "brokerid"))
    {
		xmlChar* szAttr = xmlGetProp(cur,BAD_CAST "brokerid");
		//xmlChar*ת��Ϊint
		m_nBrokerId=atoi((char*)szAttr);
		xmlFree(szAttr);
	}

	CServerField serValue;
	xmlNodePtr propNodePtr = cur->xmlChildrenNode;	
	propNodePtr = propNodePtr->next;
	while(propNodePtr!=NULL)
	{
		if (!xmlStrcmp(propNodePtr->name,BAD_CAST "item"))
		{
			xmlAttrPtr attrPtr = propNodePtr->properties;
			while (attrPtr != NULL)
			{
				if (!xmlStrcmp(attrPtr->name, BAD_CAST "name"))
				{
					xmlChar* szAttr = xmlGetProp(propNodePtr,attrPtr->name);
					strcpy(serValue.m_szName,(char*)szAttr);
					xmlFree(szAttr);
				} 
				else if (!xmlStrcmp(attrPtr->name, BAD_CAST "tradefront"))
				{
					//trade
					xmlChar* szAttr = xmlGetProp(propNodePtr,attrPtr->name);
					strcpy(serValue.m_szTrade,(char*)szAttr);
					xmlFree(szAttr);
				}
				else 
				{
					//md
					xmlChar* szAttr = xmlGetProp(propNodePtr,attrPtr->name);
					strcpy(serValue.m_szMd,(char*)szAttr);
					xmlFree(szAttr);
				}
				attrPtr = attrPtr->next;
			}
			m_vecServer.push_back(serValue);
		}	
		propNodePtr = propNodePtr->next;
	}	
	return ;
}

void CServer::ParseDoc(string docname)
{
	//��������ĵ�ָ�룬xmlDoc��һ��struct��������һ��xml�������Ϣ��xmlDocPtr����xmlDoc*
	xmlDocPtr doc;           
    xmlNodePtr curNode;      //������ָ��

	doc = xmlParseFile(docname.c_str()); //�����ļ�
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
	   if ((!xmlStrcmp(curNode->name, BAD_CAST "server")))
       {
           ParseServer(doc, curNode);
       }
       curNode = curNode->next;
    }    
    xmlFreeDoc(doc);
    return ;
}