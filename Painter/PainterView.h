//////////////////////////////////////////////////
// 文件名：		CPainterView.h
// 版本：		1.0
// 目的与功能：	主程序绘图区视类
// 创建日期：	2020.9.6
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////

// PainterView.h: CPainterView 类的接口
//

#pragma once


class CPainterView : public CView
{
protected: // 仅从序列化创建
	CPainterView() noexcept;
	DECLARE_DYNCREATE(CPainterView)

// 特性
public:
	CPainterDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* t_pClientDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* t_pClientDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* t_pClientDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CPainterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	// 响应背景擦除消息，为了防止重绘时 ListView 被遮挡
	afx_msg BOOL OnEraseBkgnd(CDC* t_pClientDC);
	// 响应尺寸变化消息
	afx_msg void OnSize(UINT t_nType, int cx, int cy);
	// 响应左键弹起消息，需要往 ShapeCreator 状态机中添加新的控制点
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // PainterView.cpp 中的调试版本
inline CPainterDoc* CPainterView::GetDocument() const
   { return reinterpret_cast<CPainterDoc*>(m_pDocument); }
#endif

