#pragma once


// CVoiceChatForm dialog

class CVoiceChatForm : public CDialogEx
{
	DECLARE_DYNAMIC(CVoiceChatForm)

public:
	CVoiceChatForm(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CVoiceChatForm();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_VOICECHATFORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
