//////////////////////////////////////////////////
// �ļ�����		CShapeCreator.h
// �汾��		1.0
// Ŀ���빦�ܣ�	ͼ�δ�������һ��״̬����
// �������ڣ�	2020.9.6
// �޸����ڣ�	2020.9.14
// ���ߣ�		Fan Zhimin
// �޸��ߣ�		Fan Zhimin
// ��ϵ��ʽ��	
//////////////////////////////////////////////////


#pragma once

// ����ͼ�δ�����״̬����
class CShapeCreator
{
public:
	// ��׼���캯��
	CShapeCreator();


	// ��־λ�������Ƿ����ڴ���ͼ��
	bool m_bIsCreating;
	// ���ڴ�����ͼ�ε����ͣ�ȡֵ�� CMyShape.h �еĶ���
	int m_nType;
	// ���ڴ�����ͼ���Ѿ���ɵĲ�����
	int m_nSteps;
	// ���ڴ�����ͼ���Ѿ�����Ŀ��Ƶ�����
	CArray<CPoint, CPoint&> m_arrayPoints;
	// ָ��Ŀ��ͼ�������ָ�룬������ɺ�״̬���Ὣ��ͼ�β��뵽��ָ��ָ���������
	CObArray* m_pObArray;
	// ���ڴ�����ͼ�ε���ɫ
	Color m_colorColor;
	// ���ڴ�����ͼ�ε��߿�
	int m_nWidth;
	// �½�ͼ��ʱ�Զ��������öԻ���
	bool m_bShowSetting;


	
	// �趨Ŀ��ͼ�������ָ��
	void SetTarget(CObArray* pObArrayTarget);
	// ���Ϳ�ʼ���������Ҫָ��Ҫ����ͼ�ε����
	void BeginCreating(int t_nType);
	// ���һ���µĿ��Ƶ�
	void PushPoint(CPoint pointNewPoint);
	// ״̬����������
	void Copy(CShapeCreator* pSrcShapeCreator);
	// �� JsonObject ����һ��ͼ�Σ�ע���ⲻ��Ӱ��״̬����״̬
	void CreateFromJson(CJsonObject jsonobjShape);
};

