#pragma once
#include"stdafx.h"

typedef struct DIC_OPERATOR_TYPE_TAG
{
	/* 人员类型主键序号 */
	long OPERATOR_TYPE_ID;
	/* 人员类型编码 */
	std::string OPERATOR_TYPE_CODE;
	/* 人员类型名称 */
	std::string OPERATOR_TYPE_NAME;
	/*人员类型分类：0  管理类型   1 通用类型   2 行政类型*/
	int OPERATOR_TYPE_FLAG;
	/*人员权限管理（检测系统）： 0 无权限      1 有权限*/
	int AUTHORITY_TYPE_FLAG;
	/*光机反转权限管理（检测系统）： 0 权限关闭     1 权限开启*/
	int XRAYCHECK_AUTH_FLAG;
	/* 启用状态：0  禁用  1 启用 */
	int USE_FLAG;
	/* 启用日期：写入时间 */
	std::string START_DATE;
	/* 禁用日期 */
	std::string END_DATE;
	/* 说明 */
	std::string NOTE;
	/*模式转换权限管理（检测系统）： 0 权限关闭     1 权限开启*/
	int MODEL_AUTH_FLAG;
}DIC_OPERATOR_TYPE;

typedef struct DIC_OPERATOR_TAG
{
	/* 人员序号（主键） */
	long OPERATOR_ID;
	/* 人员类型序号(外键) */
	long OPERATOR_TYPE_ID;
	/* 人员编号 */
	std::string OPERATOR_CODE;
	/* 人员名称 */
	std::string OPERATOR_NAME;
	/* 启用状态：0  禁用  1 启用 */
	int USE_FLAG;
	/* 启用日期：写入时间 */
	std::string START_DATE;
	/* 禁用日期 */
	std::string END_DATE;
	/* 说明 */
	std::string NOTE;
}DIC_OPERATOR;

typedef struct DIC_MACHINE_TAG
{
	/* 设备类型主键序号 */
	long MACHINE_ID;
	/* 设备类型编码 */
	std::string MACHINE_CODE;
	/* 设备类型名称 */
	std::string MACHINE_NAME;
	/* 启用状态：0  禁用  1 启用 */
	int USE_FLAG;
	/* 启用日期：写入时间 */
	std::string START_DATE;
	/* 禁用日期 */
	std::string END_DATE;
	/* 说明 */
	std::string NOTE;
}DIC_MACHINE;

typedef struct DIC_PRODUCT_TAG
{
	/* 券别主键序号 */
	long PRODUCT_ID;
	/* 券别编号 */
	std::string PRODUCT_CODE;
	/* 券别名称 */
	std::string PRODUCT_NAME;
	/* 券别面值（元） */
	int PRODUCT_AMOUNT;
    /*券别单捆重量（KG）*/
	float PRODUCT_WEIGHT;
	/* 启用状态：0  禁用  1 启用 */
	int USE_FLAG;
	/* 启用日期：写入时间 */
	std::string START_DATE;
	/* 禁用日期 */
	std::string END_DATE;
	/* 说明 */
	std::string NOTE;
}DIC_PRODUCT;