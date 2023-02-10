#include "TaskManager.h"

void TaskManager::Initialize()
{
	PersonInCharge *picss[3];
	for (int i = 0; i < 3; i++) {
		picss[i] = new PersonInCharge;
	}

	picss[0]->SetPicID(0);
	picss[0]->SetClassNum(1);
	picss[0]->SetContent("Iguchi_Syunpei");

	picss[1]->SetPicID(1);
	picss[1]->SetClassNum(1);
	picss[1]->SetContent("Imai_Takeshi");

	picss[2]->SetPicID(2);
	picss[2]->SetClassNum(1);
	picss[2]->SetContent("Higuchi_Yuya");

	for (int i = 0; i < 3; i++) {
		pics_.push_back(picss[i]);
	}

	Task::SetPersonInCharge(pics_);
}

void TaskManager::Update()
{
	switch (operatorNum)
	{
	case 0:// タスク操作画面
		printf("\n[タスクの操作]\n");
		printf("1.タスクの新規作成\n");
		printf("2.タスクの表示\n");
		if (tasks_.size() != 0) {
			printf("3.タスクの編集\n");
			printf("4.タスクの削除\n");
		}
		printf("\n------------------------------------\n");
		printf("操作を選択してください\n");

		scanf_s("%d", &operatorNum);
		break;

	#pragma region 新規タスクの作成
	case 1:// 新規タスクを作成
	{
		printf("\n[タスクの新規作成]\n");
		Task* task = new Task;
		printf("タスクIDを入力して下さい\n");
		scanf_s("%d", &taskID_);
		task->SetID(taskID_);

		printf("担当者IDを入力して、担当者を選択してください\n");
		for (auto itr = pics_.begin(); itr != pics_.end(); ++itr) {
			PersonInCharge* pic = *itr;

			pic->DrawPicAllInfo();
		}
		scanf_s("%d", &picID_);
		task->SetPicID(picID_);

		printf("タスクの題名を入力してください\n");
		scanf_s("%s", &taskTitle_,20);
		task->SetTaskTitle(taskTitle_);

		printf("タスクの内容を入力してください\n");
		scanf_s("%s", &taskContent_, 100);
		task->SetTaskContent(taskContent_);

		printf("タスクの優先度を選択してください\n");
		printf("0:低め\n");
		printf("1:普通\n");
		printf("2:高め\n");
		scanf_s("%d", &priorityNum_);
		task->SetPriorityNum(priorityNum_);

		printf("タスクの期限を入力してください\n");
		scanf_s("%s", &deadline_, 30);
		task->SetDeadLine(deadline_);

		printf("タスクのステータスを選択してください\n");
		printf("0:未完了\n");
		printf("1:完了\n");
		scanf_s("%d", &statusNum_);
		task->SetStatusNum(statusNum_);

		tasks_.push_back(task);
		printf("タスクID:%dの作成が完了しました。\n",task->GetTaskID());
		operatorNum = 0;
	}
	break;
	#pragma endregion

	#pragma region タスクの表示
	case 2:// タスクの表示
		printf("\n[タスクの表示]\n");
		printf("0.タスクの一覧表示\n");
		printf("1.タスクのIDを指定してタスクを表示\n");
		printf("9.タスク操作に戻る\n");

		printf("\n操作を選択してください\n");
		scanf_s("%d", &displayNum);

		// 表示番号での操作
		ShowUpdate();

		break;
	#pragma endregion

	#pragma region タスクの編集
	case 3:
	{
		if (tasks_.size() != 0) {
			Task* task = new Task;
			printf("\n[要素の編集]\n");
			printf("編集したいタスクのIDを指定してください\n");
			for (auto task : tasks_) {
				task->DrawTaskID();
				task->DrawTaskTitle();
				printf("\n");
			}
			scanf_s("%d", &taskID_);

			// サーチしたものを代入
			task = SearchTask(taskID_);
			task->DrawTaskID();
			task->DrawTaskTitle();
			printf("\n");
			printf("変更したいものを選んでください。\n");
			printf("0:担当者\n");
			printf("1:題名\n");
			printf("2:内容\n");
			printf("3:優先度\n");
			printf("4:期限\n");
			printf("5:ステータス\n");
			printf("6:一括変更\n");
			printf("7:変更なし\n");
			scanf_s("%d", &editNum);

			// 変更処理
			EditUpdate();

			printf("タスクID:%dの変更が完了しました。\n", task->GetTaskID());
		}
		operatorNum = 0;
		break;
	}
	#pragma endregion

	#pragma region タスクの削除
	case 4:
	{
		if (tasks_.size() != 0) {
			printf("\n[タスクの削除]\n");
			printf("0:全てのタスクを削除。\n");
			printf("1:IDを指定して、タスクを削除。\n");
			scanf_s("%d", &deleteNum);
			switch (deleteNum)
			{
			case 0:// 全削除
				tasks_.clear();
				printf("全てのタスクを削除しました。\n");
				break;
			case 1:// 指定して削除
			{
				Task* task = new Task;
				printf("削除したいタスクのIDを指定してください。\n");
				for (auto task : tasks_) {
					task->DrawTaskID();
					task->DrawTaskTitle();
					printf("\n");
				}
				scanf_s("%d", &taskID_);

				DeleteTask(taskID_);
				printf("タスクID:%dの削除をしました\n", taskID_);
			}
				break;
			default:
				operatorNum = 0;
				break;
			}
		}
		operatorNum = 0;
		break;
	}
		
	#pragma endregion


	default:
		operatorNum = 0;
		break;
	}
}

void TaskManager::EditUpdate()
{
	Task* task = new Task;
	// サーチしたものを代入
	task = SearchTask(taskID_);
	switch (editNum)
	{
	case 0:// 担当者変更
		printf("担当者IDを入力して、担当者を選択してください\n");
		for (auto itr = pics_.begin(); itr != pics_.end(); ++itr) {
			PersonInCharge* pic = *itr;

			pic->DrawPicAllInfo();
		}
		scanf_s("%d", &picID_);
		task->SetPicID(picID_);
		break;
	case 1:// 題名変更
		printf("タスクの題名を入力してください\n");
		scanf_s("%s", &taskTitle_, 20);
		task->SetTaskTitle(taskTitle_);
		break;
	case 2:// 内容変更
		printf("タスクの内容を入力してください\n");
		scanf_s("%s", &taskContent_, 100);
		task->SetTaskContent(taskContent_);
		break;
	case 3:// 優先度変更
		printf("タスクの優先度を選択してください\n");
		printf("0:低め\n");
		printf("1:普通\n");
		printf("2:高め\n");
		scanf_s("%d", &priorityNum_);
		task->SetPriorityNum(priorityNum_);
		break;
	case 4:// 期限変更
		printf("タスクの期限を入力してください\n");
		scanf_s("%s", &deadline_, 30);
		task->SetDeadLine(deadline_);
		break;
	case 5:// ステータス変更
		printf("タスクのステータスを選択してください\n");
		printf("0:未完了\n");
		printf("1:完了\n");
		scanf_s("%d", &statusNum_);
		task->SetStatusNum(statusNum_);
		break;
	case 6:// 一括変更
		printf("担当者IDを入力して、担当者を選択してください\n");
		for (auto itr = pics_.begin(); itr != pics_.end(); ++itr) {
			PersonInCharge* pic = *itr;

			pic->DrawPicAllInfo();
		}
		scanf_s("%d", &picID_);
		task->SetPicID(picID_);

		printf("タスクの題名を入力してください\n");
		scanf_s("%s", &taskTitle_, 20);
		task->SetTaskTitle(taskTitle_);

		printf("タスクの内容を入力してください\n");
		scanf_s("%s", &taskContent_, 100);
		task->SetTaskContent(taskContent_);

		printf("タスクの優先度を選択してください\n");
		printf("0:低め\n");
		printf("1:普通\n");
		printf("2:高め\n");
		scanf_s("%d", &priorityNum_);
		task->SetPriorityNum(priorityNum_);

		printf("タスクの期限を入力してください\n");
		scanf_s("%s", &deadline_, 30);
		task->SetDeadLine(deadline_);

		printf("タスクのステータスを選択してください\n");
		printf("0:未完了\n");
		printf("1:完了\n");
		scanf_s("%d", &statusNum_);
		task->SetStatusNum(statusNum_);
		break;
	default:
		operatorNum = 0;
		break;
	}
}

void TaskManager::ShowUpdate()
{
	switch (displayNum)
	{
	case 0:
	{
		printf("\n[タスクの一覧表示]\n");
		int taskNum = tasks_.size();
		printf("タスクの数:%d\n", taskNum);
		printf("タスク一覧:{\n");
		// リスト一覧の表示
		for (auto task : tasks_) {
			task->DrawAllInfo();
			printf("\n");
		}
		printf("}\n");
		printf("\n------------------------------------\n");
		printf("0.要素の表示に戻る\n");
		printf("1.要素の操作に戻る\n");
		scanf_s("%d", &operatorNum);
		if (operatorNum == 0) {
			operatorNum = 2;
		}
		else if (operatorNum == 1) {
			operatorNum = 0;
		}
		break;
	}
	case 1:
	{
		Task* task = new Task;
		// 番号を指定して要素を表示
		printf("\n[IDを指定して表示]\n");
		printf("表示したいタスクのIDを指定してください。\n");
		for (auto task : tasks_) {
			task->DrawTaskID();
			task->DrawTaskTitle();
			printf("\n");
		}
		scanf_s("%d", &taskID_);

		task = SearchTask(taskID_);
		task->DrawAllInfo();
		printf("\n------------------------------------\n");
		printf("0.要素の表示に戻る\n");
		printf("1.要素の操作に戻る\n");
		scanf_s("%d", &operatorNum);
		if (operatorNum == 0) {
			operatorNum = 2;
		}
		else if (operatorNum == 1) {
			operatorNum = 0;
		}
		break;
	}
	default:
		break;
	}
	if (displayNum == 9) {
		operatorNum = 0;
	}
}

Task* TaskManager::SearchTask(int taskID)
{
	Task* result = new Task;
	for (auto itr = tasks_.begin(); itr != tasks_.end(); ++itr) {
		result = *itr;
		if (result->GetTaskID() == taskID) {
			return result;
		}
	}
}

void TaskManager::DeleteTask(int taskID)
{
	Task* result = new Task;
	for (auto itr = tasks_.begin(); itr != tasks_.end();) {
		result = *itr;
		if (result->GetTaskID() == taskID) {
			tasks_.erase(itr);
			break;
		}
		else {
			++itr;
		}
	}
}
