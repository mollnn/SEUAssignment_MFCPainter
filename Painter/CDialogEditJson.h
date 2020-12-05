//////////////////////////////////////////////////
// 文件名：		CDialogEditJson.h
// 版本：		1.0
// 目的与功能：	用于输入/输出 JSON 编码的交互对话框
// 创建日期：	2020.9.13
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////

#pragma once


// CDialogEditJson 对话框

class CDialogEditJson : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogEditJson)

public:
	// 标准构造函数
	CDialogEditJson(CWnd* pParent = nullptr);   
	// 标准析构函数
	virtual ~CDialogEditJson();					

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDITJSON };
#endif

protected:
	// 数据动态绑定
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 文本框输入/输出的 JSON 字符串
	CString m_strJson;


	// 对话框初始化消息响应函数
	virtual BOOL OnInitDialog();
	// 确认消息响应函数
	virtual void OnOK();
};
