#pragma once
#include <stdio.h>
#include <list>
#include "PersonInCharge.h"

/// <summary>
/// 一つのタスク内容
/// </summary>
class Task
{
public:// サブ
	enum Priority
	{
		Lower,   // 低め 0
		Usually, // 普通 1
		Higher,  // 高め 2
	};
	enum Status
	{
		Incomplete, // 未完了 0
		Completion, // 完了   1
	};

public:// メンバ関数
	// 情報の譲渡
	int GetTaskID() { return taskID; }

	// 表示

	// タスクIDの表示
	void DrawTaskID();

	// タスクの担当者たちを表示
	void DrawAllPics();

	// タスク単体の担当者の表示
	void DrawPic();

	// タスクの題名を表示
	void DrawTaskTitle();

	// タスクの内容を表示
	void DrawTaskContent();

	// タスクの優先度を表示
	void DrawPriority();

	// タスクの期限を表示
	void DrawDeadLine();

	// タスクのステータスを表示
	void DrawStatus();

	// タスクの全情報を表示
	void DrawAllInfo();


	// セッター
	void SetID(int taskID) { this->taskID = taskID; }
	void SetPicID(int picID) { this->picID = picID; }
	void SetTaskTitle(const char* taskTitle) { strcpy_s(this->taskTitle, 20, taskTitle); }
	void SetTaskContent(const char* taskContent) { strcpy_s(this->taskContent,100, taskContent); }
	void SetPriorityNum(int priorityNum) { this->priorityNum = priorityNum; }
	void SetDeadLine(const char* deadline) { strcpy_s(this->deadline, 30, deadline); }
	void SetStatusNum(int statusNum) { this->statusNum = statusNum; }
	static void SetPersonInCharge(std::list<PersonInCharge*>pics) { Task::pics = pics; }

private:// メンバ変数

	// タスクのID
	int taskID = 0;

	// 担当者のリスト（選択可能）
	int picID = 0;
	static std::list<PersonInCharge*> pics;

	// セットした担当者
	PersonInCharge pic;

	// 題名
	char taskTitle[20];

	// 内容
	char taskContent[100];

	// 優先度
	int priorityNum = 0;

	Priority priority = Priority::Usually;

	// 期限
	char deadline[30];

	// ステータス
	int statusNum = 0;

	Status status = Status::Incomplete;

};

