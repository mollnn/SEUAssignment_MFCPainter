//////////////////////////////////////////////////
// 文件名：		CMyShapePolygon6.cpp
// 版本：		1.0
// 目的与功能：	图形类：多边形（6边）
// 创建日期：	2020.9.6
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////

#include "pch.h"
#include "CMyShapePolygon6.h"

/**************************************************
Name:		CMyShapePolygon6
Inputs:
			CArray<CPoint, CPoint&>&	arrayPoints	控制点数组
			Color						color		图形颜色
			int							nWidth		图形线宽
Return:
			(none)
Description:
			构造函数
**************************************************/
CMyShapePolygon6::CMyShapePolygon6(CArray<CPoint, CPoint&>& arrayPoints, Color color, int nWidth) : CMyShapePolygon(arrayPoints, color, nWidth)
{
	m_nType = MYSHAPE_POLYGON6;
	m_arrayPoints.Copy(arrayPoints);
	m_colorColor = color;
	m_nWidth = nWidth;
}

/**************************************************
Name:		Draw
Inputs:
			Graphics& graphicsGDI	绘制目标 GDI+ 对象的引用
Return:
			(none)
Description:
			在 GDI+ 对象上绘制本图形
**************************************************/
CString CMyShapePolygon6::GetName()
{
	return CMyShapePolygon::GetName(CString(_T("六边形 ")));
}

/**************************************************
Name:		GetName
Inputs:
			(none)
Return:
			(CString)	返回的显示名称
Description:
			获取图形的显示名称
**************************************************/
CMyShape* CMyShapePolygon6::Copy()
{
	CMyShapePolygon6* pNewShape = new CMyShapePolygon6(m_arrayPoints, m_colorColor, m_nWidth);
	return pNewShape;
}