// CMyDialog.cpp: ʵ���ļ�
//

#include "pch.h"
#include "EditBox.h"
#include "CMyDialog.h"
#include "afxdialogex.h"


// CMyDialog �Ի���

IMPLEMENT_DYNAMIC(CMyDialog, CDialogEx)

CMyDialog::CMyDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, txt_str);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialogEx)
	//ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &CMyDialog::OnClickedMfccolorbutton1)
	//ON_BN_CLICKED(IDC_BUTTON1, &CMyDialog::OnClickedButton1)
	//ON_BN_CLICKED(IDC_BUTTON2, &CMyDialog::OnClickedButton2)
	ON_BN_CLICKED(IDOK, &CMyDialog::OnBnClickedOk)
	//	ON_EN_CHANGE(IDC_EDIT1, &CMyDialog::OnChangeEdit1)
	//	ON_EN_CHANGE(IDC_EDIT2, &CMyDialog::OnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &CMyDialog::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CMyDialog ��Ϣ�������

/*
void CMyDialog::OnClickedMfccolorbutton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMyDialog::OnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	// ���ؼ���ֵ��ֵ����Ա����
	UpdateData(1);
	// ����Ա������ֵ��ֵ���ؼ�
	UpdateData(0);
}
*/
/*
void CMyDialog::OnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	text_str = "Ĭ�����";
	// ���ÿؼ�����ʾ����ɫ
	// ����Ա������ֵ��ֵ���ؼ�
	UpdateData(0);
}
*/

void CMyDialog::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}






void CMyDialog::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
