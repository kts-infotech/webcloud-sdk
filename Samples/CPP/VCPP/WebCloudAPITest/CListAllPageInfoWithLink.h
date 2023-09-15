#pragma once
#include"Include/Httprequest.hpp" 
#include"Include/JSONvalue.h"
#include"Include/JSON.h"

// CListAllPageInfoWithLink dialog

class CListAllPageInfoWithLink : public CDialogEx
{
    DECLARE_DYNAMIC(CListAllPageInfoWithLink)

public:
    CString strUrl = _T("http://test2.virtualtutor.co.in/");
    CListAllPageInfoWithLink(CWnd* pParent = nullptr);   // standard constructor
    virtual ~CListAllPageInfoWithLink();

    // Dialog Data
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_DIALOG_LISTALLPAGEINFOWITHLINKS };
#endif


    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_MESSAGE_MAP()
public:
    void GetAllPageInfoValue();
    virtual BOOL OnInitDialog();

    CArray<int>m_Menuid;
    afx_msg void OnBnClickedClose();
    CEdit MENUID;
private:
    AppApiService* m_apiService;
    CArray<MenuInfo, MenuInfo> m_infoArray;
    MenuInfo infomenu;
   
public:
    CListCtrl m_listctrl;
};
    