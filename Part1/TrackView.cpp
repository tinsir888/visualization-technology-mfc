
// TrackView.cpp: CTrackView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Track.h"
#endif

#include "TrackDoc.h"
#include "TrackView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTrackView

IMPLEMENT_DYNCREATE(CTrackView, CView)

BEGIN_MESSAGE_MAP(CTrackView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_WM_KEYUP()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_POPUP_RECTANGLE, &CTrackView::OnPopupRectangle)
	ON_COMMAND(ID_POPUP_POLYGON, &CTrackView::OnPopupPloygon)
END_MESSAGE_MAP()

// CTrackView 构造/析构

CTrackView::CTrackView() noexcept
{
	// TODO: 在此处添加构造代码

	movx = 1;
	movy = 1;
	nums = 0;
	x = 0;
	y = 0;
}

CTrackView::~CTrackView()
{
}

BOOL CTrackView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CTrackView 绘图

void CTrackView::OnDraw(CDC* /*pDC*/)
{
	CTrackDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CTrackView 打印

BOOL CTrackView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CTrackView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CTrackView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CTrackView 诊断

#ifdef _DEBUG
void CTrackView::AssertValid() const
{
	CView::AssertValid();
}

void CTrackView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTrackDoc* CTrackView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTrackDoc)));
	return (CTrackDoc*)m_pDocument;
}
#endif //_DEBUG


// CTrackView 消息处理程序


void CTrackView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nChar == 'v' || nChar== 'V') {
		CBitmap bm;
		bm.LoadBitmap(IDB_BITMAP1);
		CDC memDC;
		CDC* pDC = GetDC();
		memDC.CreateCompatibleDC(pDC);
		memDC.SelectObject(&bm);
		BITMAP info;
		bm.GetBitmap(&info);
		CRect rect;
		GetClientRect(&rect);
		pDC->BitBlt(x, y, info.bmWidth, info.bmHeight, &memDC, 0, 0, SRCCOPY);
		SetTimer(1, 10, NULL);
		bm.DeleteObject();
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CTrackView::OnContextMenu(CWnd* /*pWnd*/, CPoint pnt)
{
	// TODO: 在此处添加消息处理程序代码
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	CMenu* pMenu = menu.GetSubMenu(0);
	KillTimer(1);
	pMenu->TrackPopupMenu(TPM_LEFTALIGN,pnt.x,pnt.y,this);
}


void CTrackView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnRButtonUp(nFlags, point);
}

BOOL CTrackView::PreTranslateMessage(MSG* pMsg) {
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CPoint pnt;
	pnt.x = 200;
	pnt.y = 200;
	if (pMsg->message == WM_KEYDOWN && GetKeyState(VK_CONTROL) < 0){
		if (pMsg->wParam == 'R' || pMsg->wParam == 'r') {
			nums = 1;
			InvalidateRect(NULL);
			UpdateWindow();
			CDC* pDC = GetDC();
			CRect rect;
			GetClientRect(&rect);
			CPoint pnt;
			GetCursorPos(&pnt);
			GetWindowRect(&rect);
			int tmp_x = pnt.x - rect.left;
			int tmp_y = pnt.y - rect.top;
			pnt.x = x = tmp_x;
			pnt.y = y = tmp_y;
			pnt0 = pnt;
			pDC->Rectangle(pnt.x, pnt.y, pnt.x + 200, pnt.y + 200);
		}
		else if (pMsg->wParam == 'P' || pMsg->wParam == 'p') {
			nums = 2;
			InvalidateRect(NULL);
			UpdateWindow();
			CDC* pDC = GetDC();
			CRect rect;
			GetClientRect(&rect);
			CPoint pnt;
			GetCursorPos(&pnt);
			GetWindowRect(&rect);
			int tmp_x = pnt.x - rect.left;
			int tmp_y = pnt.y - rect.top;
			pnt.x = x = tmp_x;
			pnt.y = y = tmp_y;
			pnt0 = pnt;
			CPoint var[6];
			var[0].x = pnt0.x; var[0].y = pnt0.y;
			var[1].x = pnt0.x + 100; var[1].y = pnt0.y;
			var[2].x = pnt0.x + 200; var[2].y = pnt0.y + 100;
			var[3].x = pnt0.x + 100; var[3].y = pnt0.y + 200;
			var[4].x = pnt0.x; var[4].y = pnt0.y + 200;
			var[5].x = pnt0.x - 100; var[5].y = pnt0.y + 100;
			pDC->Polygon(var, 6);
		}
	}
	return CView::PreTranslateMessage(pMsg);
}

void CTrackView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == 1) {
		CBitmap bm;
		bm.LoadBitmap(IDB_BITMAP1);
		CDC memDC;
		CDC* pDC = GetDC();
		memDC.CreateCompatibleDC(pDC);
		memDC.SelectObject(&bm);
		BITMAP info;
		bm.GetBitmap(&info);
		CRect rect;
		GetClientRect(&rect);
		InvalidateRect(NULL);
		UpdateWindow();
		if (nums == 1) {
			movx = movy = 1;
			pDC->Rectangle(pnt0.x, pnt0.y, pnt0.x + 200, pnt0.y + 200);
			pDC->BitBlt(x, y, info.bmWidth, info.bmHeight, &memDC, 0, 0, SRCCOPY);
			if (y == pnt0.y && x != pnt0.x + 200)
				x += movx;
			else if (x == pnt0.x + 200 && y != pnt0.y + 200)
				y += movy;
			else if (y == pnt0.y + 200 && x != pnt0.x)
				x -= movx;
			else if (x == pnt0.x && y != pnt0.y)
				y -= movy;
		}
		else if (nums == 2) {
			movx = movy = 1;
			CPoint var[6];
			var[0].x = pnt0.x; var[0].y = pnt0.y;
			var[1].x = pnt0.x + 100; var[1].y = pnt0.y;
			var[2].x = pnt0.x + 200; var[2].y = pnt0.y + 100;
			var[3].x = pnt0.x + 100; var[3].y = pnt0.y + 200;
			var[4].x = pnt0.x; var[4].y = pnt0.y + 200;
			var[5].x = pnt0.x - 100; var[5].y = pnt0.y + 100;
			pDC->Polygon(var, 6);
			pDC->BitBlt(x, y, info.bmWidth, info.bmHeight, &memDC, 0, 0, SRCCOPY);
			if (y == pnt0.y && x <= pnt0.x + 100)
				x += movx;
			else if (x <= pnt0.x + 200 && y <= pnt0.y + 100 && x >= pnt0.x + 100 && y >= pnt0.y)
				x += movx, y += movy;
			else if (x <= pnt0.x + 202 && y <= pnt0.y + 200 && x >= pnt0.x + 100 && y >= pnt0.y + 100)
				x -= movx, y += movy;
			else if (y >= pnt0.y + 200 && x >= pnt0.x)
				x -= movx;
			else if (x <= pnt0.x && y <= pnt0.y + 202 && x >= pnt0.x - 100 && y >= pnt0.y + 100)
				x -= movx, y -= movy;
			else if (x <= pnt0.x && y <= pnt0.y + 102 && x >= pnt0.x - 102 && y >= pnt0.y)
				x += movx, y -= movy;
		}
		bm.DeleteObject();
	}
	CView::OnTimer(nIDEvent);
}


void CTrackView::OnPopupPloygon()
{
	// TODO: 在此处添加实现代码.
	nums = 2;
	InvalidateRect(NULL);
	UpdateWindow();
	CDC* pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);
	CPoint pnt;
	GetCursorPos(&pnt);
	GetWindowRect(&rect);
	int tmp_x = pnt.x - rect.left;
	int tmp_y = pnt.y - rect.top;
	pnt.x = x = tmp_x;
	pnt.y = y = tmp_y;
	pnt0 = pnt;
	CPoint var[6];
	var[0].x = pnt.x; var[0].y = pnt.y;
	var[1].x = pnt.x + 100; var[1].y = pnt.y;
	var[2].x = pnt.x + 200; var[2].y = pnt.y + 100;
	var[3].x = pnt.x + 100; var[3].y = pnt.y + 200;
	var[4].x = pnt.x; var[4].y = pnt.y + 200;
	var[5].x = pnt.x - 100; var[5].y = pnt.y + 100;
	pDC->Polygon(var, 6);
}


void CTrackView::OnPopupRectangle()
{
	// TODO: 在此处添加实现代码.
	nums = 1;
	InvalidateRect(NULL);
	UpdateWindow();
	CDC* pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);//获取客户区大小
	CPoint pnt;
	GetCursorPos(&pnt);
	GetWindowRect(&rect);
	int tmp_x = pnt.x - rect.left;
	int tmp_y = pnt.y - rect.top;
	pnt.x = x = tmp_x;
	pnt.y = y = tmp_y;
	pnt0 = pnt;
	pDC->Rectangle(pnt.x, pnt.y, pnt.x + 200, pnt.y + 200);
}
