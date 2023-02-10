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
	case 0:// �^�X�N������
		printf("\n[�^�X�N�̑���]\n");
		printf("1.�^�X�N�̐V�K�쐬\n");
		printf("2.�^�X�N�̕\��\n");
		if (tasks_.size() != 0) {
			printf("3.�^�X�N�̕ҏW\n");
			printf("4.�^�X�N�̍폜\n");
		}
		printf("\n------------------------------------\n");
		printf("�����I�����Ă�������\n");

		scanf_s("%d", &operatorNum);
		break;

	#pragma region �V�K�^�X�N�̍쐬
	case 1:// �V�K�^�X�N���쐬
	{
		printf("\n[�^�X�N�̐V�K�쐬]\n");
		Task* task = new Task;
		printf("�^�X�NID����͂��ĉ�����\n");
		scanf_s("%d", &taskID_);
		task->SetID(taskID_);

		printf("�S����ID����͂��āA�S���҂�I�����Ă�������\n");
		for (auto itr = pics_.begin(); itr != pics_.end(); ++itr) {
			PersonInCharge* pic = *itr;

			pic->DrawPicAllInfo();
		}
		scanf_s("%d", &picID_);
		task->SetPicID(picID_);

		printf("�^�X�N�̑薼����͂��Ă�������\n");
		scanf_s("%s", &taskTitle_,20);
		task->SetTaskTitle(taskTitle_);

		printf("�^�X�N�̓��e����͂��Ă�������\n");
		scanf_s("%s", &taskContent_, 100);
		task->SetTaskContent(taskContent_);

		printf("�^�X�N�̗D��x��I�����Ă�������\n");
		printf("0:���\n");
		printf("1:����\n");
		printf("2:����\n");
		scanf_s("%d", &priorityNum_);
		task->SetPriorityNum(priorityNum_);

		printf("�^�X�N�̊�������͂��Ă�������\n");
		scanf_s("%s", &deadline_, 30);
		task->SetDeadLine(deadline_);

		printf("�^�X�N�̃X�e�[�^�X��I�����Ă�������\n");
		printf("0:������\n");
		printf("1:����\n");
		scanf_s("%d", &statusNum_);
		task->SetStatusNum(statusNum_);

		tasks_.push_back(task);
		printf("�^�X�NID:%d�̍쐬���������܂����B\n",task->GetTaskID());
		operatorNum = 0;
	}
	break;
	#pragma endregion

	#pragma region �^�X�N�̕\��
	case 2:// �^�X�N�̕\��
		printf("\n[�^�X�N�̕\��]\n");
		printf("0.�^�X�N�̈ꗗ�\��\n");
		printf("1.�^�X�N��ID���w�肵�ă^�X�N��\��\n");
		printf("9.�^�X�N����ɖ߂�\n");

		printf("\n�����I�����Ă�������\n");
		scanf_s("%d", &displayNum);

		// �\���ԍ��ł̑���
		ShowUpdate();

		break;
	#pragma endregion

	#pragma region �^�X�N�̕ҏW
	case 3:
	{
		if (tasks_.size() != 0) {
			Task* task = new Task;
			printf("\n[�v�f�̕ҏW]\n");
			printf("�ҏW�������^�X�N��ID���w�肵�Ă�������\n");
			for (auto task : tasks_) {
				task->DrawTaskID();
				task->DrawTaskTitle();
				printf("\n");
			}
			scanf_s("%d", &taskID_);

			// �T�[�`�������̂���
			task = SearchTask(taskID_);
			task->DrawTaskID();
			task->DrawTaskTitle();
			printf("\n");
			printf("�ύX���������̂�I��ł��������B\n");
			printf("0:�S����\n");
			printf("1:�薼\n");
			printf("2:���e\n");
			printf("3:�D��x\n");
			printf("4:����\n");
			printf("5:�X�e�[�^�X\n");
			printf("6:�ꊇ�ύX\n");
			printf("7:�ύX�Ȃ�\n");
			scanf_s("%d", &editNum);

			// �ύX����
			EditUpdate();

			printf("�^�X�NID:%d�̕ύX���������܂����B\n", task->GetTaskID());
		}
		operatorNum = 0;
		break;
	}
	#pragma endregion

	#pragma region �^�X�N�̍폜
	case 4:
	{
		if (tasks_.size() != 0) {
			printf("\n[�^�X�N�̍폜]\n");
			printf("0:�S�Ẵ^�X�N���폜�B\n");
			printf("1:ID���w�肵�āA�^�X�N���폜�B\n");
			scanf_s("%d", &deleteNum);
			switch (deleteNum)
			{
			case 0:// �S�폜
				tasks_.clear();
				printf("�S�Ẵ^�X�N���폜���܂����B\n");
				break;
			case 1:// �w�肵�č폜
			{
				Task* task = new Task;
				printf("�폜�������^�X�N��ID���w�肵�Ă��������B\n");
				for (auto task : tasks_) {
					task->DrawTaskID();
					task->DrawTaskTitle();
					printf("\n");
				}
				scanf_s("%d", &taskID_);

				DeleteTask(taskID_);
				printf("�^�X�NID:%d�̍폜�����܂���\n", taskID_);
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
	// �T�[�`�������̂���
	task = SearchTask(taskID_);
	switch (editNum)
	{
	case 0:// �S���ҕύX
		printf("�S����ID����͂��āA�S���҂�I�����Ă�������\n");
		for (auto itr = pics_.begin(); itr != pics_.end(); ++itr) {
			PersonInCharge* pic = *itr;

			pic->DrawPicAllInfo();
		}
		scanf_s("%d", &picID_);
		task->SetPicID(picID_);
		break;
	case 1:// �薼�ύX
		printf("�^�X�N�̑薼����͂��Ă�������\n");
		scanf_s("%s", &taskTitle_, 20);
		task->SetTaskTitle(taskTitle_);
		break;
	case 2:// ���e�ύX
		printf("�^�X�N�̓��e����͂��Ă�������\n");
		scanf_s("%s", &taskContent_, 100);
		task->SetTaskContent(taskContent_);
		break;
	case 3:// �D��x�ύX
		printf("�^�X�N�̗D��x��I�����Ă�������\n");
		printf("0:���\n");
		printf("1:����\n");
		printf("2:����\n");
		scanf_s("%d", &priorityNum_);
		task->SetPriorityNum(priorityNum_);
		break;
	case 4:// �����ύX
		printf("�^�X�N�̊�������͂��Ă�������\n");
		scanf_s("%s", &deadline_, 30);
		task->SetDeadLine(deadline_);
		break;
	case 5:// �X�e�[�^�X�ύX
		printf("�^�X�N�̃X�e�[�^�X��I�����Ă�������\n");
		printf("0:������\n");
		printf("1:����\n");
		scanf_s("%d", &statusNum_);
		task->SetStatusNum(statusNum_);
		break;
	case 6:// �ꊇ�ύX
		printf("�S����ID����͂��āA�S���҂�I�����Ă�������\n");
		for (auto itr = pics_.begin(); itr != pics_.end(); ++itr) {
			PersonInCharge* pic = *itr;

			pic->DrawPicAllInfo();
		}
		scanf_s("%d", &picID_);
		task->SetPicID(picID_);

		printf("�^�X�N�̑薼����͂��Ă�������\n");
		scanf_s("%s", &taskTitle_, 20);
		task->SetTaskTitle(taskTitle_);

		printf("�^�X�N�̓��e����͂��Ă�������\n");
		scanf_s("%s", &taskContent_, 100);
		task->SetTaskContent(taskContent_);

		printf("�^�X�N�̗D��x��I�����Ă�������\n");
		printf("0:���\n");
		printf("1:����\n");
		printf("2:����\n");
		scanf_s("%d", &priorityNum_);
		task->SetPriorityNum(priorityNum_);

		printf("�^�X�N�̊�������͂��Ă�������\n");
		scanf_s("%s", &deadline_, 30);
		task->SetDeadLine(deadline_);

		printf("�^�X�N�̃X�e�[�^�X��I�����Ă�������\n");
		printf("0:������\n");
		printf("1:����\n");
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
		printf("\n[�^�X�N�̈ꗗ�\��]\n");
		int taskNum = tasks_.size();
		printf("�^�X�N�̐�:%d\n", taskNum);
		printf("�^�X�N�ꗗ:{\n");
		// ���X�g�ꗗ�̕\��
		for (auto task : tasks_) {
			task->DrawAllInfo();
			printf("\n");
		}
		printf("}\n");
		printf("\n------------------------------------\n");
		printf("0.�v�f�̕\���ɖ߂�\n");
		printf("1.�v�f�̑���ɖ߂�\n");
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
		// �ԍ����w�肵�ėv�f��\��
		printf("\n[ID���w�肵�ĕ\��]\n");
		printf("�\���������^�X�N��ID���w�肵�Ă��������B\n");
		for (auto task : tasks_) {
			task->DrawTaskID();
			task->DrawTaskTitle();
			printf("\n");
		}
		scanf_s("%d", &taskID_);

		task = SearchTask(taskID_);
		task->DrawAllInfo();
		printf("\n------------------------------------\n");
		printf("0.�v�f�̕\���ɖ߂�\n");
		printf("1.�v�f�̑���ɖ߂�\n");
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
