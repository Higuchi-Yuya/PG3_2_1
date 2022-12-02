#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct cell {
	char name[15];
	struct cell* prev;
	struct cell* next;

}CELL;

void create(CELL* currentCell, const char* name);
void edit(CELL* currentCell, const char* name);
void deleteCell(CELL* currentCell, int& itrator);
void index(CELL* endCell, int no);
void indexSpecify(CELL* endCell, int iterator);
CELL* getInsertAddressSo(CELL* endCELL, int iterator);
CELL* getInsertAddressHe(CELL* endCELL, int iterator);
int iteratorCount(CELL* endCELL, int iterator);

int main() {

	char name[15];

	// æ“ªƒZƒ‹‚ğéŒ¾
	CELL head;
	//head.name[0] = {'a'};
	head.next = nullptr;
	head.prev = nullptr;

	int no = 1;
	int iteratorCount_ = 0;
	int num = 0;
	int operationNum = 0;
	int displayNum = 0;

	int iterator = 0;
	int inputValue = 0;
	CELL* insertCell;

	while (true) {


		switch (operationNum)
		{
		case 0:
			printf("\n[—v‘f‚Ì‘€ì]\n");
			printf("1.—v‘f‚Ì•\¦\n");
			printf("2.—v‘f‚Ì‘}“ü\n");
			if (head.next != nullptr) {
				printf("3.—v‘f‚Ì•ÒW\n");
				printf("4.—v‘f‚Ìíœ\n");
			}
			printf("\n------------------------------------\n");
			printf("‘€ì‚ğ‘I‘ğ‚µ‚Ä‚­‚¾‚³‚¢\n");

			scanf_s("%d", &operationNum);
			break;
		#pragma region —v‘f‚Ì•\¦
		case 1:// —v‘f‚Ì•\¦
			printf("\n[—v‘f‚Ì•\¦]\n");
			printf("1.—v‘f‚Ìˆê——•\¦\n");
			printf("2.—v‘f‚Ì”Ô†‚ğw’è‚µ‚Ä—v‘f‚ğ•\¦\n");
			printf("9.—v‘f‘€ì‚É–ß‚é\n");

			printf("\n‘€ì‚ğ‘I‘ğ‚µ‚Ä‚­‚¾‚³‚¢\n");
			scanf_s("%d", &displayNum);

			switch (displayNum)
			{
			case 1:
				printf("\n[—v‘f‚Ìˆê——•\¦]\n");
				printf("—v‘f”:%d", num);
				printf("—v‘fˆê——:{\n");
				// ƒŠƒXƒgˆê——‚Ì•\¦
				index(&head, no);
				printf("}\n");
				printf("\n------------------------------------\n");
				printf("1.—v‘f‚Ì•\¦‚É–ß‚é\n");
				printf("2.—v‘f‚Ì‘€ì‚É–ß‚é\n");
				scanf_s("%d", &operationNum);
				if (operationNum == 2) {
					operationNum = 0;
				}
				break;
			case 2:
				// ”Ô†‚ğw’è‚µ‚Ä—v‘f‚ğ•\¦
				printf("\n[”Ô†‚ğw’è‚µ‚Ä•\¦]\n");
				printf("•\¦‚µ‚½‚¢—v‘f‚Ì”Ô†‚ğw’è‚µ‚Ä‚­‚¾‚³‚¢B\n");
				scanf_s("%d", &iterator);
				// ”CˆÓ‚ÌƒZƒ‹‚ğŒã‚ë‚É’Ç‰Á
				insertCell = getInsertAddressHe(&head, iterator);
				indexSpecify(insertCell, iterator);
				printf("\n------------------------------------\n");
				printf("1.—v‘f‚Ì•\¦‚É–ß‚é\n");
				printf("2.—v‘f‚Ì‘€ì‚É–ß‚é\n");
				scanf_s("%d", &operationNum);
				if (operationNum == 2) {
					operationNum = 0;
				}

			default:
				break;
			}
			if (displayNum == 9) {
				operationNum = 0;
			}

			break;
#pragma endregion

		#pragma region —v‘f‚Ì‘}“ü
		case 2:
			iterator = 0;
			printf("\n[—v‘f‚Ì‘}“ü]\n");
			printf("—v‘f‚ğ’Ç‰Á‚·‚éêŠ‚ğw’è‚µ‚Ä‚­‚¾‚³‚¢BÅŒã”ö‚É’Ç‰Á‚·‚éê‡‚Í‰½‚à“ü—Í‚µ‚È‚¢‚Å‚­‚¾‚³‚¢B\n");
			scanf_s("%d", &iterator);
			// ”CˆÓ‚ÌƒZƒ‹‚ğŒã‚ë‚É’Ç‰Á
			insertCell = getInsertAddressSo(&head, iterator);
			iteratorCount_ = iteratorCount(&head, iterator);
			printf("’Ç‰Á‚·‚é—v‘f‚Ì’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
			scanf_s("%s", &name, 15);

			create(insertCell, name);

			printf("—v‘fh%sh‚ª%d”Ô–Ú‚É‘}“ü‚³‚ê‚Ü‚µ‚½\n", name, iteratorCount_);

			num++;
			operationNum = 0;
			break;
#pragma endregion

		#pragma region —v‘f‚Ì•ÒW
		case 3:
			printf("\n[—v‘f‚Ì•ÒW]\n");
			printf("•ÒW‚µ‚½‚¢—v‘f‚Ì”Ô†‚ğw’è‚µ‚Ä‚­‚¾‚³‚¢\n");
			scanf_s("%d", &iterator);
			// ”CˆÓ‚ÌƒZƒ‹‚ğŒã‚ë‚É’Ç‰Á
			insertCell = getInsertAddressHe(&head, iterator);
			printf("%d”Ô–Ú‚Ì—v‘f‚Ì•ÏX‚·‚é’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\n", iterator);
			scanf_s("%s", &name, 15);

			strcpy_s(insertCell->name, 15, name);

			printf("%d”Ô–Ú‚Ì—v‘f‚Ì’l‚ªh%sh‚É•ÏX‚³‚ê‚Ü‚µ‚½\n", iterator, name);
			operationNum = 0;
			break;
#pragma endregion

		#pragma region —v‘f‚Ìíœ
		case 4:
			printf("\n[—v‘f‚Ìíœ]\n");
			printf("íœ‚µ‚½‚¢—v‘f”Ô†‚ğw’è‚µ‚Ä‚­‚¾‚³‚¢B\n");
			scanf_s("%d", &iterator);

			insertCell = getInsertAddressHe(&head, iterator);
			strcpy_s(name, 15, insertCell->name);
			

			deleteCell(&head,iterator);
			printf("%d”Ô–Ú‚Ì—v‘fh%sh‚ğíœ‚µ‚Ü‚µ‚½\n", iterator, name);
			num--;
			operationNum = 0;
			break;
#pragma endregion


		default:
			break;
		}

	}

	return 0;

}

void create(CELL* currentCell, const char* name)
{
	CELL* newCell;
	// V‹Kì¬‚·‚éƒZƒ‹‚Ìƒƒ‚ƒŠŠm•Û
	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->name, 15, name);
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	if (currentCell->next) {
		CELL* nextCell = currentCell;
		nextCell->prev = newCell;
	}

	currentCell->next = newCell;
}

void edit(CELL* currentCell, const char* name)
{
	strcpy_s(currentCell->name, 15, name);
}

void deleteCell(CELL* currentCell,int &itrator)
{
	CELL* head_ = currentCell;
	CELL* deleteCell = currentCell->next;
	for (int i = 0; i < itrator - 2; i++) {
		head_ = deleteCell;
		deleteCell = head_->next;
	}

	head_->next = deleteCell->next;
	
}

void index(CELL* endCell, int no)
{
	while (endCell->next != nullptr) {
		endCell = endCell->next;

		printf("%d:", no);
		//printf("%p:", endCell->prev);
		printf("h%sh:,\n", endCell->name);
		//printf("(%p):", endCell);
		//printf("%p\n", endCell->next);
		no++;
	}
}

void indexSpecify(CELL* endCell, int iterator)
{
	printf("%d:", iterator);
	printf("h%sh,\n", endCell->name);
}

CELL* getInsertAddressSo(CELL* endCELL, int iterator)
{
	for (int i = 1; i < iterator; i++) {
		if (endCELL->next) {
			endCELL = endCELL->next;
		}
		else {
			printf("%d”Ô–Ú‚Ì—v‘f‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½B", iterator);
			break;
		}
	}
	if (iterator == 0)
	{
		while (endCELL->next != nullptr) {
			endCELL = endCELL->next;
		}
	}
	return endCELL;
}

CELL* getInsertAddressHe(CELL* endCELL, int iterator)
{
	for (int i = 1; i <= iterator; i++) {
		if (endCELL->next) {
			endCELL = endCELL->next;
		}
		else {
			printf("%d”Ô–Ú‚Ì—v‘f‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½B", iterator);
			break;
		}
	}
	return endCELL;
}

int iteratorCount(CELL* endCELL, int iterator)
{
	int num = 1;
	for (int i = 1; i < iterator; i++) {
		if (endCELL->next) {
			endCELL = endCELL->next;
			num++;
		}
		else {
			printf("%d”Ô–Ú‚Ì—v‘f‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½B", iterator);
			break;
		}
	}
	if (iterator == 0)
	{
		while (endCELL->next != nullptr) {
			endCELL = endCELL->next;
			num++;
		}
	}
	return num;
}
