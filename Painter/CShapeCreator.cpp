//////////////////////////////////////////////////
// �ļ�����		CShapeCreator.cpp
// �汾��		1.0
// Ŀ���빦�ܣ�	ͼ�δ�������һ��״̬����
// �������ڣ�	2020.9.6
// �޸����ڣ�	2020.9.14
// ���ߣ�		Fan Zhimin
// �޸��ߣ�		Fan Zhimin
// ��ϵ��ʽ��	
//////////////////////////////////////////////////


#include "pch.h"
#include "CShapeCreator.h"

CShapeCreator::CShapeCreator()
{
	m_colorColor = Color(0, 0, 0);	// �趨��ʼ��ɫ
	m_nWidth = 1;					// �趨��ʼ�߿�
	m_nSteps = 0;					// ��������
	m_nType = 0;					// ��ʼ����Ϊ��
	m_bIsCreating = 0;				// ��̬�²��ڴ���״̬��
	m_bShowSetting = 1;				// ��̬���Զ��������ô���
	m_pObArray = NULL;
}

/**************************************************
Name:		SetTarget
Inputs:
			CObArray* pObArrayTarget	ָ��Ŀ�������ָ��
Return:
			(none)
Description:
			���� ShapeCreator Ҫ����������ͼ�δ�ŵ��δ�
**************************************************/
void CShapeCreator::SetTarget(CObArray* pObArrayTarget)
{
	m_pObArray = pObArrayTarget;	// �趨Ŀ������
}

/**************************************************
Name:		BeginCreating
Inputs:
			int t_nType					������ͼ�ε�����
Return:
			(none)
Description:
			��״̬���´�ָ���ʼ����һ���µ�ָ�������ͼ��
**************************************************/
void CShapeCreator::BeginCreating(int t_nType)
{
	if (m_bShowSetting)		// ���Ҫÿ�δ���ʱ����������
	{
		CDialogPaintSetting t_dlgPaintSetting;				// ���öԻ���
		t_dlgPaintSetting.m_pTargetShapeCreator = this;		// �趨���ݵĴ洢Ŀ��
		t_dlgPaintSetting.DoModal();						// ��ʾģ̬�Ի���
	}
	m_bIsCreating = TRUE;		// ���ô���״̬
	m_nType = t_nType;			// ����ͼ������
	m_nSteps = 0;				// ���������λ

	m_arrayPoints.RemoveAll();	// ��տ��Ƶ�����
}

/**************************************************
Name:		PushPoint
Inputs:
			CPoint pointNewPoint		������Ŀ��Ƶ�
Return:
			(none)
Description:
			�����ڴ�����ͼ�Σ�����һ���µĿ��Ƶ�
**************************************************/
void CShapeCreator::PushPoint(CPoint pointNewPoint)
{
	++m_nSteps;							// ���Ƶ���������
	m_arrayPoints.Add(pointNewPoint);	// ѹ����Ƶ�

	// �ж�ͼ���Ƿ��Ѿ�������ɣ������ɣ���ͼ��ѹ��Ŀ��������
	switch (m_nType)
	{
	case MYSHAPE_POINT:
		// �½���
		if (m_nSteps == 1)
		{
			m_pObArray->Add(new CMyShapePoint(m_arrayPoints, m_colorColor, m_nWidth));
			m_bIsCreating = FALSE;		// ������������
		}
		break;
	case MYSHAPE_LINE:
		// �½���
		if (m_nSteps == 2)
		{
			m_pObArray->Add(new CMyShapeLine(m_arrayPoints, m_colorColor, m_nWidth));
			m_bIsCreating = FALSE;		// ������������
		}
		break;
	case MYSHAPE_CIRCLE:
		// �½�Բ��
		if (m_nSteps == 2)
		{
			m_pObArray->Add(new CMyShapeCircle(m_arrayPoints, m_colorColor, m_nWidth));
			m_bIsCreating = FALSE;		// ������������
		}
		break;
	case MYSHAPE_ELLIPSE:
		// �½���Բ
		if (m_nSteps == 2)
		{
			m_pObArray->Add(new CMyShapeEllipse(m_arrayPoints, m_colorColor, m_nWidth));
			m_bIsCreating = FALSE;		// ������������
		}
		break;
	case MYSHAPE_RECTANGLE:
		// �½�����
		if (m_nSteps == 2)
		{
			m_pObArray->Add(new CMyShapeRectangle(m_arrayPoints, m_colorColor, m_nWidth));
			m_bIsCreating = FALSE;		// ������������
		}
		break;
	case MYSHAPE_POLYGON3:
		// �½�������
		if (m_nSteps == 3)
		{
			m_pObArray->Add(new CMyShapePolygon3(m_arrayPoints, m_colorColor, m_nWidth));
			m_bIsCreating = FALSE;		// ������������
		}
		break;
	case MYSHAPE_POLYGON4:
		// �½��ı���
		if (m_nSteps == 4)
		{
			m_pObArray->Add(new CMyShapePolygon4(m_arrayPoints, m_colorColor, m_nWidth));
			m_bIsCreating = FALSE;		// ������������
		}
		break;
	case MYSHAPE_POLYGON5:
		// �½������
		if (m_nSteps == 5)
		{
			m_pObArray->Add(new CMyShapePolygon5(m_arrayPoints, m_colorColor, m_nWidth));
			m_bIsCreating = FALSE;		// ������������
		}
		break;
	case MYSHAPE_POLYGON6:
		// �½�������
		if (m_nSteps == 6)
		{
			m_pObArray->Add(new CMyShapePolygon6(m_arrayPoints, m_colorColor, m_nWidth));
			m_bIsCreating = FALSE;		// ������������
		}
		break;
	default:
		break;
	}

	// ������ʾ
	CMainFrame* t_pFrameMain = (CMainFrame*)AfxGetMainWnd();

	if (t_pFrameMain)
	{
		// �����б���Ϣ
		t_pFrameMain->m_pPainterListView->UpdateFromDoc();
		// �ػ�
		t_pFrameMain->m_pPainterListView->Invalidate(FALSE);
		t_pFrameMain->m_pPainterView->Invalidate(FALSE);
	}
}

/**************************************************
Name:		Copy
Inputs:
			CShapeCreator* pSrcShapeCreator		ָ�򿽱���Դ��ָ��
Return:
			(none)
Description:
			�� pSrcShapeCreator ����һ���µ� CShapeCreator ��Ϊ *this
**************************************************/
void CShapeCreator::Copy(CShapeCreator* pSrcShapeCreator)
{
	// �������е���Ϣ
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
			CJsonObject jsonobjShape		���ڴ���ͼ�ε� CJsonObject
Return:
			(none)
Description:
			�� CJsonObject ����һ���µ�ͼ�Σ�������ѹ��Ŀ��ͼ��������
**************************************************/
void CShapeCreator::CreateFromJson(CJsonObject jsonobjShape)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	int t_nType;						// ͼ�ε�����
	jsonobjShape.Get("Type", t_nType);	// �� Json �����ȡͼ������
	CMyShape* pShape;					// ��ͼ��ָ��
	switch (t_nType)
	{
	case MYSHAPE_POINT:
		// �½���
		pShape = new CMyShapePoint(CArray<CPoint, CPoint&>(), Color(0), 0);
		pShape->FromJson(jsonobjShape);		// �� Json ����ת��Ϊͼ��
		m_pObArray->Add(pShape);			// ���ͼ�ε�������
		break;
	case MYSHAPE_LINE:
		// �½���
		pShape = new CMyShapeLine(CArray<CPoint, CPoint&>(), Color(0), 0);
		pShape->FromJson(jsonobjShape);		// �� Json ����ת��Ϊͼ��
		m_pObArray->Add(pShape);			// ���ͼ�ε�������
		break;
	case MYSHAPE_CIRCLE:
		// �½�Բ
		pShape = new CMyShapeCircle(CArray<CPoint, CPoint&>(), Color(0), 0);
		pShape->FromJson(jsonobjShape);		// �� Json ����ת��Ϊͼ��
		m_pObArray->Add(pShape);			// ���ͼ�ε�������
		break;
	case MYSHAPE_ELLIPSE:
		// �½���Բ
		pShape = new CMyShapeEllipse(CArray<CPoint, CPoint&>(), Color(0), 0);
		pShape->FromJson(jsonobjShape);		// �� Json ����ת��Ϊͼ��
		m_pObArray->Add(pShape);			// ���ͼ�ε�������
		break;
	case MYSHAPE_RECTANGLE:
		// �½�����
		pShape = new CMyShapeRectangle(CArray<CPoint, CPoint&>(), Color(0), 0);
		pShape->FromJson(jsonobjShape);		// �� Json ����ת��Ϊͼ��
		m_pObArray->Add(pShape);			// ���ͼ�ε�������
		break;
	case MYSHAPE_POLYGON3:
		// �½�������
		pShape = new CMyShapePolygon3(CArray<CPoint, CPoint&>(), Color(0), 0);
		pShape->FromJson(jsonobjShape);		// �� Json ����ת��Ϊͼ��
		m_pObArray->Add(pShape);			// ���ͼ�ε�������
		break;
	case MYSHAPE_POLYGON4:
		// �½��ı���
		pShape = new CMyShapePolygon4(CArray<CPoint, CPoint&>(), Color(0), 0);
		pShape->FromJson(jsonobjShape);		// �� Json ����ת��Ϊͼ��
		m_pObArray->Add(pShape);			// ���ͼ�ε�������
		break;
	case MYSHAPE_POLYGON5:
		// �½������
		pShape = new CMyShapePolygon5(CArray<CPoint, CPoint&>(), Color(0), 0);
		pShape->FromJson(jsonobjShape);		// �� Json ����ת��Ϊͼ��
		m_pObArray->Add(pShape);			// ���ͼ�ε�������
		break;
	case MYSHAPE_POLYGON6:
		// �½�������
		pShape = new CMyShapePolygon6(CArray<CPoint, CPoint&>(), Color(0), 0);
		pShape->FromJson(jsonobjShape);		// �� Json ����ת��Ϊͼ��
		m_pObArray->Add(pShape);			// ���ͼ�ε�������
		break;
	default:
		break;
	}
}
