//////////////////////////////////////////////////
// �ļ�����		CMyShapePolygon6.h
// �汾��		1.0
// Ŀ���빦�ܣ�	ͼ���ࣺ����Σ�6�ߣ�
// �������ڣ�	2020.9.6
// �޸����ڣ�	2020.9.14
// ���ߣ�		Fan Zhimin
// �޸��ߣ�		Fan Zhimin
// ��ϵ��ʽ��	
//////////////////////////////////////////////////

#pragma once
class CMyShapePolygon6 :
	public CMyShapePolygon
{
public:
	// ���캯��
	CMyShapePolygon6(CArray <CPoint, CPoint&>& arrayPoints, Color color, int nWidth);
	// ��ȡ���ƺ���
	virtual CString GetName();
	// ��������
	virtual CMyShape* Copy();
};

