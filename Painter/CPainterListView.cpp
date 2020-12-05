//////////////////////////////////////////////////
// �ļ�����		CPainterListView.cpp
// �汾��		1.0
// Ŀ���빦�ܣ�	�������б�������
// �������ڣ�	2020.9.6
// �޸����ڣ�	2020.9.14
// ���ߣ�		Fan Zhimin
// �޸��ߣ�		Fan Zhimin
// ��ϵ��ʽ��	
//////////////////////////////////////////////////


#include "pch.h"

IMPLEMENT_DYNCREATE(CPainterListView, CListView)
BEGIN_MESSAGE_MAP(CPainterListView, CListView)
	ON_WM_CREATE()
	ON_NOTIFY_REFLECT(NM_RCLICK, &CPainterListView::OnNMRClick)
	ON_WM_SIZE()
	ON_NOTIFY_REFLECT(NM_DBLCLK, &CPainterListView::OnNMDblclk)
END_MESSAGE_MAP()

CPainterDoc* CPainterListView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPainterDoc)));
	return (CPainterDoc*)m_pDocument;
}

void CPainterListView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	
}

BOOL CPainterListView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& t_rectClientRect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: �ڴ����ר�ô����/����û���

	return CListView::Create(lpszClassName, lpszWindowName, dwStyle, t_rectClientRect, pParentWnd, nID, pContext);
}

/**************************************************
Name:		UpdateFromDoc
Inputs:
			(none)
Return:
			(none)
Description:
			�� Doc �����л�ȡ������ͼ���б�
**************************************************/
void CPainterListView::UpdateFromDoc()
{
	// TODO: �ڴ˴����ʵ�ִ���.

	// ��ȡ�ĵ�ָ��
	CPainterDoc* t_pDoc = GetDocument();
	ASSERT_VALID(t_pDoc);
	if (!t_pDoc)
		return;

	// ׼��д���б�
	CListCtrl& t_listCtrl = GetListCtrl();						// ��ȡ List �ؼ�ָ��
	t_listCtrl.DeleteAllItems();								// ���

	CObArray& t_arrayShapes = t_pDoc->m_arrayShapes;			// ��ȡͼ����������
	int t_nShapeCount = t_arrayShapes.GetSize();				// ͼ������

	// ��������ͼ�Σ�����д���б�
	for (int i = 0; i < t_nShapeCount; i++)						
	{
		CMyShape& t_myShape = *((CMyShape*)t_arrayShapes[i]);	// ��ǰͼ�ε�����

		CString t_strText;										// ���ڴ洢��ʾ����
		t_strText = t_myShape.GetName();

		t_listCtrl.InsertItem(i, t_strText);					// ��ӵ��б���
	}
}

BOOL CPainterListView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ����ר�ô����/����û���
	cs.style |= LVS_LIST;										// �� LVS_LIST ���		
	return CListView::PreCreateWindow(cs);
}

int CPainterListView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	
	return 0;
}

void CPainterListView::OnNMRClick(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	// ��ȡ���ָ���λ���Լ�ѡ�е���
	CListCtrl* t_listctrlListCtrl = &GetListCtrl();		// ��ȡ��ǰ�б�ؼ���ָ��
	CMenu t_menuMenu, * t_pSubMenu;						// ��������Ҫ�õ��� CMenu ����
	t_menuMenu.LoadMenu(IDR_LISTRMENU);					// װ���Զ�����Ҽ��˵�
	t_pSubMenu = t_menuMenu.GetSubMenu(0);				// ��ȡ��һ�������˵������Ե�һ���˵��������Ӳ˵�
	CPoint t_pointMousePosition;						// ����һ������ȷ�����λ�õ�λ��
	GetCursorPos(&t_pointMousePosition);				// ��ȡ��ǰ����λ�ã��Ա�ʹ�ò˵����Ը�����
	m_nItemSelectedIndex = pNMItemActivate->iItem;		// ��ȡѡ����� ID

	// ��ָ��λ����ʾ�����˵�
	t_pSubMenu->TrackPopupMenu(TPM_LEFTALIGN, t_pointMousePosition.x, t_pointMousePosition.y, this); 

	*pResult = 0;
}

void CPainterListView::OnSize(UINT t_nType, int cx, int cy)
{
	CListView::OnSize(t_nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	UpdateFromDoc();									// ��д�б�
	Invalidate(FALSE);									// �ػ�
}


void CPainterListView::OnNMDblclk(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CPoint t_pointMousePosition;						// ����һ������ȷ�����λ�õ�λ��
	GetCursorPos(&t_pointMousePosition);				// ��ȡ��ǰ����λ�ã��Ա�ʹ�ò˵����Ը�����
	m_nItemSelectedIndex = pNMItemActivate->iItem;		// ��ȡѡ����� ID

	// ��ȡָ������ܵ�ָ��
	CMainFrame* t_pFrameMain = (CMainFrame*)AfxGetMainWnd();

	// ��ȡ�ĵ�ָ��
	CPainterDoc* t_pDoc = GetDocument();
	ASSERT_VALID(t_pDoc);
	if (!t_pDoc)
		return;
	
	if (t_pFrameMain)
	{
		// ��ȡѡ���ѡ��� ID
		int nId = t_pFrameMain->m_pPainterListView->m_nItemSelectedIndex;

		// �������ô���
		CDialogShapeEdit t_dlgShapeEdit;
		t_dlgShapeEdit.m_pShape = reinterpret_cast<CMyShape*>(t_pDoc->m_arrayShapes[nId])->Copy();
		if (t_dlgShapeEdit.DoModal() == IDOK)
		{
			// ȷ�ϣ�����ԭ��ͼ��
			reinterpret_cast<CMyShape*>(t_pDoc->m_arrayShapes[nId])->Assign(*t_dlgShapeEdit.m_pShape);
		}

		// �ͷ���ʱ�����ڴ�����
		delete t_dlgShapeEdit.m_pShape;

		// ������ʾ
		t_pFrameMain->m_pPainterListView->UpdateFromDoc();		// ����д���б����Ϣ
		// �ػ�
		t_pFrameMain->m_pPainterListView->Invalidate(FALSE);
		t_pFrameMain->m_pPainterView->Invalidate(FALSE);
	}

	*pResult = 0;
}
