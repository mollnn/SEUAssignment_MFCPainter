//////////////////////////////////////////////////
// 文件名：		CMyShapePoint.h
// 版本：		1.0
// 目的与功能：	图形类：点
// 创建日期：	2020.9.6
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////

#pragma once

class CMyShapePoint :
	public CMyShape
{
public:
	// 构造函数
	CMyShapePoint(CArray<CPoint, CPoint&>& arrayPoints, Color color, int nWidth);
	// 绘图函数
	virtual void Draw(Graphics& graphicsGDI);
	// 获取名称函数
	virtual CString GetName();
	// 拷贝函数
	virtual CMyShape* Copy();
};

