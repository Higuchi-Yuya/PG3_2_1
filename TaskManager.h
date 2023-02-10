#pragma once
#include "Task.h"
class TaskManager
{
public:
	void Initialize();

	void Update();

	void EditUpdate();

	void ShowUpdate();

	// �^�X�N��ID�Ń^�X�N��T��
	Task* SearchTask(int taskID);

	void DeleteTask(int taskID);

private:
	// �^�X�N���������鎞�Ɏg��ID
	int taskID_ = 0;

	// �S���҂�o�^����Ƃ��Ɏg��ID
	int picID_ = 0;

	// �薼
	char taskTitle_[20];

	// ���e
	char taskContent_[100];

	// �D��x
	int priorityNum_ = 0;

	// ����
	char deadline_[30];

	// �X�e�[�^�X
	int statusNum_ = 0;

	// ����ԍ�
	int operatorNum = 0;

	// �\�����̑���ԍ�
	int displayNum = 0;

	// �ҏW���̑���ԍ�
	int editNum = 0;

	// �폜���̑���ԍ�
	int deleteNum = 0;

	// �^�X�N��ۑ����Ƃ����X�g
	std::list<Task*>tasks_;

	// �S���҂����̃��X�g
	std::list<PersonInCharge*>pics_;


};

