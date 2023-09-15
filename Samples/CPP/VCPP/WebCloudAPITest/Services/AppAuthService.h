#pragma once
class ApiAccessInfo
{
public:
    ApiAccessInfo()
    {

    }
    bool CallChatSupport;
    bool CloudBackupSupport;
    bool ECommSupport;
    bool ExamSupport;
    bool RealTimeNotificationSupport;
    bool TechSupport;
    bool TimeTrackerSupport;
};

class AuthInfo
{
public:
    AuthInfo()
    {

    }
    ApiAccessInfo AccessInfo;
    CString AuthenticationToken;
    bool IsAdmin;
    CString UserID;
};

