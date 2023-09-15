/*********************************************************************
   Workfile : AppForumService.cpp
   Description : Implementation of  AppForumService.cpp
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 9 August 2022
 *********************************************************************/
#include "pch.h"
#include "AppApiService.h"
/***************************************************************
  Function Name : GetAllForums
  Return Type : void
  Parameters : InfoArray 
  Remarks : Function to execute network call to get all forum names 
 **************************************************************/
void AppApiService::GetAllForums(CArray<FormDetailsInfo>& InfoArray)
{

	CString getAllForums = _T("Api/Forum/GetAllForums");
	OnStatusMessage(getAllForums);
	try
	{
		JSONValue *Jvalue = NetworkRequest::GetReqEx(getAllForums);
		std::wstring res = Jvalue->Stringify(true);
		OnResponseData(CString(res.c_str()));
		JSONArray root = Jvalue->AsArray();
		for (unsigned int i = 0; i < root.size(); i++)
		{
			JSONObject Jobj = root[i]->AsObject();
			FormDetailsInfo Info;
			Info.FormID=Jobj[L"FormID"]->AsString().c_str();
			Info.FormName= Jobj[L"FormName"]->AsString().c_str();
			Info.ForumType= Jobj[L"ForumType"]->AsString().c_str();
			Info.GroupEmail= Jobj[L"GroupEmail"]->AsString().c_str();
			Info.FormDesc= Jobj[L"FormDesc"]->AsString().c_str();
			Info.ErrorDesc= Jobj[L"FormDesc"]->AsString().c_str();
			Info.IsPrivate = Jobj[L"IsPrivate"]->AsBool();
			Info.IsThreadAdminOnly = Jobj[L"IsThreadAdminOnly"]->AsBool();
			Info.Success = Jobj[L"Success"]->AsBool();
			InfoArray.Add(Info);
		}

	}
	catch (const std::exception& e)
	{
		OnResponseData(CString(e.what()));
	}

}
/***************************************************************
  Function Name : GetAllForumIdWithNames
  Return Type : void
  Parameters : InfoArray 
  Remarks :Function to execute Network call to get all forum Id with names  
 **************************************************************/
void AppApiService::GetAllForumIdWithNames(CArray<ItemInfo>& InfoArray)
{
	CString getAllForums = _T("Api/Forum/GetAllForumIdWithNames");
	OnStatusMessage(getAllForums);
	try
	{
		JSONValue* jval = NetworkRequest::GetReqEx(getAllForums);
		std::wstring res = jval->Stringify(true);
		OnResponseData(CString(res.c_str()));
		JSONArray root = jval->AsArray();
		for (unsigned int i = 0; i < root.size(); i++)
		{
			JSONObject jobj = root[i]->AsObject();
			ItemInfo Info;
			Info.Text=jobj[L"Text"]->AsString().c_str();
			Info.Value= jobj[L"Value"]->AsNumber();
			InfoArray.Add(Info);
		}

	}
	catch (const std::exception& e)
	{
		OnResponseData(CString(e.what()));
	}
}
/***************************************************************
  Function Name : GetAllTopicsWithForumID
  Return Type : void
  Parameters : strForumId 
  Parameters : InfoArray 
  Remarks :  Function to execute Network call to get the names
			 of all topics by using forum Id
 **************************************************************/
void AppApiService::GetAllTopicsWithForumID(CString strForumId, CArray<ItemInfo>& InfoArray)
{

	try
	{
		CString getAllForumId;
		getAllForumId.Format(_T("Api/Forum/GetAllTopicsWithForumID?iForumId=%s"), strForumId);
		OnStatusMessage(getAllForumId);
		JSONValue* Jvalue = NetworkRequest::GetReqEx(getAllForumId);
		JSONArray root = Jvalue->AsArray();
		for (unsigned int i = 0; i < root.size(); i++)
		{
			JSONObject Jobj = root[i]->AsObject();
			ItemInfo Info;
			Info.Text=Jobj[L"Text"]->AsString().c_str();
			Info.Value = Jobj[L"Value"]->AsNumber();
			InfoArray.Add(Info);
		}

		std::wstring res = Jvalue->Stringify(true);
		OnResponseData(CString(res.c_str()));
	}
	catch (const std::exception& e)
	{
		OnResponseData(CString(e.what()));
	}
	
}
/***************************************************************
  Function Name : GetAllThreadsWithTopicID
  Return Type : void
  Parameters : strTopicID 
  Parameters : InfoArray 
  Remarks : Function to execute the Network call to get the 
			names of threads by using topic id 
 **************************************************************/
void AppApiService::GetAllThreadsWithTopicID(CString strTopicID, CArray<ItemInfo>& InfoArray)
{
	try {
		CString getAllThreads;
		getAllThreads.Format(_T("Api/Forum/GetAllThreadsWithTopicID?strTopicID=%s"), strTopicID);
		OnStatusMessage(getAllThreads);
		JSONValue* Jvalue = NetworkRequest::GetReqEx(getAllThreads);
		JSONArray root = Jvalue->AsArray();
		for (unsigned int i = 0; i < root.size(); i++)
		{
			JSONObject Jobj = root[i]->AsObject();
			ItemInfo Info;
			Info.Text = Jobj[L"Text"]->AsString().c_str();
			Info.Value = Jobj[L"Value"]->AsNumber();
			InfoArray.Add(Info);
		}

		std::wstring res = Jvalue->Stringify(true);
		OnResponseData(CString(res.c_str()));
	}
	catch (const std::exception& e)
	{
		OnResponseData(CString(e.what()));
	}
}
/***************************************************************
  Function Name : GetAllTopics
  Return Type : void
  Parameters : strTopicID 
  Parameters : InfoArray 
  Remarks :  Function to execute the Network call to get the 
			 topic names  
 **************************************************************/
void AppApiService::GetAllTopics(CArray<Topics>& InfoArray)
{
	CString getAllTopics = _T("Api/Forum/GetAllTopics");
	OnStatusMessage(getAllTopics);
	try
	{
		JSONValue* Jvalue = NetworkRequest::GetReqEx(getAllTopics);
		std::wstring res = Jvalue->Stringify(true);
		OnResponseData(CString(res.c_str()));
		JSONArray root = Jvalue->AsArray();
		for (unsigned int i = 0; i < root.size(); i++)
		{
			JSONObject jobj = root[i]->AsObject();
			Topics Info;
			Info.TopicID=jobj[L"TopicID"]->AsString().c_str();
			Info.ForumID = jobj[L"ForumID"]->AsString().c_str();
			Info.GroupEmail = jobj[L"GroupEmail"]->AsString().c_str();
			Info.TopicDesc = jobj[L"TopicDesc"]->AsString().c_str();
			Info.TopicName = jobj[L"TopicName"]->AsString().c_str();
			Info.ErrorDesc = jobj[L"ErrorDesc"]->AsString().c_str();
			Info.AdminApproval = jobj[L"AdminApproval"]->AsBool();
			Info.Success = jobj[L"Success"]->AsBool();
			InfoArray.Add(Info);
		}

	}
	catch (const std::exception& e)
	{
		OnResponseData(CString(e.what()));
	}
}
/***************************************************************
  Function Name : GetAllThreads
  Return Type : void
  Parameters : InfoArray 
  Remarks : Function to execute the Network call to get 
			the names of all threads 
 **************************************************************/
void AppApiService::GetAllThreads(CArray<ThreadDetailsInfo>& InfoArray)
{
	CString getAllThreads = _T("Api/Forum/GetAllThreads");
	OnStatusMessage(getAllThreads);
	try
	{
		JSONValue *Jvalue = NetworkRequest::GetReqEx(getAllThreads);
		std::wstring res = Jvalue->Stringify(true);
		OnResponseData(CString(res.c_str()));
		JSONArray root = Jvalue->AsArray();
		for (unsigned int i = 0; i < root.size(); i++)
		{
			JSONObject jobj = root[i]->AsObject();
			ThreadDetailsInfo Info;
			JSONObject Jobj_Thread = jobj[L"ftrDetails"]->AsObject();
			Info.ftrDetails.BugStatus = Jobj_Thread[L"BugStatus"]->AsString().c_str();
			Info.ftrDetails.ThreadAssigned= Jobj_Thread[L"ThreadAssigned"]->AsString().c_str();
			Info.ftrDetails.AuthorID= Jobj_Thread[L"AuthorID"]->AsString().c_str();
			Info.ftrDetails.PostedDate=Jobj_Thread[L"PostedDate"]->AsString().c_str();
			Info.ftrDetails.ThreadImagePth = Jobj_Thread[L"ThreadImagePth"]->IsNull() ? _T("") : Jobj_Thread[L"ThreadImagePth"]->AsString().c_str();
			JSONObject jobj_Thread = jobj[L"ForumInfo"]->AsObject();
			Info.ForumInfo.Text = jobj_Thread[L"Text"]->IsNull()?_T(""):jobj_Thread[L"Text"]->AsString().c_str();
			Info.ForumInfo.Value = jobj_Thread[L"Value"]->AsNumber();
			JSONObject jobj_thread = jobj[L"TopicInfo"]->AsObject();
			Info.TopicInfo.Text= jobj_thread[L"Text"]->IsNull()?_T(""):jobj_thread[L"Text"]->AsString().c_str();
			Info.TopicInfo.Value= jobj_thread[L"Value"]->AsNumber();
			Info.ThreadID = jobj[L"ThreadID"]->AsString().c_str();
			Info.ThreadName= jobj[L"ThreadName"]->AsString().c_str();
			Info.ThreadImage= jobj[L"ThreadImage"]->AsString().c_str();
			Info.UserName= jobj[L"UserName"]->AsString().c_str();
			Info.ThreadDesc= jobj[L"ThreadDesc"]->AsString().c_str();
			Info.ImageName= jobj[L"ImageName"]->AsString().c_str();
			Info.ErrorDesc= jobj[L"ErrorDesc"]->AsString().c_str();
			Info.Success= jobj[L"Success"]->AsBool();
			InfoArray.Add(Info);
		}

	}
	catch (const std::exception& e)
	{
		OnResponseData(CString(e.what()));
	}
}
/***************************************************************
  Function Name : DeleteThread
  Return Type : void
  Parameters : strThreadID 
  Parameters : ResponseMessage 
  Remarks :  Function to execute the Network call to delete a thread
 **************************************************************/
void AppApiService::DeleteThread(CString strThreadID, CString& ResponseMessage)
{
	try
	{
		CString deleteAThread;
		deleteAThread.Format(_T("Api/Forum/DeleteThread?strThreadID=%s"), strThreadID);
		OnStatusMessage(deleteAThread);
		JSONValue* Jvalue = NetworkRequest::GetReqEx(deleteAThread);
		std::wstring res = Jvalue->Stringify(true);
		CString cstrRes(res.c_str());
		OnResponseData(cstrRes);
		AfxMessageBox(cstrRes);
	}
	catch(const std::exception& e)
	{
		CString errorStr(e.what());
		OnResponseData(errorStr);
		AfxMessageBox(errorStr);
	}
}
/***************************************************************
  Function Name : DeleteForum
  Return Type : void
  Parameters : strForumID 
  Parameters : ResponseMessage 
  Remarks :  Function to execute the Network call to delete a forum
 **************************************************************/
void AppApiService::DeleteForum(CString strForumID, CString& ResponseMessage)
{
	CString DeleteForum;
	DeleteForum.Format(_T("Api/Forum/DeleteForum?strForumID=%s"), strForumID);
	try
	{
		JSONValue* Jvalue = NetworkRequest::GetReqEx(DeleteForum);
		std::wstring res = Jvalue->Stringify(true);
		CString cstrRes(res.c_str());
		OnResponseData(cstrRes);
		OnStatusMessage(DeleteForum);
		ResponseMessage = Jvalue->AsString().c_str();
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		OnResponseData(errorStr);
		AfxMessageBox(errorStr);
	}
}
/***************************************************************
  Function Name : DeleteTopic
  Return Type : void
  Parameters : strTopicID 
  Parameters : ResponseMessage 
  Remarks :  Function to execute the Network call to delete a topic
 **************************************************************/
void AppApiService::DeleteTopic(int strTopicID, CString& ResponseMessage)
{
	CString DeleteTopic;
	DeleteTopic.Format(_T("Api/Forum/DeleteTopic?strTopicID=%d"), strTopicID);
	JSONValue* Jvalue = NetworkRequest::GetReqEx(DeleteTopic);
	std::wstring res = Jvalue->Stringify(true);
	CString cstrRes(res.c_str());
	OnResponseData(cstrRes);
	OnStatusMessage(DeleteTopic);
	ResponseMessage = Jvalue->AsString().c_str();
}
/***************************************************************
  Function Name : AddForum
  Return Type : CString
  Parameters : Info 
  Remarks : Function to execute the Network call to add a forum
 **************************************************************/
CString AppApiService::AddForum(FormDetailsInfo Info)
{
	CString addForums = _T("Api/Forum/AddForum");
	CString dataAdd;
	JSONObject obj;
	obj[L"FormID"] = new JSONValue(Info.FormID);
	obj[L"FormName"] = new JSONValue(Info.FormName);
	obj[L"FormDesc"] = new JSONValue(Info.FormDesc);
	obj[L"GroupEmail"] = new JSONValue(Info.GroupEmail);
	obj[L"ForumType"] = new JSONValue(Info.ForumType);
	obj[L"IsPrivate"] = new JSONValue(Info.IsPrivate);
	obj[L"IsThreadAdminOnly"] = new JSONValue(Info.IsThreadAdminOnly);
	obj[L"Success"] = new JSONValue(Info.Success);
	obj[L"ErrorDesc"] = new JSONValue(Info.ErrorDesc);

	JSONValue* val = new JSONValue(obj);
	std::wstring res = val->Stringify(false);
	dataAdd = CString(res.c_str());

	try
	{
		OnStatusMessage(addForums);
		OnRequestData(dataAdd);
		JSONValue* jval = NetworkRequest::PostReq(addForums, dataAdd);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		OnResponseData(cstrRes);
		AfxMessageBox(cstrRes);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);


	}
	return CString();
}
/***************************************************************
  Function Name : UpdateForum
  Return Type : CString
  Parameters : Info 
  Remarks : Function to execute the Network call to update a forum 
 **************************************************************/
CString AppApiService::UpdateForum(FormDetailsInfo Info)
{
	CString updateForums = _T("Api/Forum/UpdateForum");
	CString dataUpdate;
	JSONObject obj;
	obj[L"FormID"] = new JSONValue(Info.FormID);
	obj[L"FormName"] = new JSONValue(Info.FormName);
	obj[L"FormDesc"] = new JSONValue(Info.FormDesc);
	obj[L"GroupEmail"] = new JSONValue(Info.GroupEmail);
	obj[L"ForumType"] = new JSONValue(Info.ForumType);
	obj[L"IsPrivate"] = new JSONValue(Info.IsPrivate);
	obj[L"IsThreadAdminOnly"] = new JSONValue(Info.IsThreadAdminOnly);
	obj[L"Success"] = new JSONValue(Info.Success);
	obj[L"ErrorDesc"] = new JSONValue(Info.ErrorDesc);

	JSONValue* val = new JSONValue(obj);
	std::wstring res = val->Stringify(false);
	dataUpdate = CString(res.c_str());


	try
	{
		CString updateForums = _T("Api/Forum/UpdateForum");
		OnStatusMessage(updateForums);
		OnRequestData(dataUpdate);
		JSONValue* jval = NetworkRequest::PostReq(updateForums, dataUpdate);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		OnResponseData(cstrRes);
		AfxMessageBox(cstrRes);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);
	}
	return CString();
}
/***************************************************************
  Function Name : GetExistingGroups
  Return Type : void
  Parameters : InfoArray 
  Remarks : Function to execute the Network call to get the
			list of all existing groups 
 **************************************************************/
void AppApiService::GetExistingGroups(CArray<UserCategotyInfo>& InfoArray)
{
	try
	{
		CString getExistingGroups = _T("Api/Forum/GetExistingGroups");
		OnStatusMessage(getExistingGroups);
		JSONValue* jvalue = NetworkRequest::GetReqEx(getExistingGroups);
		std::wstring res1 = jvalue->Stringify(true);
		CString cstrRes1(res1.c_str());
		OnResponseData(CString(res1.c_str()));
		JSONArray root2 = jvalue->AsArray();
		for (unsigned int i = 0; i < root2.size(); i++)
		{
			JSONObject jobj = root2[i]->AsObject();
			UserCategotyInfo Info;
			Info.CategoryID = jobj[L"CategoryID"]->AsString().c_str();
			Info.CategoryName = jobj[L"CategoryName"]->AsString().c_str();
			Info.ErrorDesc = jobj[L"ErrorDesc"]->AsString().c_str();
			Info.Success= jobj[L"Success"]->AsBool();
			InfoArray.Add(Info);
		}

	}
	catch (const std::exception& e)
	{
		OnResponseData(CString(e.what()));
	}
}
/***************************************************************
  Function Name : RetrieveEmail
  Return Type : CString
  Parameters : strGroupId 
  Remarks :  Function to execute the Network call to retrieve 
		     the Emails
 **************************************************************/
CString AppApiService::RetrieveEmail(CString strGroupId, CString& ResponseMessage)
{
	CString RetrieveEmail;
	RetrieveEmail.Format(_T("Api/Forum/RetrieveEmail?strGroupId=%s"),strGroupId);
	try
	{
		JSONValue* jval = NetworkRequest::GetReqEx(RetrieveEmail);
		std::wstring res = jval->AsString();
		CString cstrRes(res.c_str());
		OnStatusMessage(RetrieveEmail);
		OnResponseData(cstrRes);
		ResponseMessage=cstrRes;
		
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		OnResponseData(errorStr);
	}
	return CString();
}
/***************************************************************
  Function Name : AddTopics
  Return Type : CString
  Parameters : Info 
  Remarks :  Function to execute the Network call to add a topic
 **************************************************************/
CString AppApiService::AddTopics(Topics Info)
{
	JSONObject obj1;
	obj1[L"TopicID"] = new JSONValue(Info.TopicID);
	obj1[L"ForumID"] = new JSONValue(Info.ForumID);
	obj1[L"GroupEmail"] = new JSONValue(Info.GroupEmail);
	obj1[L"TopicName"] = new JSONValue(Info.TopicName);
	obj1[L"TopicDesc"] = new JSONValue(Info.TopicDesc);
	obj1[L"ErrorDesc"] = new JSONValue(Info.ErrorDesc);
	CString dataAdd;
	JSONValue* val = new JSONValue(obj1);
	std::wstring res = val->Stringify(false);
	dataAdd = CString(res.c_str());
	CString addTopics = _T("Api/Forum/AddTopics");
	try
	{
		OnRequestData(dataAdd);
		JSONValue* jval = NetworkRequest::PostReq(addTopics, dataAdd);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		OnResponseData(cstrRes);
		AfxMessageBox(cstrRes);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);
	}
	return CString();
}
/***************************************************************
  Function Name : UpdateTopic
  Return Type : CString
  Parameters : Info 
  Remarks :  Function to execute the Network call to update a topic
 **************************************************************/
CString AppApiService::UpdateTopic(Topics Info)
{
	CString updateTopic = _T("Api/Forum/UpdateTopic");
	CString dataUpdate;
	JSONObject obj;
	obj[L"TopicID"] = new JSONValue(Info.TopicID);
	obj[L"ForumID"] = new JSONValue(Info.ForumID);
	obj[L"GroupEmail"] = new JSONValue(Info.GroupEmail);
	obj[L"TopicName"] = new JSONValue(Info.TopicName);
	obj[L"TopicDesc"] = new JSONValue(Info.TopicDesc);
	obj[L"AdminApproval"] = new JSONValue(Info.AdminApproval);
	obj[L"Success"] = new JSONValue(Info.Success);
	obj[L"ErrorDesc"] = new JSONValue(Info.ErrorDesc);

	JSONValue* val = new JSONValue(obj);
	std::wstring res = val->Stringify(false);
	dataUpdate = CString(res.c_str());

	try
	{
		OnStatusMessage(dataUpdate);
		JSONValue* jval = NetworkRequest::PostReq(updateTopic, dataUpdate);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		OnResponseData(cstrRes);
		AfxMessageBox(cstrRes);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);
	}
	return CString();
}
/***************************************************************
  Function Name : AddThread
  Return Type : CString
  Parameters : trd 
  Remarks :  Function to execute the Network call to add a thread
 **************************************************************/
CString AppApiService::AddThread(ThreadDetailsInfo trd)
{
	CString updateThreads = _T("Api/Forum/AddThread");
	JSONObject ftrDetails;
	ftrDetails[L"BugStatus"] = new JSONValue(trd.ftrDetails.BugStatus);
	ftrDetails[L"ThreadAssigned"] = new JSONValue(trd.ftrDetails.ThreadAssigned);
	ftrDetails[L"PostedDate"] = new JSONValue(trd.ftrDetails.PostedDate);
	ftrDetails[L"AuthorID"] = new JSONValue(trd.ftrDetails.AuthorID);
	ftrDetails[L"ThreadImagePth"] = new JSONValue(trd.ftrDetails.ThreadImagePth);

	ftrDetails[L"ThreadImagePth"] = new JSONValue(trd.ftrDetails.ThreadImagePth);

	JSONObject ThreadDetailsInfo;
	ThreadDetailsInfo[L"ftrDetails"] = new JSONValue(ftrDetails);

	JSONObject ItemInfo;
	ItemInfo[L"Text"] = new JSONValue(trd.ForumInfo.Text);
	ItemInfo[L"Value"] = new JSONValue(trd.ForumInfo.Value);
	ThreadDetailsInfo[L"ForumInfo"] = new JSONValue(ItemInfo);

	JSONObject ItemInfo1;
	ItemInfo1[L"Text"] = new JSONValue(trd.TopicInfo.Text);
	ItemInfo1[L"Value"] = new JSONValue(trd.TopicInfo.Value);
	ThreadDetailsInfo[L"TopicInfo"] = new JSONValue(ItemInfo1);

	ThreadDetailsInfo[L"ThreadID"] = new JSONValue(trd.ThreadID);
	ThreadDetailsInfo[L"ThreadName"] = new JSONValue(trd.ThreadName);
	ThreadDetailsInfo[L"UserName"] = new JSONValue(trd.UserName);
	ThreadDetailsInfo[L"ThreadDesc"] = new JSONValue(trd.ThreadDesc);

	ThreadDetailsInfo[L"ThreadImage"] = new JSONValue(trd.ThreadImage);
	ThreadDetailsInfo[L"ImageName"] = new JSONValue(trd.ImageName);

	ThreadDetailsInfo[L"Success"] = new JSONValue(trd.Success);
	ThreadDetailsInfo[L"ErrorDesc"] = new JSONValue(trd.ErrorDesc);

	JSONValue* val = new JSONValue(ThreadDetailsInfo);
	std::wstring res = val->Stringify(false);
	CString dataUpdate = CString(res.c_str());

	try
	{
		OnRequestData(dataUpdate);
		JSONValue* jval = NetworkRequest::PostReq(updateThreads, dataUpdate);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		OnResponseData(cstrRes);
		AfxMessageBox(cstrRes);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);
	}

	return CString();
}
/***************************************************************
  Function Name : UpdateThread
  Return Type : CString
  Parameters : trd 
  Remarks :  Function to execute the Network call to update a thread
 **************************************************************/
CString AppApiService::UpdateThread(ThreadDetailsInfo trd)
{
	CString updateThreads = _T("Api/Forum/UpdateThread");
	JSONObject ftrDetails;
	ftrDetails[L"BugStatus"] = new JSONValue(trd.ftrDetails.BugStatus);
	ftrDetails[L"ThreadAssigned"] = new JSONValue(trd.ftrDetails.ThreadAssigned);
	ftrDetails[L"PostedDate"] = new JSONValue(trd.ftrDetails.PostedDate);
	ftrDetails[L"AuthorID"] = new JSONValue(trd.ftrDetails.AuthorID);
	ftrDetails[L"ThreadImagePth"] = new JSONValue(trd.ftrDetails.ThreadImagePth);

	ftrDetails[L"ThreadImagePth"] = new JSONValue(trd.ftrDetails.ThreadImagePth);

	JSONObject ThreadDetailsInfo;
	ThreadDetailsInfo[L"ftrDetails"] = new JSONValue(ftrDetails);

	JSONObject ItemInfo;
	ItemInfo[L"Text"] = new JSONValue(trd.ForumInfo.Text);
	ItemInfo[L"Value"] = new JSONValue(trd.ForumInfo.Value);
	ThreadDetailsInfo[L"ForumInfo"] = new JSONValue(ItemInfo);

	JSONObject ItemInfo1;
	ItemInfo1[L"Text"] = new JSONValue(trd.TopicInfo.Text);
	ItemInfo1[L"Value"] = new JSONValue(trd.TopicInfo.Value);
	ThreadDetailsInfo[L"TopicInfo"] = new JSONValue(ItemInfo1);

	ThreadDetailsInfo[L"ThreadID"] = new JSONValue(trd.ThreadID);
	ThreadDetailsInfo[L"ThreadName"] = new JSONValue(trd.ThreadName);
	ThreadDetailsInfo[L"UserName"] = new JSONValue(trd.UserName);
	ThreadDetailsInfo[L"ThreadDesc"] = new JSONValue(trd.ThreadDesc);

	ThreadDetailsInfo[L"ThreadImage"] = new JSONValue(trd.ThreadImage);
	ThreadDetailsInfo[L"ImageName"] = new JSONValue(trd.ImageName);

	ThreadDetailsInfo[L"Success"] = new JSONValue(trd.Success);
	ThreadDetailsInfo[L"ErrorDesc"] = new JSONValue(trd.ErrorDesc);

	JSONValue* val = new JSONValue(ThreadDetailsInfo);
	std::wstring res = val->Stringify(false);
	CString dataUpdate = CString(res.c_str());

	try
	{
		OnRequestData(dataUpdate);
		JSONValue* jval = NetworkRequest::PostReq(updateThreads, dataUpdate);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		OnResponseData(cstrRes);
		AfxMessageBox(cstrRes);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);
	}
	
	return CString();
}
/***************************************************************
  Function Name : GetThreadByID
  Return Type : void
  Parameters : strThreadID 
  Parameters : InfoArray 
  Remarks : Function to execute the Network call to get all 
			threads with thread Id 
 **************************************************************/
void AppApiService::GetThreadByID(CString strThreadID, CArray<ThreadDetailsInfo>& InfoArray)
{
	try
	{
		CString getAllThreads;
		getAllThreads.Format(_T("Api/Forum/GetThreadByID?strThreadID=%s"), strThreadID);
		JSONValue* Jvalue = NetworkRequest::GetReqEx(getAllThreads);
		JSONObject root = Jvalue->AsObject();
		std::wstring res = Jvalue->Stringify(true);
		CString cstrRes(res.c_str());
		OnResponseData(cstrRes);
		OnStatusMessage(getAllThreads);
		ThreadDetailsInfo Info;
		Info.ThreadDesc= root[L"ThreadDesc"]->AsString().c_str();
		Info.ThreadID = root[L"ThreadID"]->AsString().c_str();
		Info.ThreadName = root[L"ThreadName"]->AsString().c_str();
		Info.ThreadImage = root[L"ThreadImage"]->AsString().c_str();
		Info.ImageName = root[L"ImageName"]->AsString().c_str();
		Info.Success = root[L"Success"]->AsBool();
		Info.ErrorDesc = root[L"ErrorDesc"]->AsString().c_str();
		Info.UserName = root[L"UserName"]->AsString().c_str();
		JSONObject TopicInfo= root[L"TopicInfo"]->AsObject();
		Info.TopicInfo.Text = TopicInfo[L"Text"]->IsNull() ? _T(""):TopicInfo[L"Text"]->AsString().c_str();
		Info.TopicInfo.Value = TopicInfo[L"Value"]->IsNull()? 0: TopicInfo[L"Value"]->AsNumber();
		JSONObject ForumInfo = root[L"ForumInfo"]->AsObject();
		Info.ForumInfo.Text = ForumInfo[L"Text"]->IsNull() ? _T("") : TopicInfo[L"Text"]->AsString().c_str();
		Info.ForumInfo.Value = ForumInfo[L"Value"]->IsNull() ? 0 : TopicInfo[L"Value"]->AsNumber();
		JSONObject ftrdetails = root[L"ftrDetails"]->AsObject();
		Info.ftrDetails.AuthorID = ftrdetails[L"AuthorID"]->IsNull()?_T(""): ftrdetails[L"AuthorID"]->AsString().c_str();
		Info.ftrDetails.BugStatus = ftrdetails[L"BugStatus"]->IsNull()?_T(""): ftrdetails[L"BugStatus"]->AsString().c_str();
		Info.ftrDetails.PostedDate = ftrdetails[L"PostedDate"]->IsNull()?_T(""): ftrdetails[L"PostedDate"]->AsString().c_str();
		Info.ftrDetails.ThreadAssigned = ftrdetails[L"ThreadAssigned"]->IsNull()?_T(""):ftrdetails[L"ThreadAssigned"]->AsString().c_str();
		Info.ftrDetails.ThreadImagePth = ftrdetails[L"ThreadImagePth"]->IsNull()?_T(""): ftrdetails[L"ThreadImagePth"]->AsString().c_str();
		InfoArray.Add(Info);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		OnResponseData(errorStr);
	}
}
/***************************************************************
  Function Name : GetMsgsByTrdID
  Return Type : void
  Parameters : strThread 
  Parameters : InfoArray 
  Remarks :  Function to execute the Network call to get messages by thread Id
 **************************************************************/
void AppApiService::GetMsgsByTrdID(CString strThread, CArray<CommentsInfo>& InfoArray)
{
	try {
		CString getAllMessages;
		getAllMessages.Format(_T("Api/Forum/GetMsgsByTrdID?strThreadID=%s"), strThread);
		OnStatusMessage(getAllMessages);
		JSONValue* Jvalue = NetworkRequest::GetReqEx(getAllMessages);
		JSONArray root = Jvalue->AsArray();
		for (unsigned int i = 0; i < root.size(); i++)
		{
			JSONObject Jobj = root[i]->AsObject();
			CommentsInfo Info;
			Info.MsgID = Jobj[L"MsgID"]->AsString().c_str();
			Info.ThreadID = Jobj[L"ThreadID"]->AsString().c_str();
			Info.Message = Jobj[L"Message"]->AsString().c_str();
			Info.Author = Jobj[L"Author"]->AsString().c_str();
			Info.User = Jobj[L"User"]->AsString().c_str();
			Info.PostedDate = Jobj[L"PostedDate"]->AsString().c_str();
			Info.DeletedBy = Jobj[L"DeletedBy"]->AsString().c_str();
			Info.ErrorDesc = Jobj[L"ErrorDesc"]->AsString().c_str();
			Info.Status = Jobj[L"Status"]->AsBool();
			Info.Success = Jobj[L"Success"]->AsBool();
			InfoArray.Add(Info);
		}
		std::wstring res = Jvalue->Stringify(true);
		OnResponseData(CString(res.c_str()));
	}
	catch (const std::exception& e)
	{
		OnResponseData(CString(e.what()));
	}
}
/***************************************************************
  Function Name : DeleteComments
  Return Type : void
  Parameters : strMsgID 
  Parameters : ResponseMessage 
  Remarks : Function to execute the Network call to delete comments
 **************************************************************/
void AppApiService::DeleteComments(CArray<CString>& strMsgID, CArray<CString>& ResponseMessage)
{
	CString DeleteAComment = _T("Api/Forum/DeleteComments");
	OnStatusMessage(DeleteAComment);
	JSONArray arr;
	for (int i = 0; i < strMsgID.GetSize(); i++)
	{
		arr.push_back(new JSONValue(std::wstring(strMsgID[i])));
	}
	JSONValue* val = new JSONValue(arr);
	std::wstring res = val->Stringify(true);
	CString dataUpdate = CString(res.c_str());
	OnResponseData(dataUpdate);

	try
	{
		JSONValue* jval = NetworkRequest::PostReq(DeleteAComment, dataUpdate);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		OnResponseData(cstrRes);
		AfxMessageBox(cstrRes);

	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		OnResponseData(errorStr);
		AfxMessageBox(errorStr);
	}
}
/***************************************************************
  Function Name : AddComments
  Return Type : CString
  Parameters : Info 
  Remarks : Function to execute the Network call to add a comment
 **************************************************************/
CString AppApiService::AddComments(CommentsInfo Info)
{
	CString url = _T("Api/Forum/AddComments");
	OnStatusMessage(url);
	CString data;
	data.Format(_T("{ \"MsgID\":\"%s\", \
					   \"ThreadID\" : \"%s\", \
						\"Message\" : \"%s\", \
						 \"Author\" : \"%s\", \
						  \"User\" : \"%s\", \
						   \"PostedDate\" : \"%s\", \
						    \"Status\" : false, \
						     \"DeletedBy\" :\"%s\",\
                              \"Success\" : false, \
						       \"ErrorDesc\" : \"%s\"}"),
		Info.MsgID, Info.ThreadID, Info.Message, Info.Author, Info.User, Info.Posteddate, Info.DeletedBy, Info.ErrorDesc);
	try
	{
		OnRequestData(data);
		JSONValue* jval = NetworkRequest::PostReq(url, data);
		std::wstring res = jval->Stringify(true);
		CString cstrRes(res.c_str());
		OnResponseData(cstrRes);
		AfxMessageBox(cstrRes);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);
	}
	return CString();
}
/***************************************************************
  Function Name : ForceDeleteForum
  Return Type : CString
  Parameters : strForumId 
  Remarks :  Function to execute the Network call to force delete a forum
 **************************************************************/
CString AppApiService::ForceDeleteForum(CString strForumId)
{
	try
	{
		CString ForceDeleteForum;
		ForceDeleteForum.Format(_T("Api/Forum/ForceDeleteForum?strForumId=%s"), strForumId);
		JSONValue* JvalueNew = NetworkRequest::GetReqEx(ForceDeleteForum);
		std::wstring resNew = JvalueNew->Stringify(true);
		CString cstrResNew(resNew.c_str());
		OnResponseData(cstrResNew);
		OnStatusMessage(ForceDeleteForum);
		AfxMessageBox(cstrResNew);
	}
	catch (const std::exception& e)
	{
		CString errorStr(e.what());
		AfxMessageBox(errorStr);
	}
	
	return CString();
}
/***************************************************************
  Function Name : ForceDeleteTopic
  Return Type : CString
  Parameters : strTopicId 
  Remarks :  Function to execute the Network call to force delete a topic
 **************************************************************/
CString AppApiService::ForceDeleteTopic(int strTopicId)
{
try
{
	CString ForceDeleteTopic;
	ForceDeleteTopic.Format(_T("Api/Forum/ForceDeleteTopic?strTopicId=%d"), strTopicId);
	JSONValue* JvalueNew = NetworkRequest::GetReqEx(ForceDeleteTopic);
	std::wstring resNew = JvalueNew->Stringify(true);
	CString cstrResNew(resNew.c_str());
	OnResponseData(cstrResNew);
	OnStatusMessage(ForceDeleteTopic);
	AfxMessageBox(cstrResNew);
	return CString();
}
catch (const std::exception& e)
{
	CString errorStr(e.what());
	AfxMessageBox(errorStr);
}
}
