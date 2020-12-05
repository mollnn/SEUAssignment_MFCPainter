//////////////////////////////////////////////////
// 文件名：		CDialogShapeEdit.h
// 版本：		1.0
// 目的与功能：	用于编辑已有图形属性的对话框
// 创建日期：	2020.9.13
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////

#pragma once


// CDialogShapeEdit 对话框

class CDialogShapeEdit : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogShapeEdit)

public:
	// 标准构造函数
	CDialogShapeEdit(CWnd* pParent = nullptr);   
	// 标准析构函数
	virtual ~CDialogShapeEdit();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHAPE_EDIT };
#endif

protected:
	// 数据动态绑定
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	
	DECLARE_MESSAGE_MAP()
public:
	// 指向要 MyShape 临时缓冲的指针
	CMyShape* m_pShape;


	// 对话框初始化消息响应函数
	virtual BOOL OnInitDialog();
	// 确认消息响应函数
	afx_msg void OnBnClickedOk();
	// “修改颜色”按钮单击响应函数
	afx_msg void OnBnClickedButtonChangeColor();
	// 重绘消息响应函数
	afx_msg void OnPaint();
};
