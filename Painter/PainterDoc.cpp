//////////////////////////////////////////////////
// 文件名：		CPainterDoc.cpp
// 版本：		1.0
// 目的与功能：	主程序文档类
// 创建日期：	2020.9.6
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////

// PainterDoc.cpp: CPainterDoc 类的实现
//

#include "pch.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CPainterDoc

IMPLEMENT_DYNCREATE(CPainterDoc, CDocument)

BEGIN_MESSAGE_MAP(CPainterDoc, CDocument)
	ON_COMMAND(ID_LIST_32772, &CPainterDoc::OnDeleteItemFromList)
	ON_COMMAND(ID_EDIT_CREATE_POINT, &CPainterDoc::OnEditCreatePoint)
	ON_COMMAND(ID_EDIT_CREATE_LINE, &CPainterDoc::OnEditCreateLine)
	ON_COMMAND(ID_LIST_RMENU_EDITPRO, &CPainterDoc::OnListRmenuEditpro)
	ON_COMMAND(ID_EDIT_PAINT_SETTING, &CPainterDoc::OnEditPaintSetting)
	ON_COMMAND(ID_EDIT_CREATE_CIRCLE, &CPainterDoc::OnEditCreateCircle)
	ON_COMMAND(ID_EDIT_CREATE_ELLIPSE, &CPainterDoc::OnEditCreateEllipse)
	ON_COMMAND(ID_EDIT_CREATE_POLYGON3, &CPainterDoc::OnEditCreatePolygon3)
	ON_COMMAND(ID_EDIT_CREATE_POLYGON5, &CPainterDoc::OnEditCreatePolygon5)
	ON_COMMAND(ID_EDIT_CREATE_POLYGON6, &CPainterDoc::OnEditCreatePolygon6)
	ON_COMMAND(ID_EDIT_CREATE_RECTANGLE, &CPainterDoc::OnEditCreateRectangle)
	ON_COMMAND(ID_EDIT_CREATE_POLYGON4, &CPainterDoc::OnEditCreatePolygon4)
	ON_COMMAND(ID_LIST_RMENU_TOJSON, &CPainterDoc::OnListRmenuTojson)
	ON_COMMAND(ID_EDIT_CREATE_FROMJSON, &CPainterDoc::OnEditCreateFromjson)
END_MESSAGE_MAP()


// CPainterDoc 构造/析构

CPainterDoc::CPainterDoc() noexcept
{
	// TODO: 在此添加一次性构造代码

}

CPainterDoc::~CPainterDoc()
{
}

BOOL CPainterDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)
	
	// 清空已有的图形
	for (int i = 0; i < m_arrayShapes.GetSize(); i++)
	{
		delete m_arrayShapes[i];	// 释放对象
	}
	m_arrayShapes.RemoveAll();

	// 初始化 ShapeCreator 状态机
	m_shpcreatorShapeCreator.SetTarget(&m_arrayShapes);

	// 更新列表和图形的显示
	CMainFrame* t_pFrameMain = (CMainFrame*)AfxGetMainWnd();
	if (t_pFrameMain)
	{
		// 更新列表信息
		t_pFrameMain->m_pPainterListView->UpdateFromDoc();
		// 重绘
		t_pFrameMain->m_pPainterListView->Invalidate(FALSE);
		t_pFrameMain->m_pPainterView->Invalidate(FALSE);
	}
	

	return TRUE;
}




// CPainterDoc 序列化

void CPainterDoc::Serialize(CArchive& ar)
{
	// 注意我们没有使用默认的序列化，通过手动进行文本读写，来保证存储的文件是文本文件
	if (ar.IsStoring())
	{
		// 储存
		int t_nSize = m_arrayShapes.GetSize();
		CJsonObject t_jsonobjDoc;			// 完整文档对应的 Json 对象
		CJsonObject t_jsonobjShapeArray;	// 图形数组对应的 Json 对象

		// 编码所有的图形
		for (int i = 0; i < t_nSize; i++)
		{
			t_jsonobjShapeArray.Add(((CMyShape*)m_arrayShapes[i])->ToJson());
		}

		// 添加属性
		t_jsonobjDoc.Add("Size", t_nSize);
		t_jsonobjDoc.Add("Array", t_jsonobjShapeArray);

		// 从 std::string 转换为 MFC 类型 CString
		std::string t_strJsonDocStd = t_jsonobjDoc.ToString();
		CStringA t_strJsonDocA;
		t_strJsonDocA = t_strJsonDocStd.c_str();
		CString t_strJsonDoc;
		t_strJsonDoc = t_strJsonDocA;

		// 写入一个字符串，所以实际上相当于文本文件
		ar.WriteString(t_strJsonDoc);
	}
	else
	{
		// 加载
		CString t_strJsonDoc;		// 完整的 Json 代码
		CString t_strTemp;			// 每次读入的临时字符串

		// 读取字符串并合并为一个
		while (ar.ReadString(t_strTemp))
		{
			t_strJsonDoc.Append(t_strTemp);
		}

		// 从 CString 转换为 CJsonObject 支持的类型 std::string
		CStringA t_strJsonDocA;
		t_strJsonDocA = t_strJsonDoc;
		std::string t_strJsonDocStd;
		t_strJsonDocStd = t_strJsonDocA;

		// 解析 Json 代码
		int t_nSize;
		CJsonObject t_jsonobjDoc;				// 完整文档对应的 Json 对象
		t_jsonobjDoc.Parse(t_strJsonDocStd);
		t_jsonobjDoc.Get("Size", t_nSize);
		CJsonObject t_jsonobjShapeArray;		// 图形数组对应的 Json 对象
		t_jsonobjDoc.Get("Array", t_jsonobjShapeArray);

		// 清空原有图形
		for (int i = 0; i < m_arrayShapes.GetSize(); i++)
		{
			delete m_arrayShapes[i];	// 释放对象
		}
		m_arrayShapes.RemoveAll();

		// 遍历并添加所有图形
		for (int i = 0; i < t_nSize; i++)
		{
			CJsonObject t_jsonobjShape = t_jsonobjShapeArray[i];
			m_shpcreatorShapeCreator.CreateFromJson(t_jsonobjShape);
		}

		// 更新列表和图形的显示
		CMainFrame* t_pFrameMain = (CMainFrame*)AfxGetMainWnd();
		if (t_pFrameMain)
		{
			// 更新列表信息
			t_pFrameMain->m_pPainterListView->UpdateFromDoc();
			// 重绘
			t_pFrameMain->m_pPainterListView->Invalidate(FALSE);
			t_pFrameMain->m_pPainterView->Invalidate(FALSE);
		}
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CPainterDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CPainterDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CPainterDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CPainterDoc 诊断

#ifdef _DEBUG
void CPainterDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPainterDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CPainterDoc 命令

/**************************************************
Name:		OnDeleteItemFromList
Inputs:
			(none)
Return:
			(none)
Description:
			响应 ListView 中的右键菜单事件：删除图形
**************************************************/
void CPainterDoc::OnDeleteItemFromList()
{
	// TODO: 在此添加命令处理程序代码

	CMainFrame* t_pFrameMain = (CMainFrame*)AfxGetMainWnd();	// 指向主框架的指针

	if (t_pFrameMain)
	{
		// 从图形数组里删除
		int t_nId = t_pFrameMain->m_pPainterListView->m_nItemSelectedIndex;	// 选中对象的编号
		delete m_arrayShapes[t_nId];		// 先释放对象内存
		m_arrayShapes.RemoveAt(t_nId);		// 从 ObArray 中删除

		// 更新列表和图形的显示
		// 更新列表信息
		t_pFrameMain->m_pPainterListView->UpdateFromDoc();
		// 重绘
		t_pFrameMain->m_pPainterListView->Invalidate(FALSE);
		t_pFrameMain->m_pPainterView->Invalidate(FALSE);
	}
}


/**************************************************
Name:		OnEditCreatePoint
Inputs:
			(none)
Return:
			(none)
Description:
			响应菜单事件：创建新图形：点
**************************************************/
void CPainterDoc::OnEditCreatePoint()
{
	// TODO: 在此添加命令处理程序代码
	m_shpcreatorShapeCreator.SetTarget(&m_arrayShapes);		// 设置目标图形数组
	m_shpcreatorShapeCreator.BeginCreating(MYSHAPE_POINT);	// 发送开始绘制命令
}


/**************************************************
Name:		OnEditCreateLine
Inputs:
			(none)
Return:
			(none)
Description:
			响应菜单事件：创建新图形：线
**************************************************/
void CPainterDoc::OnEditCreateLine()
{
	// TODO: 在此添加命令处理程序代码
	m_shpcreatorShapeCreator.SetTarget(&m_arrayShapes);		// 设置目标图形数组
	m_shpcreatorShapeCreator.BeginCreating(MYSHAPE_LINE);	// 发送开始绘制命令
}


/**************************************************
Name:		OnListRmenuEditpro
Inputs:
			(none)
Return:
			(none)
Description:
			响应 ListView 中的右键菜单事件：编辑图形属性
**************************************************/
void CPainterDoc::OnListRmenuEditpro()
{
	// TODO: 在此添加命令处理程序代码

	// 获取指向主框架的指针
	CMainFrame* t_pFrameMain = (CMainFrame*)AfxGetMainWnd();

	if (t_pFrameMain)
	{
		// 获取选择的选项的 ID
		int t_nId = t_pFrameMain->m_pPainterListView->m_nItemSelectedIndex;	
		
		// 创建设置窗体
		CDialogShapeEdit t_dlgShapeEdit;
		t_dlgShapeEdit.m_pShape = reinterpret_cast<CMyShape*>(m_arrayShapes[t_nId])->Copy();
		if (t_dlgShapeEdit.DoModal() == IDOK)
		{
			// 确认，覆盖原有图形
			reinterpret_cast<CMyShape*>(m_arrayShapes[t_nId])->Assign(*t_dlgShapeEdit.m_pShape);
		}
		
		// 释放临时变量内存区域
		delete t_dlgShapeEdit.m_pShape;

		// 更新显示
		t_pFrameMain->m_pPainterListView->UpdateFromDoc();		// 刷新列表信息
		t_pFrameMain->m_pPainterListView->Invalidate(FALSE);	// 重绘
		t_pFrameMain->m_pPainterView->Invalidate(FALSE);		// 重绘
	}
}


/**************************************************
Name:		OnEditPaintSetting
Inputs:
			(none)
Return:
			(none)
Description:
			响应菜单事件：编辑图形属性
**************************************************/
void CPainterDoc::OnEditPaintSetting()
{
	// TODO: 在此添加命令处理程序代码
	CDialogPaintSetting t_dlgDialogPaintSetting;
	t_dlgDialogPaintSetting.m_pTargetShapeCreator = &m_shpcreatorShapeCreator;
	t_dlgDialogPaintSetting.DoModal();
}


/**************************************************
Name:		OnEditCreateCircle
Inputs:
			(none)
Return:
			(none)
Description:
			响应菜单事件：创建新图形：圆
**************************************************/
void CPainterDoc::OnEditCreateCircle()
{
	// TODO: 在此添加命令处理程序代码
	m_shpcreatorShapeCreator.SetTarget(&m_arrayShapes);		// 设置目标图形数组
	m_shpcreatorShapeCreator.BeginCreating(MYSHAPE_CIRCLE);	// 发送开始绘制命令
}


/**************************************************
Name:		OnEditCreateEllipse
Inputs:
			(none)
Return:
			(none)
Description:
			响应菜单事件：创建新图形：椭圆
**************************************************/
void CPainterDoc::OnEditCreateEllipse()
{
	// TODO: 在此添加命令处理程序代码
	m_shpcreatorShapeCreator.SetTarget(&m_arrayShapes);		// 设置目标图形数组
	m_shpcreatorShapeCreator.BeginCreating(MYSHAPE_ELLIPSE);	// 发送开始绘制命令
}


/**************************************************
Name:		OnEditCreatePolygon3
Inputs:
			(none)
Return:
			(none)
Description:
			响应菜单事件：创建新图形：三角形
**************************************************/
void CPainterDoc::OnEditCreatePolygon3()
{
	// TODO: 在此添加命令处理程序代码
	m_shpcreatorShapeCreator.SetTarget(&m_arrayShapes);		// 设置目标图形数组
	m_shpcreatorShapeCreator.BeginCreating(MYSHAPE_POLYGON3);	// 发送开始绘制命令
}


/**************************************************
Name:		OnEditCreatePolygon5
Inputs:
			(none)
Return:
			(none)
Description:
			响应菜单事件：创建新图形：五边形
**************************************************/
void CPainterDoc::OnEditCreatePolygon5()
{
	// TODO: 在此添加命令处理程序代码
	m_shpcreatorShapeCreator.SetTarget(&m_arrayShapes);		// 设置目标图形数组
	m_shpcreatorShapeCreator.BeginCreating(MYSHAPE_POLYGON5);	// 发送开始绘制命令
}


/**************************************************
Name:		OnEditCreatePolygon6
Inputs:
			(none)
Return:
			(none)
Description:
			响应菜单事件：创建新图形：六边形
**************************************************/
void CPainterDoc::OnEditCreatePolygon6()
{
	// TODO: 在此添加命令处理程序代码
	m_shpcreatorShapeCreator.SetTarget(&m_arrayShapes);		// 设置目标图形数组
	m_shpcreatorShapeCreator.BeginCreating(MYSHAPE_POLYGON6);	// 发送开始绘制命令
}


/**************************************************
Name:		OnEditCreateRectangle
Inputs:
			(none)
Return:
			(none)
Description:
			响应菜单事件：创建新图形：矩形
**************************************************/
void CPainterDoc::OnEditCreateRectangle()
{
	// TODO: 在此添加命令处理程序代码
	m_shpcreatorShapeCreator.SetTarget(&m_arrayShapes);		// 设置目标图形数组
	m_shpcreatorShapeCreator.BeginCreating(MYSHAPE_RECTANGLE);	// 发送开始绘制命令
}


/**************************************************
Name:		OnEditCreatePolygon4
Inputs:
			(none)
Return:
			(none)
Description:
			响应菜单事件：创建新图形：四边形
**************************************************/
void CPainterDoc::OnEditCreatePolygon4()
{
	// TODO: 在此添加命令处理程序代码
	m_shpcreatorShapeCreator.SetTarget(&m_arrayShapes);		// 设置目标图形数组
	m_shpcreatorShapeCreator.BeginCreating(MYSHAPE_POLYGON4);	// 发送开始绘制命令
}


/**************************************************
Name:		OnListRmenuTojson
Inputs:
			(none)
Return:
			(none)
Description:
			响应 ListView 右键菜单事件：转换为 JSON 代码
**************************************************/
void CPainterDoc::OnListRmenuTojson()
{
	// TODO: 在此添加命令处理程序代码
	CMainFrame* t_pFrameMain = (CMainFrame*)AfxGetMainWnd();

	if (t_pFrameMain)
	{
		int t_nId = t_pFrameMain->m_pPainterListView->m_nItemSelectedIndex;				// 选中对象的 ID

		CMyShape* t_pShapeMyShape = reinterpret_cast<CMyShape*> (m_arrayShapes[t_nId]);	// 创建临时指针
		CJsonObject t_jsonobjShape = t_pShapeMyShape->ToJson();	// 编码为 Json 代码字符串

		// 类型转换
		CStringA t_strJsonA = t_jsonobjShape.ToString().c_str();
		CString t_strJson;
		t_strJson = t_strJsonA;

		// 打开对话框，输出 Json 代码
		CDialogEditJson t_dlgEditJson;
		t_dlgEditJson.m_strJson = t_strJson;

		// 弹出模态对话框
		t_dlgEditJson.DoModal();
	}
}


/**************************************************
Name:		OnEditCreateFromjson
Inputs:
			(none)
Return:
			(none)
Description:
			响应菜单事件：从 JSON 创建新图形
**************************************************/
void CPainterDoc::OnEditCreateFromjson()
{
	// TODO: 在此添加命令处理程序代码
	CDialogEditJson t_dlgEditJson;		// 创建对话框
	if (t_dlgEditJson.DoModal() == IDOK)	// 如果按下了确认键
	{
		CString t_strJsonCode = t_dlgEditJson.m_strJson;	// 从文本框中拷贝 Json 代码

		// 字符串类型转换
		CStringA t_strJsonCodeA;
		t_strJsonCodeA = t_strJsonCode;
		std::string t_strJsonCodeStd;
		t_strJsonCodeStd = t_strJsonCodeA;

		// 解析为 Json 对象
		CJsonObject t_jsonobjShape;
		t_jsonobjShape.Parse(t_strJsonCodeStd);

		// 创建图形
		m_shpcreatorShapeCreator.SetTarget(&m_arrayShapes);			// 设置目标数组
		m_shpcreatorShapeCreator.CreateFromJson(t_jsonobjShape);	// 执行创建
	}

	// 更新显示
	CMainFrame* t_pFrameMain = (CMainFrame*)AfxGetMainWnd();
	if (t_pFrameMain)
	{
		// 更新列表信息
		t_pFrameMain->m_pPainterListView->UpdateFromDoc();
		// 重绘
		t_pFrameMain->m_pPainterListView->Invalidate(FALSE);
		t_pFrameMain->m_pPainterView->Invalidate(FALSE);
	}
}
