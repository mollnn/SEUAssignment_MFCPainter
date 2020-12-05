//////////////////////////////////////////////////
// 文件名：		CShapeCreator.h
// 版本：		1.0
// 目的与功能：	图形创建器（一个状态机）
// 创建日期：	2020.9.6
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////


#pragma once

// 用于图形创建的状态机类
class CShapeCreator
{
public:
	// 标准构造函数
	CShapeCreator();


	// 标志位，表明是否正在创建图形
	bool m_bIsCreating;
	// 正在创建的图形的类型，取值见 CMyShape.h 中的定义
	int m_nType;
	// 正在创建的图形已经完成的步骤数
	int m_nSteps;
	// 正在创建的图形已经加入的控制点数组
	CArray<CPoint, CPoint&> m_arrayPoints;
	// 指向目标图形数组的指针，创建完成后，状态机会将新图形插入到该指针指向的数组中
	CObArray* m_pObArray;
	// 正在创建的图形的颜色
	Color m_colorColor;
	// 正在创建的图形的线宽
	int m_nWidth;
	// 新建图形时自动弹出设置对话框
	bool m_bShowSetting;


	
	// 设定目标图形数组的指针
	void SetTarget(CObArray* pObArrayTarget);
	// 发送开始创建命令，需要指定要创建图形的类别
	void BeginCreating(int t_nType);
	// 添加一个新的控制点
	void PushPoint(CPoint pointNewPoint);
	// 状态机拷贝函数
	void Copy(CShapeCreator* pSrcShapeCreator);
	// 从 JsonObject 创建一个图形，注意这不会影响状态机的状态
	void CreateFromJson(CJsonObject jsonobjShape);
};

