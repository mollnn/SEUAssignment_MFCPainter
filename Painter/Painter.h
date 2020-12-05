//////////////////////////////////////////////////
// 文件名：		Painter.h
// 版本：		1.0
// 目的与功能：	应用程序主头文件
// 创建日期：	2020.9.6
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////

// Painter.h: Painter 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// CPainterApp:
// 有关此类的实现，请参阅 Painter.cpp
//

class CPainterApp : public CWinAppEx
{
public:
	CPainterApp() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	ULONG_PTR   gdiplusToken;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPainterApp theApp;
