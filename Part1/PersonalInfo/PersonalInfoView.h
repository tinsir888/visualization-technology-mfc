
// PersonalInfoView.h: CPersonalInfoView 类的接口
//

#pragma once
#include "MyDlg.h"

class CPersonalInfoView : public CView
{
protected: // 仅从序列化创建
	CPersonalInfoView() noexcept;
	DECLARE_DYNCREATE(CPersonalInfoView)

// 特性
public:
	CPersonalInfoDoc* GetDocument() const;

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
	virtual ~CPersonalInfoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CString gender;
	CString age;
	CString ethnicity;
	CString place_of_origin;
	CString stu_id;
	void OnOpenDB();
};

#ifndef _DEBUG  // PersonalInfoView.cpp 中的调试版本
inline CPersonalInfoDoc* CPersonalInfoView::GetDocument() const
   { return reinterpret_cast<CPersonalInfoDoc*>(m_pDocument); }
#endif

