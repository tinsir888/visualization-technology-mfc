
// PersonalInfoView.cpp: CPersonalInfoView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "PersonalInfo.h"
#endif

#include "PersonalInfoDoc.h"
#include "PersonalInfoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPersonalInfoView

IMPLEMENT_DYNCREATE(CPersonalInfoView, CView)

BEGIN_MESSAGE_MAP(CPersonalInfoView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SHOW_DB,&CPersonalInfoView::OnOpenDB)
END_MESSAGE_MAP()

// CPersonalInfoView 构造/析构

CPersonalInfoView::CPersonalInfoView() noexcept
{
	// TODO: 在此处添加构造代码

	name = _T("");
	gender = _T("");
	age = _T("");
	ethnicity = _T("");
	place_of_origin = _T("");
	stu_id = _T("");
}

CPersonalInfoView::~CPersonalInfoView()
{
}

BOOL CPersonalInfoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CPersonalInfoView 绘图

void CPersonalInfoView::OnDraw(CDC* /*pDC*/)
{
	CPersonalInfoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CPersonalInfoView 打印

BOOL CPersonalInfoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CPersonalInfoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CPersonalInfoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CPersonalInfoView 诊断

#ifdef _DEBUG
void CPersonalInfoView::AssertValid() const
{
	CView::AssertValid();
}

void CPersonalInfoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPersonalInfoDoc* CPersonalInfoView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPersonalInfoDoc)));
	return (CPersonalInfoDoc*)m_pDocument;
}
#endif //_DEBUG


// CPersonalInfoView 消息处理程序


void CPersonalInfoView::OnOpenDB()
{
	// TODO: 在此处添加实现代码.
	MyDlg dlg;
	if (dlg.DoModal() == IDOK) {
		name = dlg.m_name;
		age = dlg.m_age;
		place_of_origin = dlg.m_place_of_origin;
		ethnicity = dlg.m_ethnicity;
		stu_id = dlg.m_stu_id;
		gender = dlg.m_gender;
		CDC* pDC = GetDC();
		CString output_name,output_gender,output_age,
			output_ethnicity,output_stuid,output_poo;
		output_name.Format(L"name: %s", name);
		output_gender.Format(L"gender: %s", gender);
		output_age.Format(L"age: %s", age);
		output_ethnicity.Format(L"ethnicity: %s", ethnicity);
		output_poo.Format(L"place of origin: %s", place_of_origin);
		output_stuid.Format(L"ID number: %s", stu_id);
		pDC->TextOutW(0, 0, output_name);
		pDC->TextOutW(0, 20, output_gender);
		pDC->TextOutW(0, 40, output_age);
		pDC->TextOutW(0, 60, output_ethnicity);
		pDC->TextOutW(0, 80, output_poo);
		pDC->TextOutW(0, 100, output_stuid);
		CPersonalInfoDoc* pDoc = GetDocument();
		pDoc->name = name;
		pDoc->gender = gender;
		pDoc->age = age;
		pDoc->place_of_origin = place_of_origin;
		pDoc->ethnicity = ethnicity;
		pDoc->stu_id = stu_id;
	}
}
