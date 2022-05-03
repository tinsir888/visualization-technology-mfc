
// TrackView.h: CTrackView 类的接口
//

#pragma once


class CTrackView : public CView
{
protected: // 仅从序列化创建
	CTrackView() noexcept;
	DECLARE_DYNCREATE(CTrackView)

// 特性
public:
	CTrackDoc* GetDocument() const;

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
	virtual ~CTrackView();
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
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int movx;
	int movy;
	CPoint pnt0;
	int nums;
	int x;
	int y;
	afx_msg void OnPopupPloygon();
	afx_msg void OnPopupRectangle();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

#ifndef _DEBUG  // TrackView.cpp 中的调试版本
inline CTrackDoc* CTrackView::GetDocument() const
   { return reinterpret_cast<CTrackDoc*>(m_pDocument); }
#endif

