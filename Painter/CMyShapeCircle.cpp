//////////////////////////////////////////////////
// 文件名：		CMyShapeCircle.cpp
// 版本：		1.0
// 目的与功能：	图形类：圆形
// 创建日期：	2020.9.6
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////

#include "pch.h"
#include "CMyShapeCircle.h"

/**************************************************
Name:		CMyShapeCircle
Inputs:
			CArray<CPoint, CPoint&>&	arrayPoints	控制点数组
			Color						color		图形颜色
			int							nWidth		图形线宽
Return:
			(none)
Description:
			构造函数
**************************************************/
CMyShapeCircle::CMyShapeCircle(CArray<CPoint, CPoint&>& arrayPoints, Color color, int nWidth)
{
	m_nType = MYSHAPE_CIRCLE;
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
void CMyShapeCircle::Draw(Graphics& graphicsGDI)
{
	// 创建绘图用画笔
	Pen t_penCurrentPen(m_colorColor, m_nWidth);
	double radius = sqrt(pow(m_arrayPoints[0].x - m_arrayPoints[1].x, 2) + pow(m_arrayPoints[0].y - m_arrayPoints[1].y, 2));	// 计算圆形的半径
	// 绘制椭圆
	graphicsGDI.DrawEllipse(&t_penCurrentPen, (Gdiplus::REAL)(m_arrayPoints[0].x - radius), m_arrayPoints[0].y - radius, 2 * radius, 2 * radius);
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
CString CMyShapeCircle::GetName()
{
	// 用 CString 的格式化方法来创建显示名称字符串
	CString t_strName = _T("Circle ");
	CString t_strAppendix;
	t_strAppendix.Format(_T("(%d,%d), r=%.2f "),
		m_arrayPoints[0].x, m_arrayPoints[0].y, sqrt(pow(m_arrayPoints[0].x - m_arrayPoints[1].x, 2) + pow(m_arrayPoints[0].y - m_arrayPoints[1].y, 2)));
	t_strName.Append(t_strAppendix);
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
CMyShape* CMyShapeCircle::Copy()
{
	CMyShapeCircle* pNewShape = new CMyShapeCircle(m_arrayPoints, m_colorColor, m_nWidth);
	return pNewShape;
}