#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cell {
	char name[8];
	char kashidasi[8];
	char henkyaku[8];
	struct cell* next;
}CELL;

void create(CELL* endCell, const char* name, const char* kanshidasi, const char* henakyaku);
void index(CELL *firstCell);

int main() {

	char name[8];
	char kashidasi[8];
	char henkyaku[8];

	// 先頭セルを宣言
	CELL head;
	head.next = nullptr;


	while (true) {

		scanf_s("%s", name, 8);
		scanf_s("%s", kashidasi, 8);
		scanf_s("%s", henkyaku, 8);

		// 最後尾にセルを追加
		create(&head, name, kashidasi, henkyaku);

		// リスト一覧の表示
		index(&head);
	}

	return 0;

}

void create(CELL *endCell, const char* name, const char* kanshidasi, const char* henakyaku)
{
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->name, 8, name);
	strcpy_s(newCell->kashidasi, 8, kanshidasi);
	strcpy_s(newCell->henkyaku, 8, henakyaku);

	// 新規作成するセルのポインター＞値＝値
	newCell->next = nullptr;

	while (endCell->next != nullptr) {
		endCell = endCell->next;
	}

	endCell = newCell;
}

void index(CELL* firstCell)
{
	while (firstCell->next != nullptr) {
		firstCell = firstCell->next;
		printf("%s\n%s\n%s\n", firstCell->name, firstCell->kashidasi, firstCell->henkyaku);
	}
	
}
