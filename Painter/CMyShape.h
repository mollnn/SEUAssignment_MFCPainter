//////////////////////////////////////////////////
// �ļ�����		CMyShape.h
// �汾��		1.0
// Ŀ���빦�ܣ�	ͼ�γ����࣬���о���ͼ�εĻ���
// �������ڣ�	2020.9.6
// �޸����ڣ�	2020.9.14
// ���ߣ�		Fan Zhimin
// �޸��ߣ�		Fan Zhimin
// ��ϵ��ʽ��	
//////////////////////////////////////////////////

#pragma once
class CMyShape : public CObject
{

public:
	// ���Ƶ�
	CArray<CPoint, CPoint&> m_arrayPoints;
	// ����
	int m_nType;
	// ��ϸ
	int m_nWidth;
	// ��ɫ
	Color m_colorColor;

	// ���ƺ��������麯����
	virtual void Draw(Graphics& graphicsGDI)=0;
	// ��ȡ���ƣ��������б�����ʾ
	virtual CString GetName();
	// �������������麯����
	virtual CMyShape* Copy() = 0;
	// ��ֵ����
	virtual void Assign(CMyShape& shapeSrc);
	// �� MyShape ת��Ϊ JsonObject
	CJsonObject ToJson();
	// �� JsonObject ����ͼ��
	void FromJson(CJsonObject jsonobjShape);
};

// ����ͼ�ζ�Ӧ�� ID ���
#define MYSHAPE_POINT		1
#define MYSHAPE_LINE		2
#define MYSHAPE_CIRCLE		3
#define MYSHAPE_ELLIPSE		4
#define MYSHAPE_RECTANGLE	5
#define MYSHAPE_POLYGON		100
#define MYSHAPE_POLYGON3	103
#define MYSHAPE_POLYGON4	104
#define MYSHAPE_POLYGON5	105
#define MYSHAPE_POLYGON6	106