//////////////////////////////////////////////////
// �ļ�����		CMyShapePolygon.cpp
// �汾��		1.0
// Ŀ���빦�ܣ�	ͼ���ࣺ����Σ����о������εĻ��ࣩ
// �������ڣ�	2020.9.6
// �޸����ڣ�	2020.9.14
// ���ߣ�		Fan Zhimin
// �޸��ߣ�		Fan Zhimin
// ��ϵ��ʽ��	
//////////////////////////////////////////////////


#include "pch.h"
#include "CMyShapePolygon.h"

/**************************************************
Name:		CMyShapePolygon
Inputs:
			CArray<CPoint, CPoint&>&	arrayPoints	���Ƶ�����
			Color						color		ͼ����ɫ
			int							nWidth		ͼ���߿�
Return:
			(none)
Description:
			���캯��
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
			Graphics& graphicsGDI	����Ŀ�� GDI+ ���������
Return:
			(none)
Description:
			�� GDI+ �����ϻ��Ʊ�ͼ��
**************************************************/
void CMyShapePolygon::Draw(Graphics& graphicsGDI)
{
	// ������ͼ�û���
	Pen t_penCurrentPen(m_colorColor, m_nWidth);
	// ���ƶ���ε����б�
	for (int i = 1; i < m_arrayPoints.GetSize(); i++)
	{
		graphicsGDI.DrawLine(&t_penCurrentPen, m_arrayPoints[i - 1].x, m_arrayPoints[i - 1].y, m_arrayPoints[i].x, m_arrayPoints[i].y);
	}
	graphicsGDI.DrawLine(&t_penCurrentPen, m_arrayPoints[0].x, m_arrayPoints[0].y, m_arrayPoints[m_arrayPoints.GetSize() - 1].x, m_arrayPoints[m_arrayPoints.GetSize() - 1].y);
	
	// �������������ڶ��㴦��һ��ʵ��Բ����ʵ��ƽ����ĩ��
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
			(CString)	���ص���ʾ����
Description:
			��ȡͼ�ε���ʾ����
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
			(CMyShape*)		�������¶����ָ��
Description:
			������ͼ�ε�һ�ݿ�����������ָ������ָ��
**************************************************/
CMyShape* CMyShapePolygon::Copy()
{
	CMyShapePolygon* pNewShape = new CMyShapePolygon(m_arrayPoints, m_colorColor, m_nWidth);
	return pNewShape;
}