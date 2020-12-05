//////////////////////////////////////////////////
// �ļ�����		CMyShapePolygon.h
// �汾��		1.0
// Ŀ���빦�ܣ�	ͼ���ࣺ����Σ����о������εĻ��ࣩ
// �������ڣ�	2020.9.6
// �޸����ڣ�	2020.9.14
// ���ߣ�		Fan Zhimin
// �޸��ߣ�		Fan Zhimin
// ��ϵ��ʽ��	
//////////////////////////////////////////////////

#pragma once
class CMyShapePolygon :
	public CMyShape
{
public:
	// ���캯��
	CMyShapePolygon(CArray <CPoint, CPoint&>& arrayPoints, Color color, int nWidth);
	// ��ͼ����
	virtual void Draw(Graphics& graphicsGDI);
	// ��ȡ���ƺ���
	virtual CString GetName(CString strPrefix);
	// ��������
	virtual CMyShape* Copy();
};
