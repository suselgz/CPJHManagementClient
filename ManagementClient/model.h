#pragma once
#include"stdafx.h"

typedef struct DIC_OPERATOR_TYPE_TAG
{
	/* ��Ա����������� */
	long OPERATOR_TYPE_ID;
	/* ��Ա���ͱ��� */
	std::string OPERATOR_TYPE_CODE;
	/* ��Ա�������� */
	std::string OPERATOR_TYPE_NAME;
	/*��Ա���ͷ��ࣺ0  ��������   1 ͨ������   2 ��������*/
	int OPERATOR_TYPE_FLAG;
	/*��ԱȨ�޹������ϵͳ���� 0 ��Ȩ��      1 ��Ȩ��*/
	int AUTHORITY_TYPE_FLAG;
	/*�����תȨ�޹������ϵͳ���� 0 Ȩ�޹ر�     1 Ȩ�޿���*/
	int XRAYCHECK_AUTH_FLAG;
	/* ����״̬��0  ����  1 ���� */
	int USE_FLAG;
	/* �������ڣ�д��ʱ�� */
	std::string START_DATE;
	/* �������� */
	std::string END_DATE;
	/* ˵�� */
	std::string NOTE;
	/*ģʽת��Ȩ�޹������ϵͳ���� 0 Ȩ�޹ر�     1 Ȩ�޿���*/
	int MODEL_AUTH_FLAG;
}DIC_OPERATOR_TYPE;

typedef struct DIC_OPERATOR_TAG
{
	/* ��Ա��ţ������� */
	long OPERATOR_ID;
	/* ��Ա�������(���) */
	long OPERATOR_TYPE_ID;
	/* ��Ա��� */
	std::string OPERATOR_CODE;
	/* ��Ա���� */
	std::string OPERATOR_NAME;
	/* ����״̬��0  ����  1 ���� */
	int USE_FLAG;
	/* �������ڣ�д��ʱ�� */
	std::string START_DATE;
	/* �������� */
	std::string END_DATE;
	/* ˵�� */
	std::string NOTE;
}DIC_OPERATOR;

typedef struct DIC_MACHINE_TAG
{
	/* �豸����������� */
	long MACHINE_ID;
	/* �豸���ͱ��� */
	std::string MACHINE_CODE;
	/* �豸�������� */
	std::string MACHINE_NAME;
	/* ����״̬��0  ����  1 ���� */
	int USE_FLAG;
	/* �������ڣ�д��ʱ�� */
	std::string START_DATE;
	/* �������� */
	std::string END_DATE;
	/* ˵�� */
	std::string NOTE;
}DIC_MACHINE;

typedef struct DIC_PRODUCT_TAG
{
	/* ȯ��������� */
	long PRODUCT_ID;
	/* ȯ���� */
	std::string PRODUCT_CODE;
	/* ȯ������ */
	std::string PRODUCT_NAME;
	/* ȯ����ֵ��Ԫ�� */
	int PRODUCT_AMOUNT;
    /*ȯ����������KG��*/
	float PRODUCT_WEIGHT;
	/* ����״̬��0  ����  1 ���� */
	int USE_FLAG;
	/* �������ڣ�д��ʱ�� */
	std::string START_DATE;
	/* �������� */
	std::string END_DATE;
	/* ˵�� */
	std::string NOTE;
}DIC_PRODUCT;