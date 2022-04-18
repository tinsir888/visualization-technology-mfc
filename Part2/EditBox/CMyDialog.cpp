// CMyDialog.cpp: 实现文件
//

#include "pch.h"
#include "EditBox.h"
#include "CMyDialog.h"
#include "afxdialogex.h"


// CMyDialog 对话框

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


// CMyDialog 消息处理程序

/*
void CMyDialog::OnClickedMfccolorbutton1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMyDialog::OnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	// 将控件的值赋值给成员变量
	UpdateData(1);
	// 将成员变量的值赋值给控件
	UpdateData(0);
}
*/
/*
void CMyDialog::OnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	text_str = "默认输出";
	// 设置控件上显示的颜色
	// 将成员变量的值赋值给控件
	UpdateData(0);
}
*/

void CMyDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}






void CMyDialog::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
