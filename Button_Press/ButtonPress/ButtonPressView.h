
// ButtonPressView.h: CButtonPressView 类的接口
//

#pragma once
#include "atltypes.h"
#define WM_MY_MESSAGE WM_USER + 1

class CButtonPressView : public CView
{
protected: // 仅从序列化创建
	CButtonPressView() noexcept;
	DECLARE_DYNCREATE(CButtonPressView)

// 特性
public:
	CButtonPressDoc* GetDocument() const;

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
	virtual ~CButtonPressView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
protected:
	afx_msg LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);
	CPoint m_Pos;
	CString m_Str;
public:
	BOOL PreTranslateMessage(MSG* pMsg);
};

#ifndef _DEBUG  // ButtonPressView.cpp 中的调试版本
inline CButtonPressDoc* CButtonPressView::GetDocument() const
   { return reinterpret_cast<CButtonPressDoc*>(m_pDocument); }
#endif

