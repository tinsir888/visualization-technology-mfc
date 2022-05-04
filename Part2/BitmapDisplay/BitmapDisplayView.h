﻿
// BitmapDisplayView.h: CBitmapDisplayView 类的接口
//

#pragma once


class CBitmapDisplayView : public CScrollView
{
protected: // 仅从序列化创建
	CBitmapDisplayView() noexcept;
	DECLARE_DYNCREATE(CBitmapDisplayView)

// 特性
public:
	CBitmapDisplayDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CBitmapDisplayView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOriginalSize();
	afx_msg void OnQuadrupleSize();
	afx_msg void OnQuarterSize();
	int node;
};

#ifndef _DEBUG  // BitmapDisplayView.cpp 中的调试版本
inline CBitmapDisplayDoc* CBitmapDisplayView::GetDocument() const
   { return reinterpret_cast<CBitmapDisplayDoc*>(m_pDocument); }
#endif

