
// CalculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


// CCalculatorDlg 对话框



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, cur_num(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_stage = 0;
	m_num1 = "0";
	m_num2 = "0";
	m_oper = 0;
	m_preoper = 0;
	m_div0 = 0;
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, cur_num);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DIG1, &CCalculatorDlg::OnBnClickedDig1)
	ON_BN_CLICKED(IDC_DIG3, &CCalculatorDlg::OnBnClickedDig3)
	ON_BN_CLICKED(IDC_DIG2, &CCalculatorDlg::OnBnClickedDig2)
	ON_BN_CLICKED(IDC_DIG4, &CCalculatorDlg::OnBnClickedDig4)
	ON_BN_CLICKED(IDC_DIG5, &CCalculatorDlg::OnBnClickedDig5)
	ON_BN_CLICKED(IDC_DIG6, &CCalculatorDlg::OnBnClickedDig6)
	ON_BN_CLICKED(IDC_DIG7, &CCalculatorDlg::OnBnClickedDig7)
	ON_BN_CLICKED(IDC_DIG8, &CCalculatorDlg::OnBnClickedDig8)
	ON_BN_CLICKED(IDC_DIG9, &CCalculatorDlg::OnBnClickedDig9)
	ON_BN_CLICKED(IDC_DIG0, &CCalculatorDlg::OnBnClickedDig0)
	ON_BN_CLICKED(IDC_DOT, &CCalculatorDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_PLUS, &CCalculatorDlg::OnBnClickedPlus)
	ON_BN_CLICKED(IDC_EQU, &CCalculatorDlg::OnBnClickedEqu)
	ON_BN_CLICKED(IDC_AC, &CCalculatorDlg::OnBnClickedAc)
	ON_BN_CLICKED(IDC_MINUS, &CCalculatorDlg::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_MUL, &CCalculatorDlg::OnBnClickedMul)
	ON_BN_CLICKED(IDC_DIV, &CCalculatorDlg::OnBnClickedDiv)
END_MESSAGE_MAP()


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// calculate res of num1 and num2
void CCalculatorDlg::calc(int a)
{
	// TODO: 在此处添加实现代码.
	m_num2 = cur_num;
	double n1, n2, n = 0.0;
	n1 = _tstof(m_num1);
	n2 = _tstof(m_num2);
	switch (a) {
		case ADD_OPERATION:
			n = n1 + n2;
			break;
		case SUB_OPERATION:
			n = n1 - n2;
			break;
		case MUL_OPERATION:
			n = n1 * n2;
			break;
		case DIV_OPERATION:
			if (n2 == 0.0) {
				cur_num = "Divisor cannot be 0";
				m_stage = 1;
			}
			else n = n1 / n2;
			break;
		default:
			break;
	}
	if (m_stage == 1)
		UpdateData(FALSE);
	else {
		if (n - (int)n == 0)
			cur_num.Format(_T("%.0f"), n);
		else cur_num.Format(_T("%f"), n);
	}
	m_preoper = 0;
}

void CCalculatorDlg::OnBnClickedDig1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_stage == 1) {
		cur_num = '0';
	}
	if (cur_num != '0') {
		cur_num += '1';
		m_stage = 2;
	}
	else {
		cur_num = '1';
		m_stage = 2;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedDig2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_stage == 1) {
		cur_num = '0';
	}
	if (cur_num != '0') {
		cur_num += '2';
		m_stage = 2;
	}
	else {
		cur_num = '2';
		m_stage = 2;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedDig3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_stage == 1) {
		cur_num = '0';
	}
	if (cur_num != '0') {
		cur_num += '3';
		m_stage = 2;
	}
	else {
		cur_num = '3';
		m_stage = 2;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedDig4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_stage == 1) {
		cur_num = '0';
	}
	if (cur_num != '0') {
		cur_num += '4';
		m_stage = 2;
	}
	else {
		cur_num = '4';
		m_stage = 2;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedDig5()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_stage == 1) {
		cur_num = '0';
	}
	if (cur_num != '0') {
		cur_num += '5';
		m_stage = 2;
	}
	else {
		cur_num = '5';
		m_stage = 2;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedDig6()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_stage == 1) {
		cur_num = '0';
	}
	if (cur_num != '0') {
		cur_num += '6';
		m_stage = 2;
	}
	else {
		cur_num = '6';
		m_stage = 2;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedDig7()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_stage == 1) {
		cur_num = '0';
	}
	if (cur_num != '0') {
		cur_num += '7';
		m_stage = 2;
	}
	else {
		cur_num = '7';
		m_stage = 2;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedDig8()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_stage == 1) {
		cur_num = '0';
	}
	if (cur_num != '0') {
		cur_num += '8';
		m_stage = 2;
	}
	else {
		cur_num = '8';
		m_stage = 2;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedDig9()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_stage == 1) {
		cur_num = '0';
	}
	if (cur_num != '0') {
		cur_num += '9';
		m_stage = 2;
	}
	else {
		cur_num = '9';
		m_stage = 2;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedDig0()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_stage == 1) {
		cur_num = '0';
	}
	if (cur_num != '0') {
		cur_num += '0';
	}
	else cur_num = '0';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedDot()
{
	// TODO: 在此添加控件通知处理程序代码
	if (cur_num != '0') {
		cur_num += '.';
		if (m_stage == 1) {
			cur_num = "0.";
			m_stage = 2;
		}
	}
	else {
		cur_num = "0.";
		m_stage = 2;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedPlus()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_preoper) {
		m_num2 = cur_num;
		calc(m_oper);
	}
	m_oper = ADD_OPERATION;
	m_preoper = m_oper;
	m_num1 = cur_num;
	cur_num = '0';
}


void CCalculatorDlg::OnBnClickedEqu()
{
	// TODO: 在此添加控件通知处理程序代码
	calc(m_oper);
	m_stage = 1;
}



void CCalculatorDlg::OnBnClickedAc()
{
	// TODO: 在此添加控件通知处理程序代码
	cur_num = '0';
	m_oper = m_preoper = 0;
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedMinus()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_preoper) {
		m_num2 = cur_num;
		calc(m_oper);
	}
	m_oper = SUB_OPERATION;
	m_preoper = m_oper;
	m_num1 = cur_num;
	cur_num = '0';
}


void CCalculatorDlg::OnBnClickedMul()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_preoper) {
		m_num2 = cur_num;
		calc(m_oper);
	}
	m_oper = MUL_OPERATION;
	m_preoper = m_oper;
	m_num1 = cur_num;
	cur_num = '0';
}


void CCalculatorDlg::OnBnClickedDiv()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_preoper) {
		m_num2 = cur_num;
		calc(m_oper);
	}
	m_oper = DIV_OPERATION;
	m_preoper = m_oper;
	m_num1 = cur_num;
	cur_num = '0';
}
