
// CalculatorDlg.h: 头文件
//
#define ADD_OPERATION 1
#define SUB_OPERATION 2
#define MUL_OPERATION 3
#define DIV_OPERATION 4
#pragma once


// CCalculatorDlg 对话框
class CCalculatorDlg : public CDialogEx
{
// 构造
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// current number in calculator edit box
	CString cur_num;
	// count calculation stage
	int m_stage;
	CString m_num1;
	CString m_num2;
	/* 
	current operation
	default:0
	+:1 -:2 *:3 /:4
	*/
	int m_oper;
	// last operation
	int m_preoper;
	// judge whether div zero
	int m_div0;
	// calculate res of num1 and num2
	void calc(int a);
	afx_msg void OnBnClickedDig1();
	afx_msg void OnBnClickedDig2();
	afx_msg void OnBnClickedDig3();
	afx_msg void OnBnClickedDig4();
	afx_msg void OnBnClickedDig5();
	afx_msg void OnBnClickedDig6();
	afx_msg void OnBnClickedDig7();
	afx_msg void OnBnClickedDig8();
	afx_msg void OnBnClickedDig9();
	afx_msg void OnBnClickedDig0();
	afx_msg void OnBnClickedDot();
	afx_msg void OnBnClickedPlus();
	afx_msg void OnBnClickedEqu();
	afx_msg void OnBnClickedAc();
	afx_msg void OnBnClickedMinus();
	afx_msg void OnBnClickedMul();
	afx_msg void OnBnClickedDiv();
};
