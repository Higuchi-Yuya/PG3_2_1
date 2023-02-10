#include "TaskManager.h"

int main() {

	// ƒ‹[ƒv“à‚Åg‚¤‚à‚Ì‚ğéŒ¾
	TaskManager* taskManager = new TaskManager;

	taskManager->Initialize();

	while (true)
	{
		taskManager->Update();
	}

	return 0;
}