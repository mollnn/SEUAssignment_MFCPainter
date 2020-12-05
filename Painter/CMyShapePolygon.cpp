//////////////////////////////////////////////////
// 文件名：		CMyShapePolygon.cpp
// 版本：		1.0
// 目的与功能：	图形类：多边形（所有具体多边形的基类）
// 创建日期：	2020.9.6
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////


#include "pch.h"
#include "CMyShapePolygon.h"

/**************************************************
Name:		CMyShapePolygon
Inputs:
			CArray<CPoint, CPoint&>&	arrayPoints	控制点数组
			Color						color		图形颜色
			int							nWidth		图形线宽
Return:
			(none)
Description:
			构造函数
**************************************************/
CMyShapePolygon::CMyShapePolygon(CArray<CPoint, CPoint&>& arrayPoints, Color color, int nWidth)
{
	m_nType = MYSHAPE_POLYGON;
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
void CMyShapePolygon::Draw(Graphics& graphicsGDI)
{
	// 创建绘图用画笔
	Pen t_penCurrentPen(m_colorColor, m_nWidth);
	// 绘制多边形的所有边
	for (int i = 1; i < m_arrayPoints.GetSize(); i++)
	{
		graphicsGDI.DrawLine(&t_penCurrentPen, m_arrayPoints[i - 1].x, m_arrayPoints[i - 1].y, m_arrayPoints[i].x, m_arrayPoints[i].y);
	}
	graphicsGDI.DrawLine(&t_penCurrentPen, m_arrayPoints[0].x, m_arrayPoints[0].y, m_arrayPoints[m_arrayPoints.GetSize() - 1].x, m_arrayPoints[m_arrayPoints.GetSize() - 1].y);
	
	// 顶点修正，对于顶点处画一个实心圆形来实现平滑的末端
	SolidBrush t_brushCurrentSolidBrush(m_colorColor);
	for (int i = 0; i < m_arrayPoints.GetSize(); i++)
	{
		graphicsGDI.FillEllipse(&t_brushCurrentSolidBrush, 1.0f * m_arrayPoints[i].x - 0.5f * m_nWidth, 1.0f * m_arrayPoints[i].y - 0.5f * m_nWidth, 1.0f * m_nWidth, 1.0f * m_nWidth);
	}
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
CString CMyShapePolygon::GetName(CString strPrefix)
{
	CString t_strName;
	t_strName = strPrefix;
	for (int i = 0; i < m_arrayPoints.GetSize(); i++)
	{
		CString t_strAppendix;
		t_strAppendix.Format(_T("(%d,%d)"), m_arrayPoints[i].x, m_arrayPoints[i].y);
		t_strName.Append(t_strAppendix);
		if (i < m_arrayPoints.GetSize() - 1)
		{
			t_strName.Append(_T("-"));
		}
	}
	return t_strName;
}

/**************************************************
Name:		Copy
Inputs:
			(none)
Return:
			(CMyShape*)		拷贝的新对象的指针
Description:
			创建本图形的一份拷贝，并返回指向它的指针
**************************************************/
CMyShape* CMyShapePolygon::Copy()
{
	CMyShapePolygon* pNewShape = new CMyShapePolygon(m_arrayPoints, m_colorColor, m_nWidth);
	return pNewShape;
}