#pragma once
#include <afx.h>
class CStudent :
    public CObject
{
public:
    CStudent() {};
    virtual ~CStudent() {};
    CString m_id;
    CString m_name;
    CString m_place_of_origin;
    CString m_ethnicity;
    CString m_age;
    CString m_gender;
    CStudent(CString id,CString name,
        CString place_of_origin,
        CString ethnicity,CString age,
        CString gender) {
        m_id = id;
        m_name = name;
        m_place_of_origin = place_of_origin;
        m_ethnicity = ethnicity;
        m_age = age;
        m_gender = gender;
    }
};

