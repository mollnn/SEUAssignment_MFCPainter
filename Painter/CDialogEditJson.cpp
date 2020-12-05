//////////////////////////////////////////////////
// 文件名：		CDialogEditJson.cpp
// 版本：		1.0
// 目的与功能：	用于输入/输出 JSON 编码的交互对话框
// 创建日期：	2020.9.13
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////

// CDialogEditJson.cpp: 实现文件
//

#include "pch.h"
#include "CDialogEditJson.h"
#include "afxdialogex.h"


// CDialogEditJson 对话框

IMPLEMENT_DYNAMIC(CDialogEditJson, CDialogEx)


CDialogEditJson::CDialogEditJson(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EDITJSON, pParent)
{

}

CDialogEditJson::~CDialogEditJson()
{
}

void CDialogEditJson::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogEditJson, CDialogEx)
END_MESSAGE_MAP()


// CDialogEditJson 消息处理程序

BOOL CDialogEditJson::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	// 将成员变量中的数据赋到窗体控件中
	SetDlgItemText(IDC_EDIT_JSON, m_strJson);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

/**************************************************
Name:		OnOK
Inputs:
			(none)
Return:		
			(none)
Description:
			单击确认按钮
**************************************************/
void CDialogEditJson::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	// 将窗体控件中的数据赋到成员变量中
	GetDlgItemText(IDC_EDIT_JSON, m_strJson);

	CDialogEx::OnOK();
}
