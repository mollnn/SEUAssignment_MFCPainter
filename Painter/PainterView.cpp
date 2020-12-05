//////////////////////////////////////////////////
// 文件名：		CPainterView.cpp
// 版本：		1.0
// 目的与功能：	主程序绘图区视类
// 创建日期：	2020.9.6
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////

// PainterView.cpp: CPainterView 类的实现
//

#include "pch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPainterView

IMPLEMENT_DYNCREATE(CPainterView, CView)

BEGIN_MESSAGE_MAP(CPainterView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPainterView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CPainterView 构造/析构


CPainterView::CPainterView() noexcept
{
	// TODO: 在此处添加构造代码

}

CPainterView::~CPainterView()
{
}

BOOL CPainterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CPainterView 绘图

void CPainterView::OnDraw(CDC* /*t_pClientDC*/)
{
	// 获取指向文档的指针
	CPainterDoc* t_pDoc = GetDocument();
	ASSERT_VALID(t_pDoc);
	if (!t_pDoc)
		return;

	// 双缓冲绘图
	CDC t_dcMemDC;										// 内存缓冲区 DC
	CBitmap t_bmpMemBitmap;								// 内存缓冲区位图对象
	CDC* t_pClientDC = GetDC();							// 客户区 DC 指针
	
	CRect t_rectClientRect;								// 客户区矩形
	GetClientRect(&t_rectClientRect);					// 获取客户区矩形

	CObArray& t_arrayShapes = t_pDoc->m_arrayShapes;	// 图形数组指针
	int t_nShapeCount = t_arrayShapes.GetSize();		// 图形数量

	t_dcMemDC.CreateCompatibleDC(t_pClientDC);																	// 创建与目标 DC 相兼容的内存 DC
	t_bmpMemBitmap.CreateCompatibleBitmap(t_pClientDC, t_rectClientRect.Width(), t_rectClientRect.Height());	// 根据目标 DC 创建位图
	t_dcMemDC.SelectObject(&t_bmpMemBitmap);																	// 把位图选入内存 DC

	if (t_nShapeCount == 0 && t_pDoc->m_shpcreatorShapeCreator.m_bIsCreating == 0)	// 没有图形，跳过绘图步骤
	{
		t_pClientDC->FillRect(t_rectClientRect, &CBrush(RGB(255, 255, 255)));
	}
	else		
	{
		// 配置 GDI+
		Graphics t_graphicsGDI(t_dcMemDC.m_hDC);							// 创建 GDI+ 对象
		t_graphicsGDI.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);	// 抗锯齿设置：高质量

		// 绘制背景
		SolidBrush t_brushBackground(Color(255, 255, 255));		// 创建背景色画刷
		t_graphicsGDI.FillRectangle(&t_brushBackground, t_rectClientRect.left, t_rectClientRect.top, t_rectClientRect.right, t_rectClientRect.bottom);	// 绘制背景色
		
		// 遍历并绘制所有已完成的图形
		for (int i = 0; i < t_nShapeCount; i++)
		{
			CMyShape& t_myShape = *((CMyShape*)t_arrayShapes[i]);	// 图形引用
			t_myShape.Draw(t_graphicsGDI);							// 调用虚函数绘制图形
		}

		// 绘制临时控制点
		if (t_pDoc->m_shpcreatorShapeCreator.m_bIsCreating)		// 如果处在创建状态，则需要绘制控制点
		{
			Pen t_penCtrlPoint(Color(0, 0, 255), 1);			// 用于绘制控制点的红色画笔
			// 遍历 ShapeCreator 中的所有控制点
			for (int i = 0; i < t_pDoc->m_shpcreatorShapeCreator.m_arrayPoints.GetSize(); i++)
			{
				// 创建当前控制点的临时拷贝
				CPoint t_pointCtrlPoint = t_pDoc->m_shpcreatorShapeCreator.m_arrayPoints[i];
				// 绘制控制点，实际上是 3*3 的小矩形
				t_graphicsGDI.DrawRectangle(&t_penCtrlPoint, t_pointCtrlPoint.x, t_pointCtrlPoint.y, 3, 3);
			}
		}

		// 利用 BitBlt 方法，将内存中的图形拷贝到客户区 DC 上
		t_pClientDC->BitBlt(t_rectClientRect.left, t_rectClientRect.top, t_rectClientRect.Width(), t_rectClientRect.Height(), &t_dcMemDC, 0, 0, SRCCOPY);
	}
	
	// 释放资源
	t_bmpMemBitmap.DeleteObject();
	t_dcMemDC.DeleteDC();
}


// CPainterView 打印

void CPainterView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPainterView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CPainterView::OnBeginPrinting(CDC* /*t_pClientDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CPainterView::OnEndPrinting(CDC* /*t_pClientDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CPainterView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPainterView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPainterView 诊断

#ifdef _DEBUG
void CPainterView::AssertValid() const
{
	CView::AssertValid();
}

void CPainterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPainterDoc* CPainterView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPainterDoc)));
	return (CPainterDoc*)m_pDocument;
}
#endif //_DEBUG


// CPainterView 消息处理程序

BOOL CPainterView::OnEraseBkgnd(CDC* t_pClientDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	return CView::OnEraseBkgnd(t_pClientDC);
}

void CPainterView::OnSize(UINT t_nType, int cx, int cy)
{
	CView::OnSize(t_nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	Invalidate(FALSE);	// 重绘
}

void CPainterView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// 获取文档指针
	CPainterDoc* t_pDoc = GetDocument();
	ASSERT_VALID(t_pDoc);
	if (!t_pDoc)
		return;

	if (t_pDoc->m_shpcreatorShapeCreator.m_bIsCreating)	// 如果处在创建状态
	{
		t_pDoc->m_shpcreatorShapeCreator.PushPoint(point);	// 则插入新的控制点
	}
	
	Invalidate(FALSE);	// 重绘
	CView::OnLButtonUp(nFlags, point);
}
