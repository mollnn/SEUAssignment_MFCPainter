//////////////////////////////////////////////////
// �ļ�����		CMyShapeCircle.cpp
// �汾��		1.0
// Ŀ���빦�ܣ�	ͼ���ࣺԲ��
// �������ڣ�	2020.9.6
// �޸����ڣ�	2020.9.14
// ���ߣ�		Fan Zhimin
// �޸��ߣ�		Fan Zhimin
// ��ϵ��ʽ��	
//////////////////////////////////////////////////

#include "pch.h"
#include "CMyShapeCircle.h"

/**************************************************
Name:		CMyShapeCircle
Inputs:
			CArray<CPoint, CPoint&>&	arrayPoints	���Ƶ�����
			Color						color		ͼ����ɫ
			int							nWidth		ͼ���߿�
Return:
			(none)
Description:
			���캯��
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
			Graphics& graphicsGDI	����Ŀ�� GDI+ ���������
Return:
			(none)
Description:
			�� GDI+ �����ϻ��Ʊ�ͼ��
**************************************************/
void CMyShapeCircle::Draw(Graphics& graphicsGDI)
{
	// ������ͼ�û���
	Pen t_penCurrentPen(m_colorColor, m_nWidth);
	double radius = sqrt(pow(m_arrayPoints[0].x - m_arrayPoints[1].x, 2) + pow(m_arrayPoints[0].y - m_arrayPoints[1].y, 2));	// ����Բ�εİ뾶
	// ������Բ
	graphicsGDI.DrawEllipse(&t_penCurrentPen, (Gdiplus::REAL)(m_arrayPoints[0].x - radius), m_arrayPoints[0].y - radius, 2 * radius, 2 * radius);
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
CString CMyShapeCircle::GetName()
{
	// �� CString �ĸ�ʽ��������������ʾ�����ַ���
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
			(CMyShape*)		�������¶����ָ��
Description:
			������ͼ�ε�һ�ݿ�����������ָ������ָ��
**************************************************/
CMyShape* CMyShapeCircle::Copy()
{
	CMyShapeCircle* pNewShape = new CMyShapeCircle(m_arrayPoints, m_colorColor, m_nWidth);
	return pNewShape;
}