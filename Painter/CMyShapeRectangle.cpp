//////////////////////////////////////////////////
// 文件名：		CMyShapeRectangle.cpp
// 版本：		1.0
// 目的与功能：	图形类：矩形
// 创建日期：	2020.9.6
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////

#include "pch.h"
#include "CMyShapeRectangle.h"

/**************************************************
Name:		CMyShapeRectangle
Inputs:
			CArray<CPoint, CPoint&>&	arrayPoints	控制点数组
			Color						color		图形颜色
			int							nWidth		图形线宽
Return:
			(none)
Description:
			构造函数
**************************************************/
CMyShapeRectangle::CMyShapeRectangle(CArray<CPoint, CPoint&>& arrayPoints, Color color, int nWidth)
{
	m_nType = MYSHAPE_RECTANGLE;
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
void CMyShapeRectangle::Draw(Graphics& graphicsGDI)
{
	// 创建绘图用画笔
	Pen t_penCurrentPen(m_colorColor, m_nWidth);

	// 创建控制点数组的拷贝
	CArray<CPoint, CPoint&> t_arrayPoints;
	t_arrayPoints.Copy(m_arrayPoints);

	// 将坐标顺序进行校正，保证大小关系
	if (t_arrayPoints[0].x > t_arrayPoints[1].x)
	{
		std::swap(t_arrayPoints[0].x, t_arrayPoints[1].x);
	}
	if (t_arrayPoints[0].y > t_arrayPoints[1].y)
	{
		std::swap(t_arrayPoints[0].y, t_arrayPoints[1].y);
	}

	// 绘制矩形
	graphicsGDI.DrawRectangle(&t_penCurrentPen, t_arrayPoints[0].x, t_arrayPoints[0].y, t_arrayPoints[1].x - t_arrayPoints[0].x, t_arrayPoints[1].y - t_arrayPoints[0].y);
	// 矩形并不需要顶点修正
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
CString CMyShapeRectangle::GetName()
{
	// 用 CString 的格式化方法来创建显示名称字符串
	CString t_strName;
	t_strName.Format(_T("矩形 (%d,%d)-(%d,%d)"),
		m_arrayPoints[0].x, m_arrayPoints[0].y, m_arrayPoints[1].x, m_arrayPoints[1].y);
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
CMyShape* CMyShapeRectangle::Copy()
{
	CMyShapeRectangle* pNewShape = new CMyShapeRectangle(m_arrayPoints, m_colorColor, m_nWidth);
	return pNewShape;
}