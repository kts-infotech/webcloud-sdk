/*---------------------------------------------------------------------------
	$Workfile: CSentemailform.h $

	Description: Header file for CSentemailform class.

	Copyright (C) 2022 KTS InfoTech
	All rights reserved.

   Author: Jayakrishnan P
	Last $Modtime: 15/06/2022  $
	Last $Revision:  $
	$History: $
---------------------------------------------------------------------------*/
#pragma once
// CSentemailform dialog
#include "Services/AppCommService.h"

class CSentemailform : public CDialogEx
{
	DECLARE_DYNAMIC(CSentemailform)

public:
	CSentemailform(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSentemailform();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SENDEMAILFORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonEmailAttachment();
	afx_msg void OnBnClickedButtonSendemailSend();
	CString strFilePath;
	MailInfo m_mailInfo;
private:
	
	CArray<AttachmentInfo, AttachmentInfo> m_attchmentList;
};

