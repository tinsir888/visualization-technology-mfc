#include "pch.h"
#include "MyDlg.h"
#include "PersonalInfo.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_gender(_T(""))
	, m_stu_id(_T(""))
	, m_name(_T(""))
	, m_place_of_origin(_T(""))
	, m_ethnicity(_T(""))
	, m_age(_T(""))
{
	m_gender = "female";
	m_stu_id = "2020200";
	m_name = "Anna";
	m_place_of_origin = "Deutschland";
	m_ethnicity = "Germania";
	m_age = "22";
}
BEGIN_MESSAGE_MAP(MyDlg,CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_ADD,&MyDlg::OnClickedAdd)
	ON_BN_CLICKED(IDC_CLOSE, &MyDlg::OnClickedClose)
	ON_BN_CLICKED(IDC_PREVIOUS, &MyDlg::OnClickedPrevious)
	ON_BN_CLICKED(IDC_NEXT, &MyDlg::OnClickedNext)
	ON_STN_CLICKED(AFX_IDC_PICTURE, &MyDlg::OnStnClickedPicture)
	ON_CBN_SELCHANGE(IDC_GENDER, &MyDlg::OnCbnSelchangeGender)
END_MESSAGE_MAP()

void MyDlg::DoDataExchange(CDataExchange* pDX){
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_GENDER, m_gender);
	DDX_Control(pDX, IDC_GENDER, m_ctrlgender);
	//DDX_Control(pDX,IDC_PICTURE,m_ctrldisplay);
	//DDV_MaxChars(pDX,m_gender,10);
	DDX_Text(pDX, IDC_IDNUM, m_stu_id);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Control(pDX, IDC_LIST1, m_ctrlList);
	DDX_Text(pDX, IDC_AGE, m_age);
	DDX_Text(pDX, IDC_ETHNICITY, m_ethnicity);
	DDX_Text(pDX, IDC_POO, m_place_of_origin);
}

BOOL MyDlg::OnInitDialog() {
	CDialogEx::OnInitDialog();
	m_ctrldisplay.GetWindowRect(&rect);
	ScreenToClient(&rect);
	m_ctrlgender.SetCurSel(0);
	m_ctrlgender.GetLBText(0, m_gender);
	m_pos = NULL;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void MyDlg::OnPaint() {
	if (!IsIconic()) {
		CPaintDC dc(this);
		dc.SetBkMode(TRANSPARENT);
		dc.SetTextColor(RGB(0, 0, 255));
		dc.TextOut(rect.left + 20, rect.top + 20, m_gender);
		CDialogEx::OnPaint();
	}
}

void MyDlg::OnSelChangeNumber() {
	m_ctrlgender.GetLBText(m_ctrlgender.GetCurSel(), m_gender);
	InvalidateRect(&rect);
}

void MyDlg::OnEditChangeNumber() {
	m_ctrlgender.GetWindowText(m_gender);
	InvalidateRect(&rect);
}

void MyDlg::OnClickedAdd() {
	UpdateData(true);
	if (m_stu_id.GetLength() == 0) {
		MessageBox(L"ID can't be empty!");
		(CEdit*)GetDlgItem(IDC_IDNUM)->SetFocus();
		return;
	}
	if (m_name.GetLength() == 0) {
		MessageBox(L"ID can't be empty!");
		(CEdit*)GetDlgItem(IDC_NAME)->SetFocus();
		return;
	}
	CStudent* pStudent;//add node into list
	pStudent = new CStudent(m_stu_id, m_name, m_place_of_origin, 
		m_ethnicity, m_age, m_gender);
	m_pDataList.AddTail(pStudent);
	m_pos = m_pDataList.GetTailPosition();
	CString tmp;
	tmp = m_stu_id + " " + m_name + " " + m_gender + " " + m_place_of_origin +
		" " + m_ethnicity + " " + m_age;
	m_ctrlList.AddString(tmp);
	m_ctrlList.SetCurSel(m_ctrlList.GetCount() - 1);
}

void MyDlg::OnClickedClose() {
	if (MessageBox(L"Close Dialog?", L"Close",
		MB_OKCANCEL | MB_ICONQUESTION) == IDOK)
		CDialog::OnCancel();
}

void MyDlg::OnClickedPrevious() {
	if (m_pos != NULL) {
		//calc last record pos in list
		if (m_pos == m_pDataList.GetHeadPosition())
			m_pos = m_pDataList.GetTailPosition();
		else m_pDataList.GetPrev(m_pos);
		CStudent* pStudent = m_pDataList.GetAt(m_pos);
		//get last record in list
		m_stu_id = pStudent->m_id;
		m_name = pStudent->m_name;
		m_place_of_origin = pStudent->m_place_of_origin;
		m_age = pStudent->m_age;
		m_gender = pStudent->m_gender;
		m_ethnicity = pStudent->m_ethnicity;
		UpdateData(false);
		//calc last record in listbox and select it.
		int pos = m_ctrlList.GetCurSel();
		if (pos == 0)
			pos = m_ctrlList.GetCount() - 1;
		else pos--;
		m_ctrlList.SetCurSel(pos);
	}
	else MessageBox(L"No item!");
}

void MyDlg::OnClickedNext() {
	if (m_pos != NULL) {
		//calc last record pos in list
		if (m_pos == m_pDataList.GetTailPosition())
			m_pos = m_pDataList.GetHeadPosition();
		else m_pDataList.GetNext(m_pos);
		CStudent* pStudent = m_pDataList.GetAt(m_pos);
		//get last record in list
		m_stu_id = pStudent->m_id;
		m_name = pStudent->m_name;
		m_place_of_origin = pStudent->m_place_of_origin;
		m_age = pStudent->m_age;
		m_gender = pStudent->m_gender;
		m_ethnicity = pStudent->m_ethnicity;
		UpdateData(false);
		//calc last record in listbox and select it.
		int pos = m_ctrlList.GetCurSel();
		if (pos == m_ctrlList.GetCount()-1)
			pos = 0;
		else pos++;
		m_ctrlList.SetCurSel(pos);
	}
	else MessageBox(L"No item!");
}

void MyDlg::OnDestroy() {
	if (!m_pDataList.IsEmpty()) {
		delete m_pDataList.RemoveHead();
	}
}

void MyDlg::OnStnClickedPicture() {
	//TODO!
}

void MyDlg::OnCbnSelchangeGender()
{
	// TODO: 在此添加控件通知处理程序代码
}
