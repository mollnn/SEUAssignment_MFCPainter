//////////////////////////////////////////////////
// 文件名：		CShapeCreator.cpp
// 版本：		1.0
// 目的与功能：	图形创建器（一个状态机）
// 创建日期：	2020.9.6
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////


#include "pch.h"
#include "CShapeCreator.h"

CShapeCreator::CShapeCreator()
{
	m_colorColor = Color(0, 0, 0);	// 设定初始颜色
	m_nWidth = 1;					// 设定初始线宽
	m_nSteps = 0;					// 步数归零
	m_nType = 0;					// 初始类型为空
	m_bIsCreating = 0;				// 初态下不在创建状态中
	m_bShowSetting = 1;				// 初态下自动弹出设置窗体
	m_pObArray = NULL;
}

/**************************************************
Name:		SetTarget
Inputs:
			CObArray* pObArrayTarget	指向目标数组的指针
Return:
			(none)
Description:
			设置 ShapeCreator 要将创建出的图形存放到何处
**************************************************/
void CShapeCreator::SetTarget(CObArray* pObArrayTarget)
{
	m_pObArray = pObArrayTarget;	// 设定目标数组
}

/**************************************************
Name:		BeginCreating
Inputs:
			int t_nType					待创建图形的类型
Return:
			(none)
Description:
			对状态机下达指令，开始创建一个新的指定种类的图形
**************************************************/
void CShapeCreator::BeginCreating(int t_nType)
{
	if (m_bShowSetting)		// 如果要每次创建时都弹出设置
	{
		CDialogPaintSetting t_dlgPaintSetting;				// 设置对话框
		t_dlgPaintSetting.m_pTargetShapeCreator = this;		// 设定数据的存储目标
		t_dlgPaintSetting.DoModal();						// 显示模态对话框
	}
	m_bIsCreating = TRUE;		// 设置创建状态
	m_nType = t_nType;			// 设置图形类型
	m_nSteps = 0;				// 步骤计数归位

	m_arrayPoints.RemoveAll();	// 清空控制点数组
}

/**************************************************
Name:		PushPoint
Inputs:
			CPoint pointNewPoint		待插入的控制点
Return:
			(none)
Description:
			对正在创建的图形，插入一个新的控制点
**************************************************/
void CShapeCreator::PushPoint(CPoint pointNewPoint)
{
	++m_nSteps;							// 控制点数量递增
	m_arrayPoints.Add(pointNewPoint);	// 压入控制点

	// 判断图形是否已经创建完成，如果完成，则将图形压入目标数组中
	switch (m_nType)
	{
	case MYSHAPE_POINT:
		// 新建点
		if (m_nSteps == 1)
		{
			m_pObArray->Add(new CMyShapePoint(m_arrayPoints, m_colorColor, m_nWidth));
			m_bIsCreating = FALSE;		// 结束创建过程
		}
		break;
	case MYSHAPE_LINE:
		// 新建线
		if (m_nSteps == 2)
		{
			m_pObArray->Add(new CMyShapeLine(m_arrayPoints, m_colorColor, m_nWidth));
			m_bIsCreating = FALSE;		// 结束创建过程
		}
		break;
	case MYSHAPE_CIRCLE:
		// 新建圆形
		if (m_nSteps == 2)
		{
			m_pObArray->Add(new CMyShapeCircle(m_arrayPoints, m_colorColor, m_nWidth));
			m_bIsCreating = FALSE;		// 结束创建过程
		}
		break;
	case MYSHAPE_ELLIPSE:
		// 新建椭圆
		if (m_nSteps == 2)
		{
			m_pObArray->Add(new CMyShapeEllipse(m_arrayPoints, m_colorColor, m_nWidth));
			m_bIsCreating = FALSE;		// 结束创建过程
		}
		break;
	case MYSHAPE_RECTANGLE:
		// 新建矩形
		if (m_nSteps == 2)
		{
			m_pObArray->Add(new CMyShapeRectangle(m_arrayPoints, m_colorColor, m_nWidth));
			m_bIsCreating = FALSE;		// 结束创建过程
		}
		break;
	case MYSHAPE_POLYGON3:
		// 新建三角形
		if (m_nSteps == 3)
		{
			m_pObArray->Add(new CMyShapePolygon3(m_arrayPoints, m_colorColor, m_nWidth));
			m_bIsCreating = FALSE;		// 结束创建过程
		}
		break;
	case MYSHAPE_POLYGON4:
		// 新建四边形
		if (m_nSteps == 4)
		{
			m_pObArray->Add(new CMyShapePolygon4(m_arrayPoints, m_colorColor, m_nWidth));
			m_bIsCreating = FALSE;		// 结束创建过程
		}
		break;
	case MYSHAPE_POLYGON5:
		// 新建五边形
		if (m_nSteps == 5)
		{
			m_pObArray->Add(new CMyShapePolygon5(m_arrayPoints, m_colorColor, m_nWidth));
			m_bIsCreating = FALSE;		// 结束创建过程
		}
		break;
	case MYSHAPE_POLYGON6:
		// 新建六边形
		if (m_nSteps == 6)
		{
			m_pObArray->Add(new CMyShapePolygon6(m_arrayPoints, m_colorColor, m_nWidth));
			m_bIsCreating = FALSE;		// 结束创建过程
		}
		break;
	default:
		break;
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

/**************************************************
Name:		Copy
Inputs:
			CShapeCreator* pSrcShapeCreator		指向拷贝来源的指针
Return:
			(none)
Description:
			从 pSrcShapeCreator 拷贝一个新的 CShapeCreator 作为 *this
**************************************************/
void CShapeCreator::Copy(CShapeCreator* pSrcShapeCreator)
{
	// 复制所有的信息
	m_arrayPoints.Copy(pSrcShapeCreator->m_arrayPoints);
	m_bIsCreating = pSrcShapeCreator->m_bIsCreating;
	m_colorColor = pSrcShapeCreator->m_colorColor;
	m_nSteps = pSrcShapeCreator->m_nSteps;
	m_nType = pSrcShapeCreator->m_nType;
	m_nWidth = pSrcShapeCreator->m_nWidth;
	m_pObArray = pSrcShapeCreator->m_pObArray;
	m_bShowSetting = pSrcShapeCreator->m_bShowSetting;
}

/**************************************************
Name:		CreateFromJson
Inputs:
			CJsonObject jsonobjShape		用于创建图形的 CJsonObject
Return:
			(none)
Description:
			从 CJsonObject 创建一个新的图形，并将它压入目标图形数组中
**************************************************/
void CShapeCreator::CreateFromJson(CJsonObject jsonobjShape)
{
	// TODO: 在此处添加实现代码.
	int t_nType;						// 图形的类型
	jsonobjShape.Get("Type", t_nType);	// 从 Json 对象获取图形类型
	CMyShape* pShape;					// 新图形指针
	switch (t_nType)
	{
	case MYSHAPE_POINT:
		// 新建点
		pShape = new CMyShapePoint(CArray<CPoint, CPoint&>(), Color(0), 0);
		pShape->FromJson(jsonobjShape);		// 从 Json 对象转化为图形
		m_pObArray->Add(pShape);			// 添加图形到数组中
		break;
	case MYSHAPE_LINE:
		// 新建线
		pShape = new CMyShapeLine(CArray<CPoint, CPoint&>(), Color(0), 0);
		pShape->FromJson(jsonobjShape);		// 从 Json 对象转化为图形
		m_pObArray->Add(pShape);			// 添加图形到数组中
		break;
	case MYSHAPE_CIRCLE:
		// 新建圆
		pShape = new CMyShapeCircle(CArray<CPoint, CPoint&>(), Color(0), 0);
		pShape->FromJson(jsonobjShape);		// 从 Json 对象转化为图形
		m_pObArray->Add(pShape);			// 添加图形到数组中
		break;
	case MYSHAPE_ELLIPSE:
		// 新建椭圆
		pShape = new CMyShapeEllipse(CArray<CPoint, CPoint&>(), Color(0), 0);
		pShape->FromJson(jsonobjShape);		// 从 Json 对象转化为图形
		m_pObArray->Add(pShape);			// 添加图形到数组中
		break;
	case MYSHAPE_RECTANGLE:
		// 新建矩形
		pShape = new CMyShapeRectangle(CArray<CPoint, CPoint&>(), Color(0), 0);
		pShape->FromJson(jsonobjShape);		// 从 Json 对象转化为图形
		m_pObArray->Add(pShape);			// 添加图形到数组中
		break;
	case MYSHAPE_POLYGON3:
		// 新建三角形
		pShape = new CMyShapePolygon3(CArray<CPoint, CPoint&>(), Color(0), 0);
		pShape->FromJson(jsonobjShape);		// 从 Json 对象转化为图形
		m_pObArray->Add(pShape);			// 添加图形到数组中
		break;
	case MYSHAPE_POLYGON4:
		// 新建四边形
		pShape = new CMyShapePolygon4(CArray<CPoint, CPoint&>(), Color(0), 0);
		pShape->FromJson(jsonobjShape);		// 从 Json 对象转化为图形
		m_pObArray->Add(pShape);			// 添加图形到数组中
		break;
	case MYSHAPE_POLYGON5:
		// 新建五边形
		pShape = new CMyShapePolygon5(CArray<CPoint, CPoint&>(), Color(0), 0);
		pShape->FromJson(jsonobjShape);		// 从 Json 对象转化为图形
		m_pObArray->Add(pShape);			// 添加图形到数组中
		break;
	case MYSHAPE_POLYGON6:
		// 新建六边形
		pShape = new CMyShapePolygon6(CArray<CPoint, CPoint&>(), Color(0), 0);
		pShape->FromJson(jsonobjShape);		// 从 Json 对象转化为图形
		m_pObArray->Add(pShape);			// 添加图形到数组中
		break;
	default:
		break;
	}
}
