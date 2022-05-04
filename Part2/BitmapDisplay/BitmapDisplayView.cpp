
// BitmapDisplayView.cpp: CBitmapDisplayView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "BitmapDisplay.h"
#endif

#include "BitmapDisplayDoc.h"
#include "BitmapDisplayView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBitmapDisplayView

IMPLEMENT_DYNCREATE(CBitmapDisplayView, CScrollView)

BEGIN_MESSAGE_MAP(CBitmapDisplayView, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CBitmapDisplayView::OnOriginalSize)
	ON_COMMAND(ID_32772, &CBitmapDisplayView::OnQuadrupleSize)
	ON_COMMAND(ID_32773, &CBitmapDisplayView::OnQuarterSize)
END_MESSAGE_MAP()

// CBitmapDisplayView 构造/析构

CBitmapDisplayView::CBitmapDisplayView() noexcept
{
	// TODO: 在此处添加构造代码

	node = 0;
}

CBitmapDisplayView::~CBitmapDisplayView()
{
}

BOOL CBitmapDisplayView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CBitmapDisplayView 绘图

void CBitmapDisplayView::OnDraw(CDC* pDC)
{
	CBitmapDisplayDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CBitmap bm;
	bm.LoadBitmap(IDB_BITMAP1);
	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);
	MemDC.SelectObject(&bm);
	BITMAP info;
	bm.GetBitmap(&info);
	if (node == 0) {
		pDC->StretchBlt(0, 0, info.bmWidth, info.bmHeight, &MemDC, 0, 0, info.bmWidth, info.bmHeight, SRCCOPY);
		bm.DeleteObject();
	}
	else if (node == 1) {
		CRect rect;
		GetClientRect(&rect);
		pDC->StretchBlt(0, 0, info.bmWidth * 4, info.bmHeight * 4, &MemDC, 0, 0, info.bmWidth, info.bmHeight, SRCCOPY);
		bm.DeleteObject();
	}
	else if (node == 2) {
		pDC->StretchBlt(0, 0, info.bmWidth / 4, info.bmHeight / 4, &MemDC, 0, 0, info.bmWidth, info.bmHeight, SRCCOPY);
		bm.DeleteObject();
	}
}

void CBitmapDisplayView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = 1600;
	sizeTotal.cy = 1200;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CBitmapDisplayView 打印

BOOL CBitmapDisplayView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CBitmapDisplayView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CBitmapDisplayView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CBitmapDisplayView 诊断

#ifdef _DEBUG
void CBitmapDisplayView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CBitmapDisplayView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CBitmapDisplayDoc* CBitmapDisplayView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBitmapDisplayDoc)));
	return (CBitmapDisplayDoc*)m_pDocument;
}
#endif //_DEBUG


// CBitmapDisplayView 消息处理程序


void CBitmapDisplayView::OnOriginalSize()
{
	// TODO: 在此添加命令处理程序代码
	node = 0;
	Invalidate(TRUE);
}


void CBitmapDisplayView::OnQuadrupleSize()
{
	// TODO: 在此添加命令处理程序代码
	node = 1;
	Invalidate(TRUE);
}


void CBitmapDisplayView::OnQuarterSize()
{
	// TODO: 在此添加命令处理程序代码
	node = 2;
	Invalidate(TRUE);
}
