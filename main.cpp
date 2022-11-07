#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cell {
	char name[8];
	struct cell* prev;
	struct cell* next;
	
}CELL;

void create(CELL* currentCell, const char* name);
void index(CELL *endCell);
CELL* getInsertAddress(CELL* endCELL, int iterator);

int main() {

	char name[8];

	// 先頭セルを宣言
	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	int iterator;
	int inputValue;
	CELL *insertCell;

	while (true) {

		printf("何番目のセルの後ろに挿入しますか？\n");
		scanf_s("%d", &iterator);

		printf("挿入する値を入力してください？\n");
		scanf_s("%s", &name, 8);

		// 任意のセルを後ろに追加
		insertCell = getInsertAddress(&head, iterator);
		create(insertCell, name);

		// リスト一覧の表示
		index(&head);
	}

	return 0;

}

void create(CELL *currentCell, const char* name)
{
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->name, 8, name);
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	if (currentCell->next) {
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}

	currentCell->next = newCell;
}

void index(CELL* endCell)
{
	int no = 1;
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("%d", no);
		printf("%p", endCell->prev);
		printf("%s", endCell->name);
		printf("(%p)", endCell);
		printf("%p\n", endCell->next);
		no++;
	}
}

CELL* getInsertAddress(CELL *endCELL,int iterator)
{
	for (int i = 0; i < iterator; i++) {
		if (endCELL->next) {
			endCELL = endCELL->next;
		}else {
			break;
		}
	}
	return endCELL;
}
