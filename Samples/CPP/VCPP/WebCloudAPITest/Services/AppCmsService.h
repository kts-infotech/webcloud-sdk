#pragma once
#include <afxstr.h>
#include "../Include/JSONvalue.h"
#include "AppApiService.h"

class MenuInfo
{
public:
         int MenuID;
        int ParentID;
        CString MenuName;
        bool ShowMenu;
        CString MenuLink;
        CString AliasURLLink;
        CString PageHeading;
        bool Success;
        CString ErrorDec;
    
};  
class SEOSocialSharingSettings
{
public:
    bool EnableSocialSharing;
    bool EnableFbSharing;
    bool EnableTwitterSharing;
    bool EnableGooglePlusSharing;
    bool EnableWhatsAppSharing;
    bool EnableFTOSharing;
    CString ImangeUrl; 
};
class SeoPageDetails
{
public:
    int MenuID;
    CString DefaultPageTitle;
    CString DefaultMetaDescription;
    CString DefaultMetaKeywords;
    bool IsAliasingEnabled;
    bool UseDefaultSeoDetails;
    SEOSocialSharingSettings SocialSharingSettings;
    bool Success;
    CString ErrorDec;
};
class LinkDetails
{
public:
    CString MenuID;
    CString MenuName;
    CString LinkID;
    CString LinkName;
    CString LinkUrl;
    CString OrderNo;
    int iOrderNo;
};
class LinkSettingsInfo
{
public:
    CString InternalLinkTitle;
    CString ExternalLinkTitle;
    bool ShowExternalLinks;
    bool ShowInternalLink;
    bool Success;
    CString ErrorDec;
    LinkDetails linkinfo;
};
class FooterDetails
{
public:
   CString MenuID;
   CString LinkID;
   CString LinkName;
};
class HeaderDetails
{
public:
    CString MenuID;
    CString LinkID;
    CString LinkName;
};