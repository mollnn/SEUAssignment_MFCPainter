//////////////////////////////////////////////////
// 文件名：		CMyShapeLine.cpp
// 版本：		1.0
// 目的与功能：	图形类：直线
// 创建日期：	2020.9.6
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////

#include "pch.h"
#include "CMyShapeLine.h"

/**************************************************
Name:		CMyShapeLine
Inputs:
			CArray<CPoint, CPoint&>&	arrayPoints	控制点数组
			Color						color		图形颜色
			int							nWidth		图形线宽
Return:
			(none)
Description:
			构造函数
**************************************************/
CMyShapeLine::CMyShapeLine(CArray<CPoint, CPoint&> &arrayPoints, Color color, int nWidth)
{
	m_nType = MYSHAPE_LINE;
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
void CMyShapeLine::Draw(Graphics& graphicsGDI)
{
	// 创建绘图用画笔
	Pen t_penCurrentPen(m_colorColor, m_nWidth);
	// 绘制直线
	graphicsGDI.DrawLine(&t_penCurrentPen, m_arrayPoints[0].x, m_arrayPoints[0].y, m_arrayPoints[1].x, m_arrayPoints[1].y);
	
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
CString CMyShapeLine::GetName()
{
	// 用 CString 的格式化方法来创建显示名称字符串
	CString t_strName;
	t_strName.Format(_T("线段 (%d,%d)-(%d,%d)"), 
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
CMyShape* CMyShapeLine::Copy()
{
	CMyShapeLine* pNewShape = new CMyShapeLine(m_arrayPoints, m_colorColor, m_nWidth);
	return pNewShape;
}