//////////////////////////////////////////////////
// 文件名：		CDialogShapeEdit.cpp
// 版本：		1.0
// 目的与功能：	用于编辑已有图形属性的对话框
// 创建日期：	2020.9.13
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////

// CDialogShapeEdit.cpp: 实现文件
//

#include "pch.h"
#include "CDialogShapeEdit.h"
#include "afxdialogex.h"


// CDialogShapeEdit 对话框

IMPLEMENT_DYNAMIC(CDialogShapeEdit, CDialogEx)

CDialogShapeEdit::CDialogShapeEdit(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHAPE_EDIT, pParent)
{

}

CDialogShapeEdit::~CDialogShapeEdit()
{
}

void CDialogShapeEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogShapeEdit, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialogShapeEdit::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE_COLOR, &CDialogShapeEdit::OnBnClickedButtonChangeColor)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDialogShapeEdit 消息处理程序

BOOL CDialogShapeEdit::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	// 设置“画笔宽度”的 Spin 控件的参数
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN1);
	pSpin->SetRange32(1, 1000);
	pSpin->SetBase(10);

	// 设置“画笔宽度”文本框控件的初始值
	SetDlgItemInt(IDC_EDIT2, m_pShape->m_nWidth);

	// 设置“控制点坐标”的 Spin 控件的参数 1 X
	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTX_1);
	pSpin->SetRange32(0, 10000);
	pSpin->SetBase(10);

	// 设置“控制点坐标”的 Spin 控件的参数 2 X
	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTX_2);
	pSpin->SetRange32(0, 10000);
	pSpin->SetBase(10);

	// 设置“控制点坐标”的 Spin 控件的参数 3 X
	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTX_3);
	pSpin->SetRange32(0, 10000);
	pSpin->SetBase(10);

	// 设置“控制点坐标”的 Spin 控件的参数 4 X
	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTX_4);
	pSpin->SetRange32(0, 10000);
	pSpin->SetBase(10);

	// 设置“控制点坐标”的 Spin 控件的参数 5 X
	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTX_5);
	pSpin->SetRange32(0, 10000);
	pSpin->SetBase(10);

	// 设置“控制点坐标”的 Spin 控件的参数 6 X
	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTX_6);
	pSpin->SetRange32(0, 10000);
	pSpin->SetBase(10);

	// 设置“控制点坐标”的 Spin 控件的参数 1 Y
	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTY_1);
	pSpin->SetRange32(0, 10000);
	pSpin->SetBase(10);

	// 设置“控制点坐标”的 Spin 控件的参数 2 Y
	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTY_2);
	pSpin->SetRange32(0, 10000);
	pSpin->SetBase(10);

	// 设置“控制点坐标”的 Spin 控件的参数 3 Y
	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTY_3);
	pSpin->SetRange32(0, 10000);
	pSpin->SetBase(10);

	// 设置“控制点坐标”的 Spin 控件的参数 4 Y
	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTY_4);
	pSpin->SetRange32(0, 10000);
	pSpin->SetBase(10);

	// 设置“控制点坐标”的 Spin 控件的参数 5 Y
	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTY_5);
	pSpin->SetRange32(0, 10000);
	pSpin->SetBase(10);

	// 设置“控制点坐标”的 Spin 控件的参数 6 Y
	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTY_6);
	pSpin->SetRange32(0, 10000);
	pSpin->SetBase(10);

	// 根据实际控制点的个数，决定禁用哪些“控制点坐标”编辑框
	if (m_pShape->m_arrayPoints.GetSize() >= 1)
	{
		// 启用控制点 1 的 EditBox 和 Spin 控件
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTX_1);
		pEdit->EnableWindow(TRUE);
		SetDlgItemInt(IDC_EDIT_POINTX_1, m_pShape->m_arrayPoints[0].x);

		pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTY_1);
		pEdit->EnableWindow(TRUE);
		SetDlgItemInt(IDC_EDIT_POINTY_1, m_pShape->m_arrayPoints[0].y);

		CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTX_1);
		pSpin->EnableWindow(TRUE);

		pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTY_1);
		pSpin->EnableWindow(TRUE);
	}
	else
	{
		// 禁用控制点 1 的 EditBox 和 Spin 控件
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTX_1);
		pEdit->EnableWindow(FALSE);

		pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTY_1);
		pEdit->EnableWindow(FALSE);

		CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTX_1);
		pSpin->EnableWindow(FALSE);

		pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTY_1);
		pSpin->EnableWindow(FALSE);
	}

	if (m_pShape->m_arrayPoints.GetSize() >= 2)
	{
		// 启用控制点 2 的 EditBox 和 Spin 控件
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTX_2);
		pEdit->EnableWindow(TRUE);
		SetDlgItemInt(IDC_EDIT_POINTX_2, m_pShape->m_arrayPoints[1].x);

		pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTY_2);
		pEdit->EnableWindow(TRUE);
		SetDlgItemInt(IDC_EDIT_POINTY_2, m_pShape->m_arrayPoints[1].y);

		CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTX_2);
		pSpin->EnableWindow(TRUE);

		pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTY_2);
		pSpin->EnableWindow(TRUE);
	}
	else
	{
		// 禁用控制点 2 的 EditBox 和 Spin 控件
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTX_2);
		pEdit->EnableWindow(FALSE);

		pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTY_2);
		pEdit->EnableWindow(FALSE);

		CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTX_2);
		pSpin->EnableWindow(FALSE);

		pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTY_2);
		pSpin->EnableWindow(FALSE);
	}

	if (m_pShape->m_arrayPoints.GetSize() >= 3)
	{
		// 启用控制点 3 的 EditBox 和 Spin 控件
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTX_3);
		pEdit->EnableWindow(TRUE);
		SetDlgItemInt(IDC_EDIT_POINTX_3, m_pShape->m_arrayPoints[2].x);

		pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTY_3);
		pEdit->EnableWindow(TRUE);
		SetDlgItemInt(IDC_EDIT_POINTY_3, m_pShape->m_arrayPoints[2].y);

		CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTX_3);
		pSpin->EnableWindow(TRUE);

		pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTY_3);
		pSpin->EnableWindow(TRUE);
	}
	else
	{
		// 禁用控制点 3 的 EditBox 和 Spin 控件
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTX_3);
		pEdit->EnableWindow(FALSE);

		pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTY_3);
		pEdit->EnableWindow(FALSE);

		CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTX_3);
		pSpin->EnableWindow(FALSE);

		pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTY_3);
		pSpin->EnableWindow(FALSE);
	}

	if (m_pShape->m_arrayPoints.GetSize() >= 4)
	{
		// 启用控制点 4 的 EditBox 和 Spin 控件
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTX_4);
		pEdit->EnableWindow(TRUE);
		SetDlgItemInt(IDC_EDIT_POINTX_4, m_pShape->m_arrayPoints[3].x);

		pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTY_4);
		pEdit->EnableWindow(TRUE);
		SetDlgItemInt(IDC_EDIT_POINTY_4, m_pShape->m_arrayPoints[3].y);

		CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTX_4);
		pSpin->EnableWindow(TRUE);

		pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTY_4);
		pSpin->EnableWindow(TRUE);
	}
	else
	{
		// 禁用控制点 4 的 EditBox 和 Spin 控件
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTX_4);
		pEdit->EnableWindow(FALSE);

		pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTY_4);
		pEdit->EnableWindow(FALSE);

		CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTX_4);
		pSpin->EnableWindow(FALSE);

		pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTY_4);
		pSpin->EnableWindow(FALSE);
	}

	if (m_pShape->m_arrayPoints.GetSize() >= 5)
	{
		// 启用控制点 5 的 EditBox 和 Spin 控件
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTX_5);
		pEdit->EnableWindow(TRUE);
		SetDlgItemInt(IDC_EDIT_POINTX_5, m_pShape->m_arrayPoints[4].x);

		pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTY_5);
		pEdit->EnableWindow(TRUE);
		SetDlgItemInt(IDC_EDIT_POINTY_5, m_pShape->m_arrayPoints[4].y);

		CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTX_5);
		pSpin->EnableWindow(TRUE);

		pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTY_5);
		pSpin->EnableWindow(TRUE);
	}
	else
	{
		// 禁用控制点 5 的 EditBox 和 Spin 控件
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTX_5);
		pEdit->EnableWindow(FALSE);

		pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTY_5);
		pEdit->EnableWindow(FALSE);

		CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTX_5);
		pSpin->EnableWindow(FALSE);

		pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTY_5);
		pSpin->EnableWindow(FALSE);
	}

	if (m_pShape->m_arrayPoints.GetSize() >= 6)
	{
		// 启用控制点 6 的 EditBox 和 Spin 控件
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTX_6);
		pEdit->EnableWindow(TRUE);
		SetDlgItemInt(IDC_EDIT_POINTX_6, m_pShape->m_arrayPoints[5].x);

		pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTY_6);
		pEdit->EnableWindow(TRUE);
		SetDlgItemInt(IDC_EDIT_POINTY_6, m_pShape->m_arrayPoints[5].y);

		CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTX_6);
		pSpin->EnableWindow(TRUE);

		pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTY_6);
		pSpin->EnableWindow(TRUE);
	}
	else
	{
		// 禁用控制点 6 的 EditBox 和 Spin 控件
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTX_6);
		pEdit->EnableWindow(FALSE);

		pEdit = (CEdit*)GetDlgItem(IDC_EDIT_POINTY_6);
		pEdit->EnableWindow(FALSE);

		CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTX_6);
		pSpin->EnableWindow(FALSE);

		pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_POINTY_6);
		pSpin->EnableWindow(FALSE);
	}

	// 重绘
	Invalidate(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
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
void CDialogShapeEdit::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();

	// 将控件中的画笔宽度存入 m_pShape
	m_pShape->m_nWidth = GetDlgItemInt(IDC_EDIT2);
	
	// 如果存在第 1 个控制点，则将其存入 m_pShape 的控制点容器中
	if (m_pShape->m_arrayPoints.GetSize() >= 1)
	{
		m_pShape->m_arrayPoints[0].x = GetDlgItemInt(IDC_EDIT_POINTX_1);
		m_pShape->m_arrayPoints[0].y = GetDlgItemInt(IDC_EDIT_POINTY_1);
	}

	// 如果存在第 2 个控制点，则将其存入 m_pShape 的控制点容器中
	if (m_pShape->m_arrayPoints.GetSize() >= 2)
	{
		m_pShape->m_arrayPoints[1].x = GetDlgItemInt(IDC_EDIT_POINTX_2);
		m_pShape->m_arrayPoints[1].y = GetDlgItemInt(IDC_EDIT_POINTY_2);
	}

	// 如果存在第 3 个控制点，则将其存入 m_pShape 的控制点容器中
	if (m_pShape->m_arrayPoints.GetSize() >= 3)
	{
		m_pShape->m_arrayPoints[2].x = GetDlgItemInt(IDC_EDIT_POINTX_3);
		m_pShape->m_arrayPoints[2].y = GetDlgItemInt(IDC_EDIT_POINTY_3);
	}

	// 如果存在第 4 个控制点，则将其存入 m_pShape 的控制点容器中
	if (m_pShape->m_arrayPoints.GetSize() >= 4)
	{
		m_pShape->m_arrayPoints[3].x = GetDlgItemInt(IDC_EDIT_POINTX_4);
		m_pShape->m_arrayPoints[3].y = GetDlgItemInt(IDC_EDIT_POINTY_4);
	}

	// 如果存在第 5 个控制点，则将其存入 m_pShape 的控制点容器中
	if (m_pShape->m_arrayPoints.GetSize() >= 5)
	{
		m_pShape->m_arrayPoints[4].x = GetDlgItemInt(IDC_EDIT_POINTX_5);
		m_pShape->m_arrayPoints[4].y = GetDlgItemInt(IDC_EDIT_POINTY_5);
	}

	// 如果存在第 6 个控制点，则将其存入 m_pShape 的控制点容器中
	if (m_pShape->m_arrayPoints.GetSize() >= 6)
	{
		m_pShape->m_arrayPoints[5].x = GetDlgItemInt(IDC_EDIT_POINTX_6);
		m_pShape->m_arrayPoints[5].y = GetDlgItemInt(IDC_EDIT_POINTY_6);
	}
}

/**************************************************
Name:		OnBnClickedButtonChangeColor
Inputs:
			(none)
Return:
			(none)
Description:
			单击修改颜色按钮
**************************************************/
void CDialogShapeEdit::OnBnClickedButtonChangeColor()
{
	// TODO: 在此添加控件通知处理程序代码

	COLORREF color = m_pShape->m_colorColor.ToCOLORREF();		// 颜色对话框的初始颜色 
	CColorDialog colorDlg(color);								// 构造颜色对话框，传入初始颜色值   

	if (IDOK == colorDlg.DoModal())								// 显示颜色对话框，并判断是否点击了“确定”   
	{
		color = colorDlg.GetColor();							// 获取颜色对话框中选择的颜色值
		m_pShape->m_colorColor.SetFromCOLORREF(color);			// 存回 m_pShape 中

		Invalidate(FALSE);										// 重绘
	}
}

void CDialogShapeEdit::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()

	// 绘制“画笔颜色”的显示
	CBrush t_brushBrush(RGB(m_pShape->m_colorColor.GetRed(), m_pShape->m_colorColor.GetGreen(), m_pShape->m_colorColor.GetBlue()));
	FillRect(this->GetDC()->GetSafeHdc(), &CRect(90, 66, 110, 85), t_brushBrush);
}
