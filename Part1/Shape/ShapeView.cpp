
// ShapeView.cpp: CShapeView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Shape.h"
#endif

#include "ShapeDoc.h"
#include "ShapeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CShapeView

IMPLEMENT_DYNCREATE(CShapeView, CView)

BEGIN_MESSAGE_MAP(CShapeView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CShapeView::OnFilePrintPreview)
	ON_COMMAND(ID_POPUP_OVAL, &CShapeView::OnPopupOval)
	ON_COMMAND(ID_POPUP_RECTANGLE, &CShapeView::OnPopupRectangle)
END_MESSAGE_MAP()

// CShapeView 构造/析构

CShapeView::CShapeView() noexcept
{
	// TODO: 在此处添加构造代码

}

CShapeView::~CShapeView()
{
}

BOOL CShapeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CShapeView 绘图

void CShapeView::OnDraw(CDC* /*pDC*/)
{
	CShapeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
	CString str;
	
}


// CShapeView 打印

BOOL CShapeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CShapeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CShapeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CShapeView 诊断

#ifdef _DEBUG
void CShapeView::AssertValid() const
{
	CView::AssertValid();
}

void CShapeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CShapeDoc* CShapeView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShapeDoc)));
	return (CShapeDoc*)m_pDocument;
}
#endif //_DEBUG


// CShapeView 消息处理程序


void CShapeView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: 在此处添加消息处理程序代码
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	CMenu* pMenu = menu.GetSubMenu(0);
	pMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
}


void CShapeView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}


void CShapeView::OnPopupOval()
{
	// TODO: 在此添加命令处理程序代码
	InvalidateRect(NULL);
	UpdateWindow();
	CDC* pDC = GetDC();
	CShapeDoc* pDoc = GetDocument();
	CRect rect;
	GetClientRect(&rect);//获取客户区的大小
	//将当前客户区的内容清空
	int WindowWidth = rect.Width();
	int WindowHeight = rect.Height();
	RedrawWindow(CRect(0, 0, WindowWidth, WindowHeight));

	CPoint pnt;
	GetCursorPos(&pnt);
	GetWindowRect(&rect);//获取客户区左上角相对于屏幕的位置
	int tmp_x = pnt.x - rect.left;
	int tmp_y = pnt.y - rect.top;
	pnt.x = tmp_x;
	pnt.y = tmp_y;
	pDC->Ellipse(pnt.x, pnt.y, pnt.x + 400, pnt.y + 300);
	CString str;
	str.Format(L"Oval!!! The upper-left coordinates: (%d, %d). The height and width: (%d, %d).", pnt.x, pnt.y, 400, 300);
	pDoc->Set(2, pnt, str);
	ReleaseDC(pDC);
}


void CShapeView::OnPopupRectangle()
{
	// TODO: 在此添加命令处理程序代码
	InvalidateRect(NULL);
	UpdateWindow();
	CDC* pDC = GetDC();
	CShapeDoc* pDoc = GetDocument();
	CRect rect;
	GetClientRect(&rect);//获取客户区的大小
	//将当前客户区的内容清空
	int WindowWidth = rect.Width();
	int WindowHeight = rect.Height();
	RedrawWindow(CRect(0, 0, WindowWidth, WindowHeight));

	CPoint pnt;
	GetCursorPos(&pnt);
	GetWindowRect(&rect);//获取客户区左上角相对于屏幕的位置
	int tmp_x = pnt.x - rect.left;
	int tmp_y = pnt.y - rect.top;
	pnt.x = tmp_x;
	pnt.y = tmp_y;
	pDC->Rectangle(pnt.x, pnt.y, pnt.x + 400, pnt.y + 300);
	CString str;
	str.Format(L"Rectangle!!! The upper-left coordinates: (%d, %d). The height and width: (%d, %d).", pnt.x, pnt.y, 400, 300);
	pDoc->Set(1, pnt, str);
	ReleaseDC(pDC);
}
