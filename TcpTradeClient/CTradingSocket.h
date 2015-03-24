#pragma once
#include "CSocket.h"

class CTradingSocket 
{
public:
	CTradingSocket()
	{
		//���캯����ʼ����Ա�������ݣ���ȡ���ն�Map����
		m_CTtcp.RecvThreadOrder();
	}
	~CTradingSocket(){}
	/*  ����
	/* @Param
	/*  InstrumentID  ��Լ
	/*  Direciton     �������� ��osdBuy�� ��  "osdSell" ��
	/*	Volumn	      ����
	/*	Type	      ��������  "otStopLimit" ֹ��   "otLimit"�޼۵�(ֻ֧���޼۵�)
	/*  LimitPrice    �����۸�
	/*  StopPrice     ֹ��۸�
	/*  Duration      ��Ч������ ��odGoodTillCanceled�� ����ǰ��Ч    "odDay" ������Ч	 "odIOC" �����ɽ�������
	/*  Transit_Now   True ���Ϸ���
	/*  OffsetFlag    ��ƽ�ֱ�־ "ofOpen" ����  "ofClose" ƽ��  "ofForceClose"ǿƽ  "ofCloseToday"ƽ��  "ofCloseYesterday"ƽ��   
	/*  HedgeFlag	  �ױ���־  "ohSpeculation"Ͷ��   "ohArbitrage"����   "ohHedge"�ױ�	
	/*  Account       �ʺ�
	/* @Return
	/*  �ɹ�����ί�кţ����򷵻�0
	*/
	LONG ReqOrder(LPCTSTR InstrumentID, LPCTSTR Direciton, LONG Volumn,LPCTSTR Type, DOUBLE LimitPrice,DOUBLE StopPrice,LPCTSTR Duration,BOOL Transit_Now,  LPCTSTR OffsetFlag, LPCTSTR HedgeFlag, LPCTSTR Account);
	
	/* ����
	/* @Param
	/*  orderID       ����ID
	/* @Return
	/*  �ɹ�1  0ʧ��
	*/
	SHORT Cancel(LONG orderID);
	
	/* ��ȡ������Ϣ
	/* @Param
	/*  orderID       ����ID
	/*  Type :         ����
	/*        Fills				   (price_traded)��ȡ�ɽ�����       
	/*        FilledQuantity	(volume_original)��ȡ�ɽ�����
	/*		  GWStatus			   (order_status)��ȡ����״̬ ��osRejectGW�������ܾ� ��osCanceled������  ��osFilled���ɽ� ��osPending���ѱ� ��osPartCanceled�����ֳ���  "osPartFilled"���ֳɽ�
	/*        CanBeCanceled			   (rsp_type)�ж��Ƿ��ܳ���   ��1���ɳ� ��0�����ܳ�
	/* @Return
	/*  
	*/
	//LPCTSTR��char*��BSTR��WCHAR*
	BSTR GetExecInfo(LONG OrderID, LPCTSTR Type);

private:
	TCP m_CTtcp;
};