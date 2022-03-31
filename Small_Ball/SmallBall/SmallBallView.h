
// SmallBallView.h: CSmallBallView 类的接口
//

#pragma once


class CSmallBallView : public CView
{
protected: // 仅从序列化创建
	CSmallBallView() noexcept;
	DECLARE_DYNCREATE(CSmallBallView)

// 特性
public:
	CSmallBallDoc* GetDocument() const;

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
	virtual ~CSmallBallView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
private:
	int x;
	int y;
	int movex;
	int movey;
	int stopx;
	int stopy;
public:
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnMenuRButtonUp(UINT nPos, CMenu* pMenu);
	afx_msg void OnTimer(UINT_PTR nIDEvent);

public:
	void OnControlAcc();//加速
	void OnControlDec();//减速
	void OnControlStop();//停止
	void OnControlRestart();//重启
protected:
	void OnRButtonUp(UINT nFlags, CPoint Point);
};

#ifndef _DEBUG  // SmallBallView.cpp 中的调试版本
inline CSmallBallDoc* CSmallBallView::GetDocument() const
   { return reinterpret_cast<CSmallBallDoc*>(m_pDocument); }
#endif

