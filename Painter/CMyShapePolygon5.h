//////////////////////////////////////////////////
// 文件名：		CMyShapePolygon5.h
// 版本：		1.0
// 目的与功能：	图形类：多边形（5边）
// 创建日期：	2020.9.6
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////

#pragma once
class CMyShapePolygon5 :
	public CMyShapePolygon
{
public:
	// 构造函数
	CMyShapePolygon5(CArray <CPoint, CPoint&>& arrayPoints, Color color, int nWidth);
	// 获取名称函数
	virtual CString GetName();
	// 拷贝函数
	virtual CMyShape* Copy();
};

