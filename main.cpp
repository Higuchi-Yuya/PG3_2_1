#include "TaskManager.h"

int main() {

	// ループ内で使うものを宣言
	TaskManager* taskManager = new TaskManager;

	taskManager->Initialize();

	while (true)
	{
		taskManager->Update();
	}

	return 0;
}