#include "TaskManager.h"

int main() {

	// ���[�v���Ŏg�����̂�錾
	TaskManager* taskManager = new TaskManager;

	taskManager->Initialize();

	while (true)
	{
		taskManager->Update();
	}

	return 0;
}