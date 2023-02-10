#pragma once
#include <stdio.h>
#include <list>
#include "PersonInCharge.h"

/// <summary>
/// ��̃^�X�N���e
/// </summary>
class Task
{
public:// �T�u
	enum Priority
	{
		Lower,   // ��� 0
		Usually, // ���� 1
		Higher,  // ���� 2
	};
	enum Status
	{
		Incomplete, // ������ 0
		Completion, // ����   1
	};

public:// �����o�֐�
	// ���̏��n
	int GetTaskID() { return taskID; }

	// �\��

	// �^�X�NID�̕\��
	void DrawTaskID();

	// �^�X�N�̒S���҂�����\��
	void DrawAllPics();

	// �^�X�N�P�̂̒S���҂̕\��
	void DrawPic();

	// �^�X�N�̑薼��\��
	void DrawTaskTitle();

	// �^�X�N�̓��e��\��
	void DrawTaskContent();

	// �^�X�N�̗D��x��\��
	void DrawPriority();

	// �^�X�N�̊�����\��
	void DrawDeadLine();

	// �^�X�N�̃X�e�[�^�X��\��
	void DrawStatus();

	// �^�X�N�̑S����\��
	void DrawAllInfo();


	// �Z�b�^�[
	void SetID(int taskID) { this->taskID = taskID; }
	void SetPicID(int picID) { this->picID = picID; }
	void SetTaskTitle(const char* taskTitle) { strcpy_s(this->taskTitle, 20, taskTitle); }
	void SetTaskContent(const char* taskContent) { strcpy_s(this->taskContent,100, taskContent); }
	void SetPriorityNum(int priorityNum) { this->priorityNum = priorityNum; }
	void SetDeadLine(const char* deadline) { strcpy_s(this->deadline, 30, deadline); }
	void SetStatusNum(int statusNum) { this->statusNum = statusNum; }
	static void SetPersonInCharge(std::list<PersonInCharge*>pics) { Task::pics = pics; }

private:// �����o�ϐ�

	// �^�X�N��ID
	int taskID = 0;

	// �S���҂̃��X�g�i�I���\�j
	int picID = 0;
	static std::list<PersonInCharge*> pics;

	// �Z�b�g�����S����
	PersonInCharge pic;

	// �薼
	char taskTitle[20];

	// ���e
	char taskContent[100];

	// �D��x
	int priorityNum = 0;

	Priority priority = Priority::Usually;

	// ����
	char deadline[30];

	// �X�e�[�^�X
	int statusNum = 0;

	Status status = Status::Incomplete;

};

