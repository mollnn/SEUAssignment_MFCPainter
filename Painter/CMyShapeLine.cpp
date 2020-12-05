//////////////////////////////////////////////////
// �ļ�����		CMyShapeLine.cpp
// �汾��		1.0
// Ŀ���빦�ܣ�	ͼ���ֱࣺ��
// �������ڣ�	2020.9.6
// �޸����ڣ�	2020.9.14
// ���ߣ�		Fan Zhimin
// �޸��ߣ�		Fan Zhimin
// ��ϵ��ʽ��	
//////////////////////////////////////////////////

#include "pch.h"
#include "CMyShapeLine.h"

/**************************************************
Name:		CMyShapeLine
Inputs:
			CArray<CPoint, CPoint&>&	arrayPoints	���Ƶ�����
			Color						color		ͼ����ɫ
			int							nWidth		ͼ���߿�
Return:
			(none)
Description:
			���캯��
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
			Graphics& graphicsGDI	����Ŀ�� GDI+ ���������
Return:
			(none)
Description:
			�� GDI+ �����ϻ��Ʊ�ͼ��
**************************************************/
void CMyShapeLine::Draw(Graphics& graphicsGDI)
{
	// ������ͼ�û���
	Pen t_penCurrentPen(m_colorColor, m_nWidth);
	// ����ֱ��
	graphicsGDI.DrawLine(&t_penCurrentPen, m_arrayPoints[0].x, m_arrayPoints[0].y, m_arrayPoints[1].x, m_arrayPoints[1].y);
	
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
CString CMyShapeLine::GetName()
{
	// �� CString �ĸ�ʽ��������������ʾ�����ַ���
	CString t_strName;
	t_strName.Format(_T("�߶� (%d,%d)-(%d,%d)"), 
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
CMyShape* CMyShapeLine::Copy()
{
	CMyShapeLine* pNewShape = new CMyShapeLine(m_arrayPoints, m_colorColor, m_nWidth);
	return pNewShape;
}