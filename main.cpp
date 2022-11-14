#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>

typedef struct cell {
	char name[15];
	struct cell* prev;
	struct cell* next;
	
}CELL;

void create(CELL* currentCell, const char* name);
void index(CELL *endCell);
CELL* getInsertAddress(CELL* endCELL, int iterator);

int main() {

	char name[15];

	const char* Yamanote[] = { "大宮","さいたま新都心","与野","北浦和","浦和",
							   "南浦和","蕨","西川口","川口","赤羽",
							   "東十条","王子","上中里","田端","西日暮里",
							   "日暮里","鶯谷","上野","御徒町","秋葉原",
							   "神田","東京","有楽町","新橋","浜松町",
							   "田町","品川","大井町","大森","蒲田",
							   "川崎","鶴見","新子安","東神奈川","横浜",
							   "桜木町","関内","石川町","山手","根岸",
							   "磯子","新杉田","洋光台","港南台","本郷台","大船" };

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
		scanf_s("%s", &name, 15);

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
