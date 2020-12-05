//////////////////////////////////////////////////
// 文件名：		CPainterListView.cpp
// 版本：		1.0
// 目的与功能：	主程序列表区视类
// 创建日期：	2020.9.6
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
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

	// TODO: 在此添加专用代码和/或调用基类
	
}

BOOL CPainterListView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& t_rectClientRect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类

	return CListView::Create(lpszClassName, lpszWindowName, dwStyle, t_rectClientRect, pParentWnd, nID, pContext);
}

/**************************************************
Name:		UpdateFromDoc
Inputs:
			(none)
Return:
			(none)
Description:
			从 Doc 对象中获取并更新图形列表
**************************************************/
void CPainterListView::UpdateFromDoc()
{
	// TODO: 在此处添加实现代码.

	// 获取文档指针
	CPainterDoc* t_pDoc = GetDocument();
	ASSERT_VALID(t_pDoc);
	if (!t_pDoc)
		return;

	// 准备写入列表
	CListCtrl& t_listCtrl = GetListCtrl();						// 获取 List 控件指针
	t_listCtrl.DeleteAllItems();								// 清空

	CObArray& t_arrayShapes = t_pDoc->m_arrayShapes;			// 获取图形数组引用
	int t_nShapeCount = t_arrayShapes.GetSize();				// 图形数量

	// 遍历所有图形，重新写入列表
	for (int i = 0; i < t_nShapeCount; i++)						
	{
		CMyShape& t_myShape = *((CMyShape*)t_arrayShapes[i]);	// 当前图形的引用

		CString t_strText;										// 用于存储显示名称
		t_strText = t_myShape.GetName();

		t_listCtrl.InsertItem(i, t_strText);					// 添加到列表中
	}
}

BOOL CPainterListView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此添加专用代码和/或调用基类
	cs.style |= LVS_LIST;										// 用 LVS_LIST 风格		
	return CListView::PreCreateWindow(cs);
}

int CPainterListView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	
	return 0;
}

void CPainterListView::OnNMRClick(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	// 提取鼠标指针的位置以及选中的项
	CListCtrl* t_listctrlListCtrl = &GetListCtrl();		// 获取当前列表控件的指针
	CMenu t_menuMenu, * t_pSubMenu;						// 定义下面要用到的 CMenu 对象
	t_menuMenu.LoadMenu(IDR_LISTRMENU);					// 装载自定义的右键菜单
	t_pSubMenu = t_menuMenu.GetSubMenu(0);				// 获取第一个弹出菜单，所以第一个菜单必须有子菜单
	CPoint t_pointMousePosition;						// 定义一个用于确定光标位置的位置
	GetCursorPos(&t_pointMousePosition);				// 获取当前光标的位置，以便使得菜单可以跟随光标
	m_nItemSelectedIndex = pNMItemActivate->iItem;		// 获取选择项的 ID

	// 在指定位置显示弹出菜单
	t_pSubMenu->TrackPopupMenu(TPM_LEFTALIGN, t_pointMousePosition.x, t_pointMousePosition.y, this); 

	*pResult = 0;
}

void CPainterListView::OnSize(UINT t_nType, int cx, int cy)
{
	CListView::OnSize(t_nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	UpdateFromDoc();									// 重写列表
	Invalidate(FALSE);									// 重绘
}


void CPainterListView::OnNMDblclk(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	CPoint t_pointMousePosition;						// 定义一个用于确定光标位置的位置
	GetCursorPos(&t_pointMousePosition);				// 获取当前光标的位置，以便使得菜单可以跟随光标
	m_nItemSelectedIndex = pNMItemActivate->iItem;		// 获取选择项的 ID

	// 获取指向主框架的指针
	CMainFrame* t_pFrameMain = (CMainFrame*)AfxGetMainWnd();

	// 获取文档指针
	CPainterDoc* t_pDoc = GetDocument();
	ASSERT_VALID(t_pDoc);
	if (!t_pDoc)
		return;
	
	if (t_pFrameMain)
	{
		// 获取选择的选项的 ID
		int nId = t_pFrameMain->m_pPainterListView->m_nItemSelectedIndex;

		// 创建设置窗体
		CDialogShapeEdit t_dlgShapeEdit;
		t_dlgShapeEdit.m_pShape = reinterpret_cast<CMyShape*>(t_pDoc->m_arrayShapes[nId])->Copy();
		if (t_dlgShapeEdit.DoModal() == IDOK)
		{
			// 确认，覆盖原有图形
			reinterpret_cast<CMyShape*>(t_pDoc->m_arrayShapes[nId])->Assign(*t_dlgShapeEdit.m_pShape);
		}

		// 释放临时变量内存区域
		delete t_dlgShapeEdit.m_pShape;

		// 更新显示
		t_pFrameMain->m_pPainterListView->UpdateFromDoc();		// 重新写入列表框信息
		// 重绘
		t_pFrameMain->m_pPainterListView->Invalidate(FALSE);
		t_pFrameMain->m_pPainterView->Invalidate(FALSE);
	}

	*pResult = 0;
}
