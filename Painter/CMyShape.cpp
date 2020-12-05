//////////////////////////////////////////////////
// 文件名：		CMyShape.cpp
// 版本：		1.0
// 目的与功能：	图形抽象类，所有具体图形的基类
// 创建日期：	2020.9.6
// 修改日期：	2020.9.14
// 作者：		Fan Zhimin
// 修改者：		Fan Zhimin
// 联系方式：	
//////////////////////////////////////////////////

#include "pch.h"

/**************************************************
Name:		GetName
Inputs:
			(none)
Return:
			(CString)		待显示的名称字符串	
Description:
			获取名称，用于 ListView 显示
**************************************************/
CString CMyShape::GetName()
{
	CString t_strName;
	t_strName = _T("未命名对象");
	return t_strName;
}

/**************************************************
Name:		Assign
Inputs:
			CMyShape& shapeSrc		待赋值的源图形引用
Return:
			(none)
Description:
			赋值函数，将 shapeSrc 赋值给 *this
**************************************************/
void CMyShape::Assign(CMyShape& shapeSrc)
{
	m_arrayPoints.Copy(shapeSrc.m_arrayPoints);
	m_colorColor = shapeSrc.m_colorColor;
	m_nType = shapeSrc.m_nType;
	m_nWidth = shapeSrc.m_nWidth;
}



/**************************************************
Name:		ToJson
Inputs:
			(none)
Return:
			(CJsonObject)		转化后的 CJsonObject
Description:
			将 *this 图形转化为 CJsonObject 对象
**************************************************/
CJsonObject CMyShape::ToJson()
{
	// TODO: 在此处添加实现代码.

	CJsonObject jsonobjResult;		// 转换结果
	CJsonObject jsonobjColor;		// 颜色对象
	CJsonObject jsonobjPointArray;	// 控制点数组

	// 颜色对象
	jsonobjColor.Add("Red", m_colorColor.GetRed());
	jsonobjColor.Add("Green", m_colorColor.GetGreen());
	jsonobjColor.Add("Blue", m_colorColor.GetBlue());

	// 控制点数组
	for (int i = 0; i < m_arrayPoints.GetSize(); i++)
	{
		CJsonObject t_jsonobjPoint;		// 控制点对象
		t_jsonobjPoint.Add("x", m_arrayPoints[i].x);
		t_jsonobjPoint.Add("y", m_arrayPoints[i].y);
		jsonobjPointArray.Add(t_jsonobjPoint);		// 加入数组
	}
	
	// 合并得到图形对象
	jsonobjResult.Add("Type", m_nType);
	jsonobjResult.Add("Width", m_nWidth);
	jsonobjResult.Add("Color", jsonobjColor);
	jsonobjResult.Add("Points", jsonobjPointArray);

	return jsonobjResult;
}

/**************************************************
Name:		FromJson
Inputs:
			CJsonObject jsonobjShape	要转换的 CJsonObject 对象
Return:
			(none)
Description:
			将一个 CJsonObject 对象转换为 CMyShape 类型并赋值给 *this
**************************************************/
void CMyShape::FromJson(CJsonObject jsonobjShape)
{
	// TODO: 在此处添加实现代码.
	CJsonObject jsonobjColor;		// 颜色对象	
	CJsonObject jsonobjPointArray;	// 控制点数组

	// 从图形对象中提取
	jsonobjShape.Get("Type", m_nType);					// 获取类型
	jsonobjShape.Get("Width", m_nWidth);				// 获取线宽
	jsonobjShape.Get("Color", jsonobjColor);			// 获取颜色对象
	jsonobjShape.Get("Points", jsonobjPointArray);		// 获取控制点数组

	// 从颜色对象中提取颜色
	int t_nColorRed, t_nColorGreen, t_nColorBlue;		// 颜色分量
	jsonobjColor.Get("Red", t_nColorRed);
	jsonobjColor.Get("Green", t_nColorGreen);
	jsonobjColor.Get("Blue", t_nColorBlue);
	m_colorColor = Color(t_nColorRed, t_nColorGreen, t_nColorBlue);	

	// 从控制点数组对象中提取控制点
	m_arrayPoints.RemoveAll();
	// 遍历所有的控制点
	int t_nSize = jsonobjPointArray.GetArraySize();			// 数组大小
	for (int i = 0; i < t_nSize; i++)
	{
		CJsonObject jsonobjPoint = jsonobjPointArray[i];	// 控制点对象
		int t_nPointX, t_nPointY;		// 控制点的坐标
		jsonobjPoint.Get("x", t_nPointX);
		jsonobjPoint.Get("y", t_nPointY);
		m_arrayPoints.Add(CPoint(t_nPointX, t_nPointY));
	}
}
