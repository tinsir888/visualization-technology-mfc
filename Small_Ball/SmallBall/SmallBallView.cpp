
// SmallBallView.cpp: CSmallBallView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "SmallBall.h"
#endif

#include "SmallBallDoc.h"
#include "SmallBallView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSmallBallView

IMPLEMENT_DYNCREATE(CSmallBallView, CView)

BEGIN_MESSAGE_MAP(CSmallBallView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_MENURBUTTONUP()
	ON_WM_TIMER()
	ON_COMMAND(ID_WEITER, &CSmallBallView::OnControlRestart)//继续
	ON_COMMAND(ID_AUSZEIT, &CSmallBallView::OnControlStop)//暂停
	ON_COMMAND(ID_32771, &CSmallBallView::OnControlAcc)//加速
	ON_COMMAND(ID_32772, &CSmallBallView::OnControlDec)//减速
END_MESSAGE_MAP()

int speed = 500;

// CSmallBallView 构造/析构

CSmallBallView::CSmallBallView() noexcept
{
	// TODO: 在此处添加构造代码

	x = 0;
	y = 0;
	movex = movey = stopx = stopy = 10;//设置球的初速10pixel
}

CSmallBallView::~CSmallBallView()
{
}

BOOL CSmallBallView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSmallBallView 绘图

void CSmallBallView::OnDraw(CDC* pDC)
{
	CSmallBallDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->SetROP2(R2_XORPEN);
	pDC->Ellipse(x, y, x + 15, y + 15);//设置小球的大小
}


// CSmallBallView 打印

BOOL CSmallBallView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSmallBallView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSmallBallView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CSmallBallView 诊断

#ifdef _DEBUG
void CSmallBallView::AssertValid() const
{
	CView::AssertValid();
}

void CSmallBallView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSmallBallDoc* CSmallBallView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSmallBallDoc)));
	return (CSmallBallDoc*)m_pDocument;
}
#endif //_DEBUG


// CSmallBallView 消息处理程序


void CSmallBallView::OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/)
{
	// TODO: 在此处添加消息处理程序代码
}


int CSmallBallView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	SetTimer(1, speed, NULL);
	return 0;
}


void CSmallBallView::OnDestroy()
{
	CView::OnDestroy();
	// TODO: 在此处添加消息处理程序代码
	KillTimer(1);//时钟周期
}


void CSmallBallView::OnMenuRButtonUp(UINT nPos, CMenu* pMenu)
{
	// 该功能要求使用 Windows 2000 或更高版本。
	// 符号 _WIN32_WINNT 和 WINVER 必须 >= 0x0500。
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnMenuRButtonUp(nPos, pMenu);
}


void CSmallBallView::OnTimer(UINT_PTR nIDEvent)//小球运行的代码
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == 1) {
		CRect rect;
		GetClientRect(&rect);
		CDC* pDC = GetDC();
		pDC->SetROP2(R2_XORPEN);
		pDC->Ellipse(x, y, x + 15, y + 15);
		x += movex;
		y += movey;
		//判断撞墙后，进行转向
		if (x<0 || x>rect.right - 10) {
			movex = 0 - movex;
			stopx = movex;
		}
		if (y<0 || y>rect.bottom - 10) {
			movey = 0 - movey;
			stopy = movey;
		}
		pDC->Ellipse(x, y, x + 15, y + 15);
	}
	CView::OnTimer(nIDEvent);
}


void CSmallBallView::OnControlAcc()//控制小球加速
{
	// TODO: 在此处添加实现代码.
	if (speed > 50)speed -= 50;
	KillTimer(1);
	SetTimer(1, speed, NULL);
}


void CSmallBallView::OnControlDec()//控制小球减速
{
	// TODO: 在此处添加实现代码.
	/*if (movex > 0)movex -= 2;
	else if (movex < 0)movex += 2;
	if (movey > 0)movey -= 2;
	else movey += 2;
	stopx = movex;
	stopy = movey;*/
	speed += 50;
	KillTimer(1);
	SetTimer(1, speed, NULL);
}


void CSmallBallView::OnControlStop()//控制小球停止
{
	// TODO: 在此处添加实现代码.
	if (movex && movey) {
		stopx = movex;
		stopy = movey;
	}
	movex = 0;
	movey = 0;
}


void CSmallBallView::OnControlRestart()//控制小球开始运动
{
	// TODO: 在此处添加实现代码.
	movex = stopx;
	movey = stopy;
}


void CSmallBallView::OnRButtonUp(UINT nFlags, CPoint Point)
{
	// TODO: 在此处添加实现代码.
	ClientToScreen(&Point);
	OnContextMenu(this, Point);
}
