#pragma once


// CMyDialog �Ի���

class CMyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDialog)

public:
	CMyDialog(CWnd* pParent = nullptr);   // ��׼���캯��
	virtual ~CMyDialog();

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnClickedMfccolorbutton1();
	//afx_msg void OnClickedButton1();
	//afx_msg void OnClickedButton2();
	afx_msg void OnBnClickedOk();
	CString txt_str;

	afx_msg void OnEnChangeEdit1();
};
