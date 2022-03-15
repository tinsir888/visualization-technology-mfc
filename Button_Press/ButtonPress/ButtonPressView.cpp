
// ButtonPressView.cpp: CButtonPressView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ButtonPress.h"
#endif

#include "ButtonPressDoc.h"
#include "ButtonPressView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CButtonPressView

IMPLEMENT_DYNCREATE(CButtonPressView, CView)

BEGIN_MESSAGE_MAP(CButtonPressView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_MESSAGE(WM_MY_MESSAGE, &CButtonPressView::OnMyMessage)//自定义WM_MY_MESSAGE消息
END_MESSAGE_MAP()

// CButtonPressView 构造/析构

CButtonPressView::CButtonPressView() noexcept
{
	// TODO: 在此处添加构造代码

	m_Str = _T("");
}

CButtonPressView::~CButtonPressView()
{
}

BOOL CButtonPressView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CButtonPressView 绘图

void CButtonPressView::OnDraw(CDC* pDC)//在客户区显示信息
{
	CButtonPressDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->TextOutW(0, 0, m_Str);
}


// CButtonPressView 打印

BOOL CButtonPressView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CButtonPressView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CButtonPressView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CButtonPressView 诊断

#ifdef _DEBUG
void CButtonPressView::AssertValid() const
{
	CView::AssertValid();
}

void CButtonPressView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CButtonPressDoc* CButtonPressView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CButtonPressDoc)));
	return (CButtonPressDoc*)m_pDocument;
}
#endif //_DEBUG


// CButtonPressView 消息处理程序

/*
* 自定义WM_MY_MESSAGE消息，带两个参数（10和50），
* 由“@”（不是“2”）键激活，客户区中显示相应信息
* （自定义消息+参数）。
*/
void CButtonPressView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString str;
	str.Format(L"%c Key Pressed!", nChar);
	m_Str = str;
	if (nChar == '@') {
		SendMessage(WM_MY_MESSAGE, 10, 50);
	}
	//CView::OnChar(nChar, nRepCnt, nFlags);
}


void CButtonPressView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_Pos = point;
	CDC* pDC = GetDC();
	CString str;
	//单击鼠标左键+Ctrl，消息对话框中显示鼠标信息（鼠标左键+坐标）
	if (nFlags & MK_CONTROL) {
		str.Format(L"Left Mouse + Ctrl Clicked! Position is (%d, %d)!", 
			point.x, point.y);
		//Ctrl+左键位置信息显示
		MessageBox(str);
	}
	else {//单击鼠标左键，消息对话框中显示鼠标信息（鼠标左键+坐标）
		str.Format(L"Left Mouse Clicked! Position is (%d, %d)!", point.x, point.y);
		//显示左键位置信息
		MessageBox(str);
	}
	Invalidate(1);
	CView::OnLButtonDown(nFlags, point);
}


void CButtonPressView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ClientToScreen(&point);
	//CView::OnRButtonUp(nFlags, point);
	OnContextMenu(this, point);
}


afx_msg LRESULT CButtonPressView::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	CString str;
	str.Format(L"Message Parametres are %d and %d.", wParam, lParam);
	m_Str = str;
	Invalidate(1);
	return 0;
}

/*
* 按下键盘任意字符键（至少识别两个功能键），
* 客户区中显示按键信息（字符或功能键内容）；
*/
BOOL CButtonPressView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此处添加实现代码.
	CString str;
	if (pMsg -> message == WM_KEYDOWN) {
		if (pMsg->wParam == VK_F1) {//客户区显示 F1
			str.Format(L"F1 key pressed!");
			m_Str = str;
		}
		else if (pMsg->wParam == VK_UP) {//客户区显示 up 按键
			str.Format(L"Up key pressed!");
			m_Str = str;
		}
		else if (pMsg->wParam == VK_SHIFT) {
			str.Format(L"Shift key pressed!");
			m_Str = str;
		}
	}
	Invalidate(1);
	return CView::PreTranslateMessage(pMsg);
}
