// Testdlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "Testdlg.h"
#include "afxdialogex.h"


// CTestdlg 对话框

IMPLEMENT_DYNAMIC(CTestdlg, CDialogEx)

CTestdlg::CTestdlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestdlg::IDD, pParent)
	, m_shape(false)
	, m_red(0)
	, m_green(0)
	, m_blue(0)
	, m_line(0)
	, right(0)
	, bottom(0)
	, m_index(0)
{

	m_Fill = _T("");
}

CTestdlg::~CTestdlg()
{
}

void CTestdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_CtrlSlider1);
	DDX_CBString(pDX, IDC_COMBO1, m_Fill);
	DDV_MaxChars(pDX, m_Fill, 20);
}


BEGIN_MESSAGE_MAP(CTestdlg, CDialogEx)
	ON_BN_CLICKED(IDC_ELLI, &CTestdlg::OnBnClickedElli)
	ON_BN_CLICKED(IDC_RECT, &CTestdlg::OnBnClickedRect)
	ON_BN_CLICKED(IDC_CHECK1, &CTestdlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CTestdlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CTestdlg::OnBnClickedCheck3)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CTestdlg::OnNMCustomdrawSlider1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CTestdlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CTestdlg::OnBnClickedButton1)
	ON_WM_PAINT()
	ON_EN_CHANGE(IDC_EDIT3, &CTestdlg::OnEnChangeEdit3)
END_MESSAGE_MAP()


// CTestdlg 消息处理程序


void CTestdlg::OnBnClickedElli()
{
	// TODO: 在此添加控件通知处理程序代码
	m_shape = false;
	UpdateData(true);
	Invalidate();
}


void CTestdlg::OnBnClickedRect()
{
	// TODO: 在此添加控件通知处理程序代码
	m_shape = true;
	UpdateData(true);
	Invalidate();
}


void CTestdlg::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_red=1-m_red;
	UpdateData(true);
	Invalidate();
}


void CTestdlg::OnBnClickedCheck2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_green=1-m_green;
	UpdateData(true);
	Invalidate();
}


void CTestdlg::OnBnClickedCheck3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_blue=1-m_blue;
	UpdateData(true);
	Invalidate();
}


BOOL CTestdlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_red = 0;
	m_green = 0;
	m_blue = 0;
	m_line = 3;
	m_index = 2;
	m_CtrlSlider1.SetRange(1,6);
	m_CtrlSlider1.SetTicFreq(1);
	m_CtrlSlider1.SetPos(3);
	
	((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(2);
	((CEdit*)GetDlgItem(IDC_EDIT1))->SetWindowTextW(L"YOUR_NAME");
	((CEdit*)GetDlgItem(IDC_EDIT2))->SetWindowTextW(L"YOUR_ID");
	
	CString str1,str2;
	str1.Format(L"%d",right);
	str2.Format(L"%d",bottom);
	((CEdit*)GetDlgItem(IDC_EDIT3))->SetWindowTextW(str1);
	((CEdit*)GetDlgItem(IDC_EDIT4))->SetWindowTextW(str2);
	
	return TRUE;  // return TRUE unless you set the focus to a control
}


void CTestdlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	m_line = m_CtrlSlider1.GetPos();
	UpdateData(true);
	
	*pResult = 0;
	
}


void CTestdlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex = ((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel(); //当前选中的项  
	m_index = nIndex;
	((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(nIndex); //设置第nIndex项为显示的内容 
	UpdateData(true);
	Invalidate();
}


void CTestdlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CColorDialog dlg;
	if(dlg.DoModal()==IDOK)
	{
		
		COLORREF m_color = dlg.GetColor();
		UpdateData(true);
	}
	Invalidate();
}


void CTestdlg::OnPaint()
{
	CPaintDC dc(this);
	CPen myPen(PS_SOLID,m_line,RGB(255*m_red,255*m_green,255*m_blue));
	dc.SelectObject(myPen);

	CBrush myBrush;
	
	if(m_index==0)
	{
		
		myBrush.CreateHatchBrush(HS_VERTICAL,m_color);
	}
	if(m_index==1)
	{
		myBrush.CreateHatchBrush(HS_HORIZONTAL,m_color);
	}
	if(m_index==2)
	{
		myBrush.CreateHatchBrush(HS_DIAGCROSS,RGB(0,0,255));
	}
	
	dc.SelectObject(myBrush);
	int r=50,x_pos=420,y_pos=230;
	if(m_shape == false)
		dc.Ellipse(x_pos-r,y_pos-r,x_pos+r,y_pos+r);
	else 
		dc.Rectangle(x_pos-r,y_pos-r,x_pos+r,y_pos+r);
}


void CTestdlg::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
