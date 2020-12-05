//////////////////////////////////////////////////
// 文件名：		CDialogPaintSetting.h
// 版本：		1.0
// 目的与功能：	用于设置绘图属性的对话框
// 创建日期：	2020.9.7
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////

#pragma once


// CDialogPaintSetting 对话框

class CDialogPaintSetting : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogPaintSetting)

public:
	// 标准构造函数
	CDialogPaintSetting(CWnd* pParent = nullptr);  
	// 标准析构函数
	virtual ~CDialogPaintSetting();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAINT_SETTING };
#endif

protected:
	// 数据动态绑定
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 对话框初始化消息响应函数
	virtual BOOL OnInitDialog();
	// 绘图属性修改的目标 ShapeCreator
	CShapeCreator* m_pTargetShapeCreator;
	// 根据当前对话框中设定构建的缓冲 ShapeCreator
	CShapeCreator m_ShapeCreator;


	// 重绘消息响应函数
	afx_msg void OnPaint();
	// “修改颜色”按钮单击响应函数
	afx_msg void OnBnClickedButtonChangeColor();
	// 确认消息响应函数
	afx_msg void OnBnClickedOk();
};
