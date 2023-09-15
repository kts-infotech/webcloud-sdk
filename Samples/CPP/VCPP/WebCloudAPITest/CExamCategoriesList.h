#pragma once
#include"Include/Httprequest.hpp" 
#include"Include/JSONvalue.h"
#include"Include/JSON.h"

// CExamCategoriesList dialog

class CExamCategoriesList : public CDialogEx
{
	DECLARE_DYNAMIC(CExamCategoriesList)

public:
	CExamCategoriesList(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CExamCategoriesList();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_EXAMCOTEGORIES};
#endif
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	
};
