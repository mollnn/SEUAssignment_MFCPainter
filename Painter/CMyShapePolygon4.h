//////////////////////////////////////////////////
// �ļ�����		CMyShapePolygon4.h
// �汾��		1.0
// Ŀ���빦�ܣ�	ͼ���ࣺ����Σ�4�ߣ�
// �������ڣ�	2020.9.6
// �޸����ڣ�	2020.9.14
// ���ߣ�		Fan Zhimin
// �޸��ߣ�		Fan Zhimin
// ��ϵ��ʽ��	
//////////////////////////////////////////////////

#pragma once
class CMyShapePolygon4 :
	public CMyShapePolygon
{
public:
	// ���캯��
	CMyShapePolygon4(CArray <CPoint, CPoint&>& arrayPoints, Color color, int nWidth);
	// ��ͼ����
	virtual CString GetName();
	// ��ȡ���ƺ���
	// ��������
	virtual CMyShape* Copy();
};

