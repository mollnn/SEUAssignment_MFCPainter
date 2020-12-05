//////////////////////////////////////////////////
// 文件名：		CPainterListView.h
// 版本：		1.0
// 目的与功能：	主程序列表区视类
// 创建日期：	2020.9.6
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////


#pragma once

class CPainterListView :
	public CListView
{
// 特性
public:
	DECLARE_DYNCREATE(CPainterListView)
	// 获取指向对应文档对象的指针
	CPainterDoc* GetDocument() const;
	// 视图窗口完全建立后第一个被框架调用的函数
	virtual void OnInitialUpdate();
	// 创建
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& t_rectClientRect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	// 从文档类的图形数组中重新读取所有图形，绘制列表
	void UpdateFromDoc();
	// 在创建窗口之前调用
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);


	// 用于列表选择，最后一次被选中的元素的下标
	int m_nItemSelectedIndex;


	DECLARE_MESSAGE_MAP()
	// 响应 WM_CREATE 事件
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	// 响应列表中选中某项并右键单击事件，需要弹出菜单
	afx_msg void OnNMRClick(NMHDR* pNMHDR, LRESULT* pResult);
	// 响应大小变化
	afx_msg void OnSize(UINT t_nType, int cx, int cy);
	afx_msg void OnNMDblclk(NMHDR* pNMHDR, LRESULT* pResult);
};

