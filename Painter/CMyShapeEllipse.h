//////////////////////////////////////////////////
// �ļ�����		CMyShapeEllipse.h
// �汾��		1.0
// Ŀ���빦�ܣ�	ͼ���ࣺ��Բ
// �������ڣ�	2020.9.6
// �޸����ڣ�	2020.9.14
// ���ߣ�		Fan Zhimin
// �޸��ߣ�		Fan Zhimin
// ��ϵ��ʽ��	
//////////////////////////////////////////////////

#pragma once
class CMyShapeEllipse :
	public CMyShape
{
public:
	// ���캯��
	CMyShapeEllipse(CArray <CPoint, CPoint&>& arrayPoints, Color color, int nWidth);
	// ��ͼ����
	virtual void Draw(Graphics& graphicsGDI);
	// ��ȡ���ƺ���
	virtual CString GetName();
	// ��������
	virtual CMyShape* Copy();
};

