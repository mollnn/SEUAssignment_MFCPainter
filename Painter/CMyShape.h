//////////////////////////////////////////////////
// 文件名：		CMyShape.h
// 版本：		1.0
// 目的与功能：	图形抽象类，所有具体图形的基类
// 创建日期：	2020.9.6
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////

#pragma once
class CMyShape : public CObject
{

public:
	// 控制点
	CArray<CPoint, CPoint&> m_arrayPoints;
	// 类型
	int m_nType;
	// 粗细
	int m_nWidth;
	// 颜色
	Color m_colorColor;

	// 绘制函数（纯虚函数）
	virtual void Draw(Graphics& graphicsGDI)=0;
	// 获取名称，用于在列表中显示
	virtual CString GetName();
	// 拷贝函数（纯虚函数）
	virtual CMyShape* Copy() = 0;
	// 赋值函数
	virtual void Assign(CMyShape& shapeSrc);
	// 将 MyShape 转化为 JsonObject
	CJsonObject ToJson();
	// 从 JsonObject 解析图形
	void FromJson(CJsonObject jsonobjShape);
};

// 派生图形对应的 ID 编号
#define MYSHAPE_POINT		1
#define MYSHAPE_LINE		2
#define MYSHAPE_CIRCLE		3
#define MYSHAPE_ELLIPSE		4
#define MYSHAPE_RECTANGLE	5
#define MYSHAPE_POLYGON		100
#define MYSHAPE_POLYGON3	103
#define MYSHAPE_POLYGON4	104
#define MYSHAPE_POLYGON5	105
#define MYSHAPE_POLYGON6	106