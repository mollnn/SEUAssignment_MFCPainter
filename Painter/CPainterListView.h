//////////////////////////////////////////////////
// �ļ�����		CPainterListView.h
// �汾��		1.0
// Ŀ���빦�ܣ�	�������б�������
// �������ڣ�	2020.9.6
// �޸����ڣ�	2020.9.14
// ���ߣ�		Fan Zhimin
// �޸��ߣ�		Fan Zhimin
// ��ϵ��ʽ��	
//////////////////////////////////////////////////


#pragma once

class CPainterListView :
	public CListView
{
// ����
public:
	DECLARE_DYNCREATE(CPainterListView)
	// ��ȡָ���Ӧ�ĵ������ָ��
	CPainterDoc* GetDocument() const;
	// ��ͼ������ȫ�������һ������ܵ��õĺ���
	virtual void OnInitialUpdate();
	// ����
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& t_rectClientRect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	// ���ĵ����ͼ�����������¶�ȡ����ͼ�Σ������б�
	void UpdateFromDoc();
	// �ڴ�������֮ǰ����
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);


	// �����б�ѡ�����һ�α�ѡ�е�Ԫ�ص��±�
	int m_nItemSelectedIndex;


	DECLARE_MESSAGE_MAP()
	// ��Ӧ WM_CREATE �¼�
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	// ��Ӧ�б���ѡ��ĳ��Ҽ������¼�����Ҫ�����˵�
	afx_msg void OnNMRClick(NMHDR* pNMHDR, LRESULT* pResult);
	// ��Ӧ��С�仯
	afx_msg void OnSize(UINT t_nType, int cx, int cy);
	afx_msg void OnNMDblclk(NMHDR* pNMHDR, LRESULT* pResult);
};

