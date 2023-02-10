#pragma once
#include "Task.h"
class TaskManager
{
public:
	void Initialize();

	void Update();

	void EditUpdate();

	void ShowUpdate();

	// タスクのIDでタスクを探す
	Task* SearchTask(int taskID);

	void DeleteTask(int taskID);

private:
	// タスクを検索する時に使うID
	int taskID_ = 0;

	// 担当者を登録するときに使うID
	int picID_ = 0;

	// 題名
	char taskTitle_[20];

	// 内容
	char taskContent_[100];

	// 優先度
	int priorityNum_ = 0;

	// 期限
	char deadline_[30];

	// ステータス
	int statusNum_ = 0;

	// 操作番号
	int operatorNum = 0;

	// 表示時の操作番号
	int displayNum = 0;

	// 編集時の操作番号
	int editNum = 0;

	// 削除時の操作番号
	int deleteNum = 0;

	// タスクを保存しとくリスト
	std::list<Task*>tasks_;

	// 担当者たちのリスト
	std::list<PersonInCharge*>pics_;


};

