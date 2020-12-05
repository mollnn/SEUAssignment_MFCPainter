//////////////////////////////////////////////////
// 文件名：		pch.h
// 版本：		1.0
// 目的与功能：	预编译标头文件
// 创建日期：	2020.9.6
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////


// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件，这将使得性能优势无效。


#ifndef PCH_H
#define PCH_H

#define _CRT_SECURE_NO_WARNINGS

// 添加要在此处预编译的标头
#include "framework.h"

#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")
#include "Resource.h"
#include "CJsonObject.hpp"
using namespace neb;
#include "CShapeCreator.h"
#include "CMyShape.h"
#include "CMyShapePoint.h"
#include "CMyShapeLine.h"
#include "CMyShapeCircle.h"
#include "CMyShapeEllipse.h"
#include "CMyShapeRectangle.h"
#include "CMyShapePolygon.h"
#include "CMyShapePolygon3.h"
#include "CMyShapePolygon4.h"
#include "CMyShapePolygon5.h"
#include "CMyShapePolygon6.h"
#include "Painter.h"
#include "PainterDoc.h"
#include "PainterView.h"
#include "CPainterListView.h"
#include "MainFrm.h"
#include "CDialogShapeEdit.h"
#include "CDialogPaintSetting.h"
#include "CDialogEditJson.h"
#include <afxcontrolbars.h>




#endif //PCH_H
