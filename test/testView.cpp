
// testView.cpp : CtestView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "test.h"
#endif

#include "testDoc.h"
#include "testView.h"
#include "Testdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtestView

IMPLEMENT_DYNCREATE(CtestView, CView)

BEGIN_MESSAGE_MAP(CtestView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_TEST, &CtestView::OnTest)
	ON_COMMAND(ID_APP_ABOUT, &CtestView::OnAppAbout)
	ON_WM_CHAR()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_ESHAPE, &CtestView::OnOvalShape)
	ON_COMMAND(ID_RSHAPE, &CtestView::OnRectShape)
END_MESSAGE_MAP()

// CtestView 构造/析构

CtestView::CtestView()
	: m_pos(0)
	, isMove(false)
	, isStop(false)
	, m_shape(false)
	, m_red(0)
	, m_green(0)
	, m_blue(0)
	, m_line(0)
	, m_color(0)
	, m_index(0)
	, m_str(_T(""))
{
	// TODO: 在此处添加构造代码
	m_line = 3;
	m_color = RGB (0,0,255);
	m_index = 2;
	m_shape = false;
	m_red = 1;
	m_green = 0;
	m_blue = 1;
}

CtestView::~CtestView()
{
}

BOOL CtestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CtestView 绘制

void CtestView::OnDraw(CDC* pDC)
{
	CtestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CBitmap bm;
	bm.LoadBitmapW(IDB_BITMAP1);
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	memDC.SelectObject(&bm);
	BITMAP info;
	bm.GetBitmap(&info);
	CRect rect;
	GetClientRect(&rect);
	if(!isMove && !isStop)
	{
		m_pos.x = rect.right-79;
	}
	
	pDC->BitBlt(m_pos.x,m_pos.y,info.bmWidth,info.bmHeight,&memDC,0,0,SRCCOPY);
	bm.DeleteObject();
	pDC->SetTextColor(RGB(255,0,0));
	pDC->TextOutW(rect.left,rect.bottom - 40,L"姓名：YOUR_NAME");
	pDC->TextOutW(rect.left,rect.bottom - 20,L"学号：YOUR_ID");

	CString str;
	CString str2;
	CPen myPen(PS_SOLID,m_line,RGB(255*m_red,255*m_green,255*m_blue));
	pDC->SelectObject(myPen);

	CBrush myBrush;
	
	if(m_index==0)
	{
		str = "垂直线";
		myBrush.CreateHatchBrush(HS_VERTICAL,m_color);
	}
	if(m_index==1)
	{
		str = "垂直线";
		myBrush.CreateHatchBrush(HS_HORIZONTAL,m_color);
	}
	if(m_index==2)
	{
		str = "斜十字线";
		myBrush.CreateHatchBrush(HS_DIAGCROSS,RGB (0,0,255));
	}
	
	pDC->SelectObject(myBrush);

	if(m_shape == false)
	{
		str2 = "椭圆";
		pDC->Ellipse(rect.right/2-50,rect.bottom/2-50,rect.right/2+50,rect.bottom/2+50);
	}
		
	else 
	{
		str2 = "矩形";
		pDC->Rectangle(rect.right/2-50,rect.bottom/2-50,rect.right/2+50,rect.bottom/2+50);
	}
		
	m_str.Format(L"边框宽度：%d，边框颜色RGB：%d、%d、%d，填充样式：%s，填充颜色：，形状：%s",m_line,m_red,m_blue,m_green,str,str);
	
	pDoc->m_str = m_str;
}


// CtestView 打印

BOOL CtestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CtestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CtestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CtestView 诊断

#ifdef _DEBUG
void CtestView::AssertValid() const
{
	CView::AssertValid();
}

void CtestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CtestDoc* CtestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtestDoc)));
	return (CtestDoc*)m_pDocument;
}
#endif //_DEBUG


// CtestView 消息处理程序


void CtestView::OnTest()
{
	// TODO: 在此添加命令处理程序代码
	CTestdlg dlg;
	CRect rect;
	GetClientRect(&rect);
	dlg.right = rect.right/2;
	dlg.bottom = rect.bottom/2;
	if(dlg.DoModal()==IDOK)
	{
		m_shape = dlg.m_shape;
		m_red = dlg.m_red;
		m_green = dlg.m_green;
		m_blue = dlg.m_blue;
		m_line = dlg.m_line;
		m_index = dlg.m_index;
		m_color = dlg.m_color;
		Invalidate();
	}
}


void CtestView::OnAppAbout()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(L"姓名：YOUR_NAME",L"学号：YOUR_ID");
}



void CtestView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nChar=='n' || nChar=='N')
	{
		isMove = true;
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}


int CtestView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	
	// 设置计时器
	SetTimer(1,100,NULL);

	return 0;
}


void CtestView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	// 销毁计时器
	KillTimer(1); 
}


void CtestView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nIDEvent == 1 && isMove)
	{
		
		
		// 获得客户区
		CRect rect;
		GetClientRect(&rect);
		if(m_pos.x>rect.left)
		{
			m_pos.x=m_pos.x-20;
		}
		else
		{
			isMove = false;
			isStop = true;
		}
		Invalidate();
		
	}

	CView::OnTimer(nIDEvent);
}


void CtestView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	CMenu* pmenu = menu.GetSubMenu(0);
	GetCursorPos(&point);
	pmenu->TrackPopupMenu(TPM_LEFTALIGN,point.x,point.y,this);
	CView::OnRButtonDown(nFlags, point);
}


void CtestView::OnOvalShape()
{
	// TODO: 在此添加命令处理程序代码
	m_shape=false;
	// 清除绘图
	Invalidate();
	UpdateWindow();
}


void CtestView::OnRectShape()
{
	// TODO: 在此添加命令处理程序代码
	m_shape=true;
	// 清除绘图
	Invalidate();
	UpdateWindow();
}
