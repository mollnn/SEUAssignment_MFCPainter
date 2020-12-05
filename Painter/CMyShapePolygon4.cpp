//////////////////////////////////////////////////
// �ļ�����		CMyShapePolygon4.cpp
// �汾��		1.0
// Ŀ���빦�ܣ�	ͼ���ࣺ����Σ�4�ߣ�
// �������ڣ�	2020.9.6
// �޸����ڣ�	2020.9.14
// ���ߣ�		Fan Zhimin
// �޸��ߣ�		Fan Zhimin
// ��ϵ��ʽ��	
//////////////////////////////////////////////////


#include "pch.h"
#include "CMyShapePolygon4.h"

/**************************************************
Name:		CMyShapePolygon4
Inputs:
			CArray<CPoint, CPoint&>&	arrayPoints	���Ƶ�����
			Color						color		ͼ����ɫ
			int							nWidth		ͼ���߿�
Return:
			(none)
Description:
			���캯��
**************************************************/
CMyShapePolygon4::CMyShapePolygon4(CArray<CPoint, CPoint&>& arrayPoints, Color color, int nWidth) : CMyShapePolygon(arrayPoints, color, nWidth)
{
	m_nType = MYSHAPE_POLYGON4;
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
CString CMyShapePolygon4::GetName()
{
	return CMyShapePolygon::GetName(CString(_T("�ı��� ")));
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
CMyShape* CMyShapePolygon4::Copy()
{
	CMyShapePolygon4* pNewShape = new CMyShapePolygon4(m_arrayPoints, m_colorColor, m_nWidth);
	return pNewShape;
}