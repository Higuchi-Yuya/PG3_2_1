#include "Task.h"
#include <iostream>
#include <iterator>

std::list<PersonInCharge*> Task::pics;

void Task::DrawTaskID()
{
	printf("TaskID:%d\n", taskID);
}

void Task::DrawAllPics()
{
	printf("セットできるメンバー");
	for (auto pic : pics) {
		pic->DrawPicID();
		pic->DrawClss();
		pic->DrawContent();
	}
}

void Task::DrawPic()
{
	for (auto itr = pics.begin(); itr != pics.end(); ++itr) {
		PersonInCharge* Pic = *itr;
		if (Pic->GetPicID() == picID) {
			pic = *Pic;
		}
	}

	pic.DrawPicAllInfo();
	
}

void Task::DrawTaskTitle()
{
	printf("題名:%s\n", taskTitle);
}

void Task::DrawTaskContent()
{
	printf("タスク内容:%s\n", taskContent);
}

void Task::DrawPriority()
{
	// 受け取った優先度の番号で優先度を決める
	switch (priorityNum)
	{
	case 0:
		priority = Priority::Lower;
		break;
	case 1:
		priority = Priority::Usually;
		break;
	case 2:
		priority = Priority::Higher;
		break;
	default:
		break;
	}

	// 優先度の描画
	switch (priority)
	{
	case Task::Lower:
		printf("優先度:低め\n");
		break;
	case Task::Usually:
		printf("優先度:普通\n");
		break;
	case Task::Higher:
		printf("優先度:高め\n");
		break;
	default:
		break;
	}
	
}

void Task::DrawDeadLine()
{
	printf("期限:%s\n", deadline);
}

void Task::DrawStatus()
{
	// ステータスを番号で受け取りステータスの設定を行う
	switch (statusNum)
	{
	case 0:
		status = Status::Incomplete;
		break;
	case 1:
		status = Status::Completion;
		break;
	default:
		break;
	}

	// 受け取ったものを描画
	switch (status)
	{
	case Task::Incomplete:
		printf("ステータス:未完了\n");
		break;
	case Task::Completion:
		printf("ステータス:完了\n");
		break;
	default:
		break;
	}
}

void Task::DrawAllInfo()
{
	DrawTaskID();
	DrawPic();
	DrawTaskTitle();
	DrawTaskContent();
	DrawPriority();
	DrawDeadLine();
	DrawStatus();
}
