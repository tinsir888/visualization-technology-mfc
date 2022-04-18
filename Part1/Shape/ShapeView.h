
// ShapeView.h: CShapeView 类的接口
//

#pragma once


class CShapeView : public CView
{
protected: // 仅从序列化创建
	CShapeView() noexcept;
	DECLARE_DYNCREATE(CShapeView)

// 特性
public:
	CShapeDoc* GetDocument() const;

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
	virtual ~CShapeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnFilePrintPreview();
	afx_msg void OnPopupOval();
	afx_msg void OnPopupRectangle();
};

#ifndef _DEBUG  // ShapeView.cpp 中的调试版本
inline CShapeDoc* CShapeView::GetDocument() const
   { return reinterpret_cast<CShapeDoc*>(m_pDocument); }
#endif

