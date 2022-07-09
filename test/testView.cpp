
// testView.cpp : CtestView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CtestView ����/����

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
	// TODO: �ڴ˴���ӹ������
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CtestView ����

void CtestView::OnDraw(CDC* pDC)
{
	CtestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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
	pDC->TextOutW(rect.left,rect.bottom - 40,L"������YOUR_NAME");
	pDC->TextOutW(rect.left,rect.bottom - 20,L"ѧ�ţ�YOUR_ID");

	CString str;
	CString str2;
	CPen myPen(PS_SOLID,m_line,RGB(255*m_red,255*m_green,255*m_blue));
	pDC->SelectObject(myPen);

	CBrush myBrush;
	
	if(m_index==0)
	{
		str = "��ֱ��";
		myBrush.CreateHatchBrush(HS_VERTICAL,m_color);
	}
	if(m_index==1)
	{
		str = "��ֱ��";
		myBrush.CreateHatchBrush(HS_HORIZONTAL,m_color);
	}
	if(m_index==2)
	{
		str = "бʮ����";
		myBrush.CreateHatchBrush(HS_DIAGCROSS,RGB (0,0,255));
	}
	
	pDC->SelectObject(myBrush);

	if(m_shape == false)
	{
		str2 = "��Բ";
		pDC->Ellipse(rect.right/2-50,rect.bottom/2-50,rect.right/2+50,rect.bottom/2+50);
	}
		
	else 
	{
		str2 = "����";
		pDC->Rectangle(rect.right/2-50,rect.bottom/2-50,rect.right/2+50,rect.bottom/2+50);
	}
		
	m_str.Format(L"�߿��ȣ�%d���߿���ɫRGB��%d��%d��%d�������ʽ��%s�������ɫ������״��%s",m_line,m_red,m_blue,m_green,str,str);
	
	pDoc->m_str = m_str;
}


// CtestView ��ӡ

BOOL CtestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CtestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CtestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CtestView ���

#ifdef _DEBUG
void CtestView::AssertValid() const
{
	CView::AssertValid();
}

void CtestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CtestDoc* CtestView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtestDoc)));
	return (CtestDoc*)m_pDocument;
}
#endif //_DEBUG


// CtestView ��Ϣ�������


void CtestView::OnTest()
{
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
	MessageBox(L"������YOUR_NAME",L"ѧ�ţ�YOUR_ID");
}



void CtestView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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

	// TODO:  �ڴ������ר�õĴ�������
	
	// ���ü�ʱ��
	SetTimer(1,100,NULL);

	return 0;
}


void CtestView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	// ���ټ�ʱ��
	KillTimer(1); 
}


void CtestView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(nIDEvent == 1 && isMove)
	{
		
		
		// ��ÿͻ���
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	CMenu* pmenu = menu.GetSubMenu(0);
	GetCursorPos(&point);
	pmenu->TrackPopupMenu(TPM_LEFTALIGN,point.x,point.y,this);
	CView::OnRButtonDown(nFlags, point);
}


void CtestView::OnOvalShape()
{
	// TODO: �ڴ���������������
	m_shape=false;
	// �����ͼ
	Invalidate();
	UpdateWindow();
}


void CtestView::OnRectShape()
{
	// TODO: �ڴ���������������
	m_shape=true;
	// �����ͼ
	Invalidate();
	UpdateWindow();
}
