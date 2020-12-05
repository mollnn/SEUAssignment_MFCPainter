//////////////////////////////////////////////////
// �ļ�����		CMyShapeEllipse.cpp
// �汾��		1.0
// Ŀ���빦�ܣ�	ͼ���ࣺ��Բ
// �������ڣ�	2020.9.6
// �޸����ڣ�	2020.9.14
// ���ߣ�		Fan Zhimin
// �޸��ߣ�		Fan Zhimin
// ��ϵ��ʽ��	
//////////////////////////////////////////////////

#include "pch.h"
#include "CMyShapeEllipse.h"

/**************************************************
Name:		CMyShapeEllipse
Inputs:
			CArray<CPoint, CPoint&>&	arrayPoints	���Ƶ�����
			Color						color		ͼ����ɫ
			int							nWidth		ͼ���߿�
Return:
			(none)
Description:
			���캯��
**************************************************/
CMyShapeEllipse::CMyShapeEllipse(CArray<CPoint, CPoint&>& arrayPoints, Color color, int nWidth)
{
	m_nType = MYSHAPE_ELLIPSE;
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
void CMyShapeEllipse::Draw(Graphics& graphicsGDI)
{
	// ������ͼ�û���
	Pen t_penCurrentPen(m_colorColor, m_nWidth);
	// ������Բ
	graphicsGDI.DrawEllipse(&t_penCurrentPen, m_arrayPoints[0].x, m_arrayPoints[0].y, m_arrayPoints[1].x - m_arrayPoints[0].x, m_arrayPoints[1].y - m_arrayPoints[0].y);
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
CString CMyShapeEllipse::GetName()
{
	// �� CString �ĸ�ʽ��������������ʾ�����ַ���
	CString t_strName;
	t_strName.Format(_T("��Բ (%d,%d)-(%d,%d)"), m_arrayPoints[0].x, m_arrayPoints[0].y, m_arrayPoints[1].x , m_arrayPoints[1].y );
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
CMyShape* CMyShapeEllipse::Copy()
{
	CMyShapeEllipse* pNewShape = new CMyShapeEllipse(m_arrayPoints, m_colorColor, m_nWidth);
	return pNewShape;
}