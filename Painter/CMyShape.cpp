//////////////////////////////////////////////////
// �ļ�����		CMyShape.cpp
// �汾��		1.0
// Ŀ���빦�ܣ�	ͼ�γ����࣬���о���ͼ�εĻ���
// �������ڣ�	2020.9.6
// �޸����ڣ�	2020.9.14
// ���ߣ�		Fan Zhimin
// �޸��ߣ�		Fan Zhimin
// ��ϵ��ʽ��	
//////////////////////////////////////////////////

#include "pch.h"

/**************************************************
Name:		GetName
Inputs:
			(none)
Return:
			(CString)		����ʾ�������ַ���	
Description:
			��ȡ���ƣ����� ListView ��ʾ
**************************************************/
CString CMyShape::GetName()
{
	CString t_strName;
	t_strName = _T("δ��������");
	return t_strName;
}

/**************************************************
Name:		Assign
Inputs:
			CMyShape& shapeSrc		����ֵ��Դͼ������
Return:
			(none)
Description:
			��ֵ�������� shapeSrc ��ֵ�� *this
**************************************************/
void CMyShape::Assign(CMyShape& shapeSrc)
{
	m_arrayPoints.Copy(shapeSrc.m_arrayPoints);
	m_colorColor = shapeSrc.m_colorColor;
	m_nType = shapeSrc.m_nType;
	m_nWidth = shapeSrc.m_nWidth;
}



/**************************************************
Name:		ToJson
Inputs:
			(none)
Return:
			(CJsonObject)		ת����� CJsonObject
Description:
			�� *this ͼ��ת��Ϊ CJsonObject ����
**************************************************/
CJsonObject CMyShape::ToJson()
{
	// TODO: �ڴ˴����ʵ�ִ���.

	CJsonObject jsonobjResult;		// ת�����
	CJsonObject jsonobjColor;		// ��ɫ����
	CJsonObject jsonobjPointArray;	// ���Ƶ�����

	// ��ɫ����
	jsonobjColor.Add("Red", m_colorColor.GetRed());
	jsonobjColor.Add("Green", m_colorColor.GetGreen());
	jsonobjColor.Add("Blue", m_colorColor.GetBlue());

	// ���Ƶ�����
	for (int i = 0; i < m_arrayPoints.GetSize(); i++)
	{
		CJsonObject t_jsonobjPoint;		// ���Ƶ����
		t_jsonobjPoint.Add("x", m_arrayPoints[i].x);
		t_jsonobjPoint.Add("y", m_arrayPoints[i].y);
		jsonobjPointArray.Add(t_jsonobjPoint);		// ��������
	}
	
	// �ϲ��õ�ͼ�ζ���
	jsonobjResult.Add("Type", m_nType);
	jsonobjResult.Add("Width", m_nWidth);
	jsonobjResult.Add("Color", jsonobjColor);
	jsonobjResult.Add("Points", jsonobjPointArray);

	return jsonobjResult;
}

/**************************************************
Name:		FromJson
Inputs:
			CJsonObject jsonobjShape	Ҫת���� CJsonObject ����
Return:
			(none)
Description:
			��һ�� CJsonObject ����ת��Ϊ CMyShape ���Ͳ���ֵ�� *this
**************************************************/
void CMyShape::FromJson(CJsonObject jsonobjShape)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	CJsonObject jsonobjColor;		// ��ɫ����	
	CJsonObject jsonobjPointArray;	// ���Ƶ�����

	// ��ͼ�ζ�������ȡ
	jsonobjShape.Get("Type", m_nType);					// ��ȡ����
	jsonobjShape.Get("Width", m_nWidth);				// ��ȡ�߿�
	jsonobjShape.Get("Color", jsonobjColor);			// ��ȡ��ɫ����
	jsonobjShape.Get("Points", jsonobjPointArray);		// ��ȡ���Ƶ�����

	// ����ɫ��������ȡ��ɫ
	int t_nColorRed, t_nColorGreen, t_nColorBlue;		// ��ɫ����
	jsonobjColor.Get("Red", t_nColorRed);
	jsonobjColor.Get("Green", t_nColorGreen);
	jsonobjColor.Get("Blue", t_nColorBlue);
	m_colorColor = Color(t_nColorRed, t_nColorGreen, t_nColorBlue);	

	// �ӿ��Ƶ������������ȡ���Ƶ�
	m_arrayPoints.RemoveAll();
	// �������еĿ��Ƶ�
	int t_nSize = jsonobjPointArray.GetArraySize();			// �����С
	for (int i = 0; i < t_nSize; i++)
	{
		CJsonObject jsonobjPoint = jsonobjPointArray[i];	// ���Ƶ����
		int t_nPointX, t_nPointY;		// ���Ƶ������
		jsonobjPoint.Get("x", t_nPointX);
		jsonobjPoint.Get("y", t_nPointY);
		m_arrayPoints.Add(CPoint(t_nPointX, t_nPointY));
	}
}
