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
	printf("�Z�b�g�ł��郁���o�[");
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
	printf("�薼:%s\n", taskTitle);
}

void Task::DrawTaskContent()
{
	printf("�^�X�N���e:%s\n", taskContent);
}

void Task::DrawPriority()
{
	// �󂯎�����D��x�̔ԍ��ŗD��x�����߂�
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

	// �D��x�̕`��
	switch (priority)
	{
	case Task::Lower:
		printf("�D��x:���\n");
		break;
	case Task::Usually:
		printf("�D��x:����\n");
		break;
	case Task::Higher:
		printf("�D��x:����\n");
		break;
	default:
		break;
	}
	
}

void Task::DrawDeadLine()
{
	printf("����:%s\n", deadline);
}

void Task::DrawStatus()
{
	// �X�e�[�^�X��ԍ��Ŏ󂯎��X�e�[�^�X�̐ݒ���s��
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

	// �󂯎�������̂�`��
	switch (status)
	{
	case Task::Incomplete:
		printf("�X�e�[�^�X:������\n");
		break;
	case Task::Completion:
		printf("�X�e�[�^�X:����\n");
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
