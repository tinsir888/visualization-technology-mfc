#pragma once


// CTestdlg 对话框

class CTestdlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTestdlg)

public:
	CTestdlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTestdlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedElli();
	bool m_shape;
	afx_msg void OnBnClickedRect();
	afx_msg void OnBnClickedCheck1();
	int m_red;
	afx_msg void OnBnClickedCheck2();
	int m_green;
	afx_msg void OnBnClickedCheck3();
	int m_blue;
	CSliderCtrl m_CtrlSlider1;
	virtual BOOL OnInitDialog();
	int m_line;
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	CString m_Fill;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton1();
	COLORREF m_color;
	int right;
	int bottom;
	afx_msg void OnPaint();
	int m_index;
	afx_msg void OnEnChangeEdit3();
};
