/*********************************************************************
   Workfile : forumservices.cpp
   Description : Implementation of  forumservices.cpp
 
   Copyright (C) 2022 KTS InfoTech
   All rights reserved
 
   Author : Silpa Sivaram
   Last Modified : 21 June 2022
 *********************************************************************/
#include "forumservices.h"
#include "mainwindow.h"
#include <QMessageBox>
ForumServices::ForumServices()
{
    m_NetworkReq=new NetWorkRequest();
}
/***************************************************************
  Function Name : GetAllForums
  Return Type : QJsonDocument
  Remarks : Network request to get all forums 
 **************************************************************/
QJsonDocument ForumServices::GetAllForums()
{
    QJsonDocument Doc;
    try
    {
         QString Paramters = "Api/Forum/GetAllForums";
         QNetworkReply* Result= m_NetworkReq->GetRequest(Paramters);
         Doc=QJsonDocument::fromJson(Result->readAll());
         MainWindow::SetResponseData(Doc);

    }
    catch (std::exception& e)
    {
        MainWindow::SetResponseData(e.what());
    }
    return Doc;
}
/***************************************************************
  Function Name : GetAllForumIdWithNames
  Return Type : QJsonDocument
  Remarks : Network request to get all forum id with names 
 **************************************************************/
QJsonDocument ForumServices::GetAllForumIdWithNames()
{
    QJsonDocument Doc;
    try
    {
        QString Parameters = "Api/Forum/GetAllForumIdWithNames";
        QNetworkReply*Result=m_NetworkReq->GetRequest(Parameters);
        Doc=QJsonDocument::fromJson(Result->readAll());
        MainWindow::SetResponseData(Doc);

    }
    catch (std::exception&e)
    {
        MainWindow::SetResponseData(e.what());
    }
    return Doc;
}
/***************************************************************
  Function Name : GetAllTopicsWithForumID
  Return Type : QJsonDocument
  Parameters : strForumId 
  Remarks : Network request to get all topics with forum id 
 **************************************************************/
QJsonDocument ForumServices::GetAllTopicsWithForumID(QString strForumId)
{
QJsonDocument Doc;
    try
    {
        QString Parameters ="Api/Forum/GetAllTopicsWithForumID?iForumId="+strForumId;
        QNetworkReply*Result=m_NetworkReq->GetRequest(Parameters);
        Doc=QJsonDocument::fromJson(Result->readAll());
        MainWindow::SetResponseData(Doc);
    }
    catch (std::exception&e)
    {
    MainWindow::SetResponseData(e.what());
    }
return Doc;
}
/***************************************************************
  Function Name : GetAllThreadsWithTopicID
  Return Type : QJsonDocument
  Parameters : strTopicID 
  Remarks :  Network request to get all threads with topic id
 **************************************************************/
QJsonDocument ForumServices::GetAllThreadsWithTopicID(QString strTopicID)
{
    QJsonDocument Doc;
        try
        {
            //QString Parameters = QString("Api/Forum/GetAllThreadsWithTopicID?strTopicID==%0").arg(strTopicID);
            QString Parameters ="Api/Forum/GetAllThreadsWithTopicID?strTopicID="+strTopicID;
            QNetworkReply*Result=m_NetworkReq->GetRequest(Parameters);
            Doc=QJsonDocument::fromJson(Result->readAll());
            MainWindow::SetResponseData(Doc);
        }
        catch (std::exception&e)
        {
        MainWindow::SetResponseData(e.what());
        }
    return Doc;
}
/***************************************************************
  Function Name : GetAllTopics
  Return Type : QJsonDocument
  Remarks : Network request to get alltopics 
 **************************************************************/
QJsonDocument ForumServices::GetAllTopics()
{
    QJsonDocument Doc;
        try
        {
            QString Parameters ="Api/Forum/GetAllTopics";
            QNetworkReply*Result=m_NetworkReq->GetRequest(Parameters);
            Doc=QJsonDocument::fromJson(Result->readAll());
            MainWindow::SetResponseData(Doc);
        }
        catch (std::exception&e)
        {
        MainWindow::SetResponseData(e.what());
        }
    return Doc;
}
/***************************************************************
  Function Name : GetAllThreads
  Return Type : QJsonDocument
  Remarks :  Network request to get all threads
 **************************************************************/
QJsonDocument ForumServices::GetAllThreads()
{
    QJsonDocument Doc;
        try
        {
            QString Parameters ="Api/Forum/GetAllThreads";
            QNetworkReply*Result=m_NetworkReq->GetRequest(Parameters);
            Doc=QJsonDocument::fromJson(Result->readAll());
            MainWindow::SetResponseData(Doc);
        }
        catch (std::exception&e)
        {
        MainWindow::SetResponseData(e.what());
        }
    return Doc;
}
/***************************************************************
  Function Name : DeleteThread
  Return Type : QJsonDocument
  Parameters : strThreadID 
  Remarks : Network request to delete a thread 
 **************************************************************/
QJsonDocument ForumServices::DeleteThread(QString strThreadID)
{
    QJsonDocument Doc;
        try
        {
            QString Parameters ="Api/Forum/DeleteThread?strThreadID="+strThreadID;
            QNetworkReply*Result=m_NetworkReq->GetRequest(Parameters);
            auto Doc=QString(Result->readAll());
            MainWindow::SetResponseData(Doc);
            QMessageBox::information(nullptr,"WebColudAPITest",Doc);

        }
        catch (std::exception&e)
        {
        MainWindow::SetResponseData(e.what());
        QMessageBox::information(nullptr,"WebColudAPITest","Unable to Delete This Thread");
        }
    return Doc;
}
/***************************************************************
  Function Name : DeleteForum
  Return Type : QString
  Parameters : strForumID 
  Remarks : Network request to delete a forum 
 **************************************************************/
QString ForumServices::DeleteForum(QString strForumID)
{
       QString data;
        try
        {
            QString Parameters ="Api/Forum/DeleteForum?strForumID="+strForumID;
            QNetworkReply*Result=m_NetworkReq->GetRequest(Parameters);
            data =QString(Result->readAll());
            data=data.remove("\"");
            MainWindow::SetResponseData(data);
            QMessageBox::information(nullptr,"WebColudAPITest",data);

        }
        catch (std::exception&e)
        {
        MainWindow::SetResponseData(e.what());
        }
       return data;

}
/***************************************************************
  Function Name : DeleteTopic
  Return Type : QString
  Parameters : strTopicID 
  Remarks : Network request to delete a topic 
 **************************************************************/
QString ForumServices::DeleteTopic(QString strTopicID)
{
     QString Responsedata;
     try
     {
         QString Parameters ="Api/Forum/DeleteTopic?strTopicID="+strTopicID;
         QNetworkReply*Result=m_NetworkReq->GetRequest(Parameters);
         Responsedata=QString(Result->readAll());
         MainWindow::SetResponseData(Responsedata);
         QMessageBox::information(nullptr,"WebColudAPITest",Responsedata);
     }
     catch (std::exception&e)
     {
     MainWindow::SetResponseData(e.what());
     }
    return Responsedata;
}
/***************************************************************
  Function Name : AddForum
  Return Type : QString
  Parameters : Info 
  Remarks : Network request to add a forum 
 **************************************************************/
QString ForumServices::AddForum(QJsonDocument Info)
{
    QString Data;
     try
     {
         QString Parameters ="Api/Forum/AddForum";
         QNetworkReply*Result=m_NetworkReq->PostRequest(Parameters,Info.toJson());
         Data=QString(Result->readAll());
         MainWindow::SetResponseData(Data);
         QMessageBox::information(nullptr,"WebColudAPITest",Data);
     }
     catch (std::exception&e)
     {
     MainWindow::SetResponseData(e.what());
     QMessageBox::information(nullptr,"WebColudAPITest",e.what());
     }
    return Data;
}
/***************************************************************
  Function Name : UpdateForum
  Return Type : QString
  Parameters : Info 
  Remarks : Network request to update a forum 
 **************************************************************/
QString ForumServices::UpdateForum(QJsonDocument Info)
{
    QString Data;
     try
     {
         QString Parameters ="Api/Forum/UpdateForum";
         QNetworkReply*Result=m_NetworkReq->PostRequest(Parameters,Info.toJson());
         Data=QString(Result->readAll());
         MainWindow::SetResponseData(Data);
         QMessageBox::information(nullptr,"WebColudAPITest",Data);

     }
     catch (std::exception&e)
     {
     MainWindow::SetResponseData(e.what());
     }
    return Data;
}
/***************************************************************
  Function Name : GetExistingGroups
  Return Type : QJsonDocument
  Remarks : Network request to get all existing groups 
 **************************************************************/
QJsonDocument ForumServices::GetExistingGroups()
{
    QJsonDocument Doc;
     try
     {
         QString Parameters ="Api/Forum/GetExistingGroups";
         QNetworkReply*Result=m_NetworkReq->GetRequest(Parameters);
         Doc=QJsonDocument::fromJson(Result->readAll());
         MainWindow::SetResponseData(Doc);
     }
     catch (std::exception&e)
     {
     MainWindow::SetResponseData(e.what());
     }
    return Doc;
}
/***************************************************************
  Function Name : RetrieveEmail
  Return Type : QString
  Parameters : strGroupId 
  Remarks : Network request to retrieve e-mails 
 **************************************************************/
QString ForumServices::RetrieveEmail(QString strGroupId)
{
    QString Response;
     try
     {
         QString Parameters ="Api/Forum/RetrieveEmail?strGroupId="+strGroupId;
         QNetworkReply*Result=m_NetworkReq->GetRequest(Parameters);
         Response=QString(Result->readAll());
         Response=Response.remove("\"");
         MainWindow::SetResponseData(Response);
     }
     catch (std::exception&e)
     {
     MainWindow::SetResponseData(e.what());
     }
    return Response;
}
/***************************************************************
  Function Name : AddTopics
  Return Type : QString
  Parameters : Info 
  Remarks : Network request to add topics 
 **************************************************************/
QString ForumServices::AddTopics(QJsonDocument Info)
{
    QString Resp;
     try
     {
         QString Parameters ="Api/Forum/AddTopics";
         QNetworkReply*Result=m_NetworkReq->PostRequest(Parameters,Info.toJson());
         Resp=QString(Result->readAll());
         MainWindow::SetResponseData(Resp);
         QMessageBox::information(nullptr,"WebColudAPITest",Resp);
     }
     catch (std::exception&e)
     {
     MainWindow::SetResponseData(e.what());
     }
    return Resp;
}
/***************************************************************
  Function Name : UpdateTopic
  Return Type : QString
  Parameters : Info 
  Remarks : Network request to update topics 
 **************************************************************/
QString ForumServices::UpdateTopic(QJsonDocument Info)
{

    QString data;
     try
     {
         QString Parameters ="Api/Forum/UpdateTopic";
         QNetworkReply*Result=m_NetworkReq->PostRequest(Parameters,Info.toJson());
         data=QString(Result->readAll());
         MainWindow::SetResponseData(data);
         QMessageBox::information(nullptr,"WebColudAPITest",data);
     }
     catch (std::exception&e)
     {
     MainWindow::SetResponseData(e.what());

     }
    return data;
}
/***************************************************************
  Function Name : AddThread
  Return Type : QString
  Parameters : trd 
  Remarks : Network request to add a thread 
 **************************************************************/
QString ForumServices::AddThread(QJsonDocument trd)
{

    QString data;
     try
     {
         QString Parameters ="Api/Forum/AddThread";
         QNetworkReply*Result=m_NetworkReq->PostRequest(Parameters,trd.toJson());
         data=QString(Result->readAll());
         MainWindow::SetResponseData(data);
         QMessageBox::information(nullptr,"WebColudAPITest",data);
     }
     catch (std::exception&e)
     {
     MainWindow::SetResponseData(e.what());
     }
    return data;
}
/***************************************************************
  Function Name : UpdateThread
  Return Type : QString
  Parameters : trd 
  Remarks : Network request to update a thread 
 **************************************************************/
QString ForumServices::UpdateThread(QJsonDocument trd)
{
    QString Data;
     try
     {
         QString Parameters ="Api/Forum/UpdateThread";
         QNetworkReply*Result=m_NetworkReq->PostRequest(Parameters,trd.toJson());
         Data=QString(Result->readAll());
         MainWindow::SetResponseData(Data);
         QMessageBox::information(nullptr,"WebColudAPITest",Data);
     }
     catch (std::exception&e)
     {
     MainWindow::SetResponseData(e.what());
     }
    return Data;
}
/***************************************************************
  Function Name : GetThreadByID
  Return Type : QJsonDocument
  Parameters : strThreadID 
  Remarks : Network request to get thread by thread id 
 **************************************************************/
QJsonDocument ForumServices::GetThreadByID(QString strThreadID)
{
    QJsonDocument Doc;
     try
     {
         QString Parameters ="Api/Forum/GetThreadByID?strThreadID="+strThreadID;
         QNetworkReply*Result=m_NetworkReq->GetRequest(Parameters);
         Doc=QJsonDocument::fromJson(Result->readAll());
         MainWindow::SetResponseData(Doc);
     }
     catch (std::exception&e)
     {
     MainWindow::SetResponseData(e.what());
     }
    return Doc;
}
/***************************************************************
  Function Name : GetMsgsByTrdID
  Return Type : QJsonDocument
  Parameters : strThread 
  Remarks : Network request to get messages by thread id 
 **************************************************************/
QJsonDocument ForumServices::GetMsgsByTrdID(QString strThread)
{

    QJsonDocument Doc;
     try
     {
         QString Parameters ="Api/Forum/GetMsgsByTrdID?strThreadID="+strThread;
         QNetworkReply*Result=m_NetworkReq->GetRequest(Parameters);
         Doc=QJsonDocument::fromJson(Result->readAll());
         MainWindow::SetResponseData(Doc);
     }
     catch (std::exception&e)
     {
     MainWindow::SetResponseData(e.what());
     }
    return Doc;
}
/***************************************************************
  Function Name : DeleteComments
  Return Type : QJsonDocument
  Parameters : strMsgID 
  Remarks : Network request to delete comments 
 **************************************************************/
QJsonDocument ForumServices::DeleteComments(QJsonDocument strMsgID)
{
    QJsonDocument Doc;
     try
     {
         QString Parameters ="Api/Forum/DeleteComments";
         QNetworkReply*Result=m_NetworkReq->PostRequest(Parameters,strMsgID.toJson());
         auto Doc=QString(Result->readAll());
         MainWindow::SetResponseData(Doc);
         QMessageBox::information(nullptr,"WebColudAPITest",Doc);
     }
     catch (std::exception&e)
     {
     MainWindow::SetResponseData(e.what());
     QMessageBox::information(nullptr,"WebColudAPITest","Unable to delete this Message");
     }
    return Doc;
}
/***************************************************************
  Function Name : AddComments
  Return Type : QJsonDocument
  Parameters : Info 
  Remarks : Network request to add comments 
 **************************************************************/
QJsonDocument ForumServices::AddComments(QJsonDocument Info)
{

    QJsonDocument Doc;
     try
     {
         QString Parameters ="Api/Forum/AddComments";
         QNetworkReply*Result=m_NetworkReq->PostRequest(Parameters,Info.toJson());
         auto Doc=QString(Result->readAll());
         MainWindow::SetResponseData(Doc);
         QMessageBox::information(nullptr,"WebColudAPITest",Doc);
     }
     catch (std::exception&e)
     {
     MainWindow::SetResponseData(e.what());
     QMessageBox::information(nullptr,"WebColudAPITest",e.what());
     }
    return Doc;
}
/***************************************************************
  Function Name : ForceDeleteForum
  Return Type : QJsonDocument
  Parameters : strForumId 
  Remarks : Network request to force delete forum 
 **************************************************************/
QJsonDocument ForumServices::ForceDeleteForum(QString strForumId)
{

    QJsonDocument Doc;
     try
     {
         QString Parameters ="Api/Forum/ForceDeleteForum?strForumId="+strForumId;
         QNetworkReply*Result=m_NetworkReq->GetRequest(Parameters);
         auto Doc=QString(Result->readAll());
         MainWindow::SetResponseData(Doc);
         QMessageBox::information(nullptr,"WebColudAPITest",Doc);
     }
     catch (std::exception&e)
     {
     MainWindow::SetResponseData(e.what());
     QMessageBox::information(nullptr,"WebColudAPITest",e.what());
     }
    return Doc;
}
/***************************************************************
  Function Name : ForceDeleteTopic
  Return Type : QJsonDocument
  Parameters : strTopicId 
  Remarks : Network request to force delete topic 
 **************************************************************/
QJsonDocument ForumServices::ForceDeleteTopic(QString strTopicId)
{

    QJsonDocument Doc;
     try
     {
         QString Parameters ="Api/Forum/ForceDeleteTopic?strTopicId="+strTopicId;
         QNetworkReply*Result=m_NetworkReq->GetRequest(Parameters);
         Doc=QJsonDocument::fromJson(Result->readAll());
         MainWindow::SetResponseData(Doc);
     }
     catch (std::exception&e)
     {
     MainWindow::SetResponseData(e.what());
     }
    return Doc;
}

























