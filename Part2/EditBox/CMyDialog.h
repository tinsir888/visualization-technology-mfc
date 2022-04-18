#pragma once


// CMyDialog 对话框

class CMyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDialog)

public:
	CMyDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMyDialog();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnClickedMfccolorbutton1();
	//afx_msg void OnClickedButton1();
	//afx_msg void OnClickedButton2();
	afx_msg void OnBnClickedOk();
	CString txt_str;

	afx_msg void OnEnChangeEdit1();
};
