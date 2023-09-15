// UserList.cpp : implementation file
//

#include "pch.h"
#include "WebCloudAPITest.h"
#include "UserList.h"
#include "afxdialogex.h"


// UserList dialog

IMPLEMENT_DYNAMIC(UserList, CDialogEx)

UserList::UserList(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

UserList::~UserList()
{
}

void UserList::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UserList, CDialogEx)
	ON_COMMAND(ID_FILE_NEW, &UserList::OnUserList)
END_MESSAGE_MAP()


// UserList message handlers


void UserList::OnUserList()
{
	this->DoModal();
}
