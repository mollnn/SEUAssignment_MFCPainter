//////////////////////////////////////////////////
// 文件名：		CMyShapePolygon5.cpp
// 版本：		1.0
// 目的与功能：	图形类：多边形（5边）
// 创建日期：	2020.9.6
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////

#include "pch.h"
#include "CMyShapePolygon5.h"

/**************************************************
Name:		CMyShapePolygon5
Inputs:
			CArray<CPoint, CPoint&>&	arrayPoints	控制点数组
			Color						color		图形颜色
			int							nWidth		图形线宽
Return:
			(none)
Description:
			构造函数
**************************************************/
CMyShapePolygon5::CMyShapePolygon5(CArray<CPoint, CPoint&>& arrayPoints, Color color, int nWidth) : CMyShapePolygon(arrayPoints, color, nWidth)
{
	m_nType = MYSHAPE_POLYGON5;
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
CString CMyShapePolygon5::GetName()
{
	return CMyShapePolygon::GetName(CString(_T("五边形 ")));
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
CMyShape* CMyShapePolygon5::Copy()
{
	CMyShapePolygon5* pNewShape = new CMyShapePolygon5(m_arrayPoints, m_colorColor, m_nWidth);
	return pNewShape;
}