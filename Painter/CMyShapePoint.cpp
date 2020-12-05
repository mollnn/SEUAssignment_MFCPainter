//////////////////////////////////////////////////
// �ļ�����		CMyShapePoint.cpp
// �汾��		1.0
// Ŀ���빦�ܣ�	ͼ���ࣺ��
// �������ڣ�	2020.9.6
// �޸����ڣ�	2020.9.14
// ���ߣ�		Fan Zhimin
// �޸��ߣ�		Fan Zhimin
// ��ϵ��ʽ��	
//////////////////////////////////////////////////


#include "pch.h"

/**************************************************
Name:		CMyShapePoint
Inputs:
			CArray<CPoint, CPoint&>&	arrayPoints	���Ƶ�����
			Color						color		ͼ����ɫ
			int							nWidth		ͼ���߿�
Return:
			(none)
Description:
			���캯��
**************************************************/
CMyShapePoint::CMyShapePoint(CArray<CPoint, CPoint&>& arrayPoints, Color color, int nWidth)
{
	m_nType = MYSHAPE_POINT;
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
void CMyShapePoint::Draw(Graphics& graphicsGDI)
{
	// ���㴦��һ��ʵ��Բ��
	SolidBrush t_brushCurrentSolidBrush(m_colorColor);
	graphicsGDI.FillEllipse(&t_brushCurrentSolidBrush, 1.0f * m_arrayPoints[0].x - 0.5f * m_nWidth, 1.0f * m_arrayPoints[0].y - 0.5f * m_nWidth, 1.0f * m_nWidth + 1, 1.0f * m_nWidth + 1);
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
CString CMyShapePoint::GetName()
{
	// �� CString �ĸ�ʽ��������������ʾ�����ַ���
	CString t_strName;
	t_strName.Format(_T("�� (%d,%d)"), m_arrayPoints[0].x, m_arrayPoints[0].y);
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
CMyShape* CMyShapePoint::Copy()
{
	CMyShapePoint* pNewShape = new CMyShapePoint(m_arrayPoints, m_colorColor, m_nWidth);
	return pNewShape;
}