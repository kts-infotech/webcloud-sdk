#include "pch.h"
#include "AppApiService.h"

AppApiService::AppApiService(ApiEvents* pApiEvents)
{
	m_pApiEvents = pApiEvents;
}
void AppApiService::SetAPIURL(CString strURL)
{
	m_strBaseAPIURL = strURL;
	
}

void AppApiService::OnResponseData(CString Data)
{
	m_pApiEvents->OnResponseData(Data);
}

void AppApiService::OnRequestData(CString Data)
{
	m_pApiEvents->OnRequestData(Data);
}
void AppApiService :: OnStatusMessage(CString Message)
{
	m_pApiEvents->OnStatusMessage(Message);
}
