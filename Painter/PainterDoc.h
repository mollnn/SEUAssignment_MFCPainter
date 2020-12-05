//////////////////////////////////////////////////
// 文件名：		CPainterDoc.h
// 版本：		1.0
// 目的与功能：	主程序文档类
// 创建日期：	2020.9.6
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////

// PainterDoc.h: CPainterDoc 类的接口
//


#pragma once


class CPainterDoc : public CDocument
{
protected: // 仅从序列化创建
	CPainterDoc() noexcept;
	DECLARE_DYNCREATE(CPainterDoc)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CPainterDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	// 图形创建状态机
	CShapeCreator m_shpcreatorShapeCreator;
	// 储存当前文档中用户绘制的所有图形
	CObArray m_arrayShapes;
	

	// 响应列表视图右键菜单：从列表视图中删除图形
	afx_msg void OnDeleteItemFromList();
	// 响应列表视图右键菜单：修改已有图形的属性
	afx_msg void OnListRmenuEditpro();
	// 响应列表视图右键菜单：输出 Json 代码
	afx_msg void OnListRmenuTojson();

	// 开始创建新的图形：点
	afx_msg void OnEditCreatePoint();
	// 开始创建新的图形：线
	afx_msg void OnEditCreateLine();
	// 响应命令：设置绘图属性
	afx_msg void OnEditPaintSetting();
	// 响应命令：开始绘制新的圆形
	afx_msg void OnEditCreateCircle();
	// 响应命令：开始绘制新的椭圆
	afx_msg void OnEditCreateEllipse();
	// 响应命令：开始绘制新的三角形
	afx_msg void OnEditCreatePolygon3();
	// 响应命令：开始绘制新的四边形
	afx_msg void OnEditCreatePolygon4();
	// 响应命令：开始绘制新的五边形
	afx_msg void OnEditCreatePolygon5();
	// 响应命令：开始绘制新的六边形
	afx_msg void OnEditCreatePolygon6();
	// 响应命令：开始绘制新的矩形
	afx_msg void OnEditCreateRectangle();
	
	// 响应命令：从 JSON 代码创建一个图形
	afx_msg void OnEditCreateFromjson();
};
