#pragma once
#include <afxdialogex.h>
#include "CStudent.h"
class MyDlg :
    public CDialogEx
{
    DECLARE_DYNAMIC(MyDlg)
public:
    MyDlg(CWnd* pParent = nullptr);
    virtual ~MyDlg() {};
#ifdef AFX_DESIGN_TIME
    enum{IDD=IDD_DIALOG1};
#endif
    CComboBox m_ctrlgender;
    CString m_gender;
    CStatic m_ctrldisplay;
    CRect rect;
    CString m_stu_id;
    CListBox m_ctrlList;
    CString m_name;
    CString m_age;
    CString m_place_of_origin;
    CString m_ethnicity;
    int flag;
    POSITION m_pos;
    afx_msg void OnClickedAdd();
    afx_msg void OnClickedClose();
    afx_msg void OnClickedPrevious();
    afx_msg void OnClickedNext();
    void OnDestroy();
    //afx_msg void OnClickedCheck();
    afx_msg void OnStnClickedPicture();
    //afx_msg void OnCbnSelChangeGender();
    virtual BOOL OnInitDialog();
    afx_msg void OnPaint();
    void OnSelChangeNumber();
    void OnEditChangeNumber();
    afx_msg void OnCbnSelChangeCombo();
private:
    CTypedPtrList <CObList, CStudent*> m_pDataList;
protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnCbnSelchangeGender();
};

