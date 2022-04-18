
// EditBoxView.h: CEditBoxView 类的接口
//

#pragma once


class CEditBoxView : public CView
{
protected: // 仅从序列化创建
	CEditBoxView() noexcept;
	DECLARE_DYNCREATE(CEditBoxView)

// 特性
public:
	CEditBoxDoc* GetDocument() const;

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
	virtual ~CEditBoxView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDialog();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	CString txt_str;
};

#ifndef _DEBUG  // EditBoxView.cpp 中的调试版本
inline CEditBoxDoc* CEditBoxView::GetDocument() const
   { return reinterpret_cast<CEditBoxDoc*>(m_pDocument); }
#endif

