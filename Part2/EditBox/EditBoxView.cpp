
// EditBoxView.cpp: CEditBoxView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "EditBox.h"
#endif

#include "EditBoxDoc.h"
#include "EditBoxView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "CMyDialog.h"

// CEditBoxView

IMPLEMENT_DYNCREATE(CEditBoxView, CView)

BEGIN_MESSAGE_MAP(CEditBoxView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CEditBoxView::OnDialog)
END_MESSAGE_MAP()

// CEditBoxView 构造/析构

CEditBoxView::CEditBoxView() noexcept
{
	// TODO: 在此处添加构造代码

}

CEditBoxView::~CEditBoxView()
{
}

BOOL CEditBoxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEditBoxView 绘图

void CEditBoxView::OnDraw(CDC* /*pDC*/)
{
	CEditBoxDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CEditBoxView 打印

BOOL CEditBoxView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CEditBoxView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CEditBoxView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CEditBoxView 诊断

#ifdef _DEBUG
void CEditBoxView::AssertValid() const
{
	CView::AssertValid();
}

void CEditBoxView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEditBoxDoc* CEditBoxView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEditBoxDoc)));
	return (CEditBoxDoc*)m_pDocument;
}
#endif //_DEBUG


// CEditBoxView 消息处理程序

void CEditBoxView::OnDialog() {
	CMyDialog dlg;

	if (dlg.DoModal() == IDOK) {
		txt_str = dlg.txt_str;
	}
	CDC* pDC;
	pDC = GetDC();
	pDC->TextOutW(0,0,txt_str);
	CEditBoxDoc* pDoc = GetDocument();
	pDoc->Set(txt_str);
}

void CEditBoxView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	if (nChar == 65) {
		CMyDialog dlg;
		if (dlg.DoModal() == IDOK) {
			txt_str = dlg.txt_str;
			CDC* pDC;
			pDC = GetDC();
			pDC->TextOutW(0,0,txt_str);
			CEditBoxDoc* pDoc = GetDocument();
			pDoc->Set(txt_str);
		}
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}