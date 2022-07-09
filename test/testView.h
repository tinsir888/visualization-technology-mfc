
// testView.h : CtestView 类的接口
//

#pragma once
#include "atltypes.h"


class CtestView : public CView
{
protected: // 仅从序列化创建
	CtestView();
	DECLARE_DYNCREATE(CtestView)

// 特性
public:
	CtestDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CtestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTest();
	afx_msg void OnAppAbout();
	CPoint m_pos;
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	bool isStop;
	bool isMove;
	bool isStop;
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnOvalShape();
	bool m_shape;
	afx_msg void OnRectShape();
	int m_red;
	int m_green;
	int m_blue;
	int m_line;
	int m_color;
	int m_index;
	CString m_str;
};

#ifndef _DEBUG  // testView.cpp 中的调试版本
inline CtestDoc* CtestView::GetDocument() const
   { return reinterpret_cast<CtestDoc*>(m_pDocument); }
#endif

