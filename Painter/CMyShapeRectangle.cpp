//////////////////////////////////////////////////
// �ļ�����		CMyShapeRectangle.cpp
// �汾��		1.0
// Ŀ���빦�ܣ�	ͼ���ࣺ����
// �������ڣ�	2020.9.6
// �޸����ڣ�	2020.9.14
// ���ߣ�		Fan Zhimin
// �޸��ߣ�		Fan Zhimin
// ��ϵ��ʽ��	
//////////////////////////////////////////////////

#include "pch.h"
#include "CMyShapeRectangle.h"

/**************************************************
Name:		CMyShapeRectangle
Inputs:
			CArray<CPoint, CPoint&>&	arrayPoints	���Ƶ�����
			Color						color		ͼ����ɫ
			int							nWidth		ͼ���߿�
Return:
			(none)
Description:
			���캯��
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
			Graphics& graphicsGDI	����Ŀ�� GDI+ ���������
Return:
			(none)
Description:
			�� GDI+ �����ϻ��Ʊ�ͼ��
**************************************************/
void CMyShapeRectangle::Draw(Graphics& graphicsGDI)
{
	// ������ͼ�û���
	Pen t_penCurrentPen(m_colorColor, m_nWidth);

	// �������Ƶ�����Ŀ���
	CArray<CPoint, CPoint&> t_arrayPoints;
	t_arrayPoints.Copy(m_arrayPoints);

	// ������˳�����У������֤��С��ϵ
	if (t_arrayPoints[0].x > t_arrayPoints[1].x)
	{
		std::swap(t_arrayPoints[0].x, t_arrayPoints[1].x);
	}
	if (t_arrayPoints[0].y > t_arrayPoints[1].y)
	{
		std::swap(t_arrayPoints[0].y, t_arrayPoints[1].y);
	}

	// ���ƾ���
	graphicsGDI.DrawRectangle(&t_penCurrentPen, t_arrayPoints[0].x, t_arrayPoints[0].y, t_arrayPoints[1].x - t_arrayPoints[0].x, t_arrayPoints[1].y - t_arrayPoints[0].y);
	// ���β�����Ҫ��������
}

/**************************************************
Name:		GetName
Inputs:
			(none)
Return:
			(CString)	���ص���ʾ����
Description:
			��ȡͼ�ε���ʾ����
**************************************************/
CString CMyShapeRectangle::GetName()
{
	// �� CString �ĸ�ʽ��������������ʾ�����ַ���
	CString t_strName;
	t_strName.Format(_T("���� (%d,%d)-(%d,%d)"),
		m_arrayPoints[0].x, m_arrayPoints[0].y, m_arrayPoints[1].x, m_arrayPoints[1].y);
	return t_strName;
}

/**************************************************
Name:		Copy
Inputs:
			(none)
Return:
			(CMyShape*)		�������¶����ָ��
Description:
			������ͼ�ε�һ�ݿ�����������ָ������ָ��
**************************************************/
CMyShape* CMyShapeRectangle::Copy()
{
	CMyShapeRectangle* pNewShape = new CMyShapeRectangle(m_arrayPoints, m_colorColor, m_nWidth);
	return pNewShape;
}