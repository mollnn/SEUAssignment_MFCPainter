//////////////////////////////////////////////////
// 文件名：		CDialogPaintSetting.cpp
// 版本：		1.0
// 目的与功能：	用于设置绘图属性的对话框
// 创建日期：	2020.9.7
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////

// CDialogPaintSetting.cpp: 实现文件
//

#include "pch.h"
#include "CDialogPaintSetting.h"
#include "afxdialogex.h"


// CDialogPaintSetting 对话框

IMPLEMENT_DYNAMIC(CDialogPaintSetting, CDialogEx)

CDialogPaintSetting::CDialogPaintSetting(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PAINT_SETTING, pParent)
{

}

CDialogPaintSetting::~CDialogPaintSetting()
{
}

void CDialogPaintSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogPaintSetting, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_CHANGE_COLOR, &CDialogPaintSetting::OnBnClickedButtonChangeColor)
	ON_BN_CLICKED(IDOK, &CDialogPaintSetting::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialogPaintSetting 消息处理程序

BOOL CDialogPaintSetting::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	// 拷贝一个 ShapeCreator 用于缓存
	m_ShapeCreator.Copy(m_pTargetShapeCreator);

	// 设定 Spin 控件的参数
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN1);
	pSpin->SetRange32(1, 1000);
	pSpin->SetBase(10);

	// 将 ShapeCreator 中已有的参数赋到控件中
	SetDlgItemInt(IDC_EDIT2, m_ShapeCreator.m_nWidth);

	// 设置复选框的初始值
	CButton* pButtonCheckBox = (CButton*)GetDlgItem(IDC_CHECK);
	pButtonCheckBox->SetCheck(m_ShapeCreator.m_bShowSetting);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void CDialogPaintSetting::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()

	// 绘制“画笔颜色”的显示
	CBrush t_brushBrush(RGB(m_ShapeCreator.m_colorColor.GetRed(), m_ShapeCreator.m_colorColor.GetGreen(), m_ShapeCreator.m_colorColor.GetBlue()));
	FillRect(this->GetDC()->GetSafeHdc(), &CRect(90,66,110,85), t_brushBrush);
}

/**************************************************
Name:		OnBnClickedButtonChangeColor
Inputs:
			(none)
Return:
			(none)
Description:
			单击“修改颜色”按钮
**************************************************/
void CDialogPaintSetting::OnBnClickedButtonChangeColor()
{
	// TODO: 在此添加控件通知处理程序代码

	COLORREF t_colorColor = m_ShapeCreator.m_colorColor.ToCOLORREF();  // 颜色对话框的初始颜色 
	CColorDialog t_colordlgDialog(t_colorColor);								// 构造颜色对话框，传入初始颜色值   

	if (IDOK == t_colordlgDialog.DoModal())								// 显示颜色对话框，并判断是否点击了“确定”   
	{
		t_colorColor = t_colordlgDialog.GetColor();							// 获取颜色对话框中选择的颜色值
		m_ShapeCreator.m_colorColor.SetFromCOLORREF(t_colorColor);		// 更新到 ShapeCreator 中

		Invalidate(FALSE);										// 重绘窗口
	}
}

/**************************************************
Name:		OnBnClickedOk
Inputs:
			(none)
Return:
			(none)
Description:
			单击确认按钮
**************************************************/
void CDialogPaintSetting::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	// 从控件中获取参数
	m_ShapeCreator.m_nWidth = GetDlgItemInt(IDC_EDIT2);
	
	// 从复选框获取参数
	CButton* pButtonCheckBox = (CButton*)GetDlgItem(IDC_CHECK);
	m_ShapeCreator.m_bShowSetting = pButtonCheckBox->GetCheck();

	// 拷贝回主程序的 ShapeCreator 中
	m_pTargetShapeCreator->Copy(&m_ShapeCreator);

	CDialogEx::OnOK();
}
