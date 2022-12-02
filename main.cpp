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

	// 先頭セルを宣言
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
			printf("\n[要素の操作]\n");
			printf("1.要素の表示\n");
			printf("2.要素の挿入\n");
			if (head.next != nullptr) {
				printf("3.要素の編集\n");
				printf("4.要素の削除\n");
			}
			printf("\n------------------------------------\n");
			printf("操作を選択してください\n");

			scanf_s("%d", &operationNum);
			break;
		#pragma region 要素の表示
		case 1:// 要素の表示
			printf("\n[要素の表示]\n");
			printf("1.要素の一覧表示\n");
			printf("2.要素の番号を指定して要素を表示\n");
			printf("9.要素操作に戻る\n");

			printf("\n操作を選択してください\n");
			scanf_s("%d", &displayNum);

			switch (displayNum)
			{
			case 1:
				printf("\n[要素の一覧表示]\n");
				printf("要素数:%d", num);
				printf("要素一覧:{\n");
				// リスト一覧の表示
				index(&head, no);
				printf("}\n");
				printf("\n------------------------------------\n");
				printf("1.要素の表示に戻る\n");
				printf("2.要素の操作に戻る\n");
				scanf_s("%d", &operationNum);
				if (operationNum == 2) {
					operationNum = 0;
				}
				break;
			case 2:
				// 番号を指定して要素を表示
				printf("\n[番号を指定して表示]\n");
				printf("表示したい要素の番号を指定してください。\n");
				scanf_s("%d", &iterator);
				// 任意のセルを後ろに追加
				insertCell = getInsertAddressHe(&head, iterator);
				indexSpecify(insertCell, iterator);
				printf("\n------------------------------------\n");
				printf("1.要素の表示に戻る\n");
				printf("2.要素の操作に戻る\n");
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

		#pragma region 要素の挿入
		case 2:
			iterator = 0;
			printf("\n[要素の挿入]\n");
			printf("要素を追加する場所を指定してください。最後尾に追加する場合は何も入力しないでください。\n");
			scanf_s("%d", &iterator);
			// 任意のセルを後ろに追加
			insertCell = getInsertAddressSo(&head, iterator);
			iteratorCount_ = iteratorCount(&head, iterator);
			printf("追加する要素の値を入力してください\n");
			scanf_s("%s", &name, 15);

			create(insertCell, name);

			printf("要素”%s”が%d番目に挿入されました\n", name, iteratorCount_);

			num++;
			operationNum = 0;
			break;
#pragma endregion

		#pragma region 要素の編集
		case 3:
			printf("\n[要素の編集]\n");
			printf("編集したい要素の番号を指定してください\n");
			scanf_s("%d", &iterator);
			// 任意のセルを後ろに追加
			insertCell = getInsertAddressHe(&head, iterator);
			printf("%d番目の要素の変更する値を入力してください。\n", iterator);
			scanf_s("%s", &name, 15);

			strcpy_s(insertCell->name, 15, name);

			printf("%d番目の要素の値が”%s”に変更されました\n", iterator, name);
			operationNum = 0;
			break;
#pragma endregion

		#pragma region 要素の削除
		case 4:
			printf("\n[要素の削除]\n");
			printf("削除したい要素番号を指定してください。\n");
			scanf_s("%d", &iterator);

			insertCell = getInsertAddressHe(&head, iterator);
			strcpy_s(name, 15, insertCell->name);
			

			deleteCell(&head,iterator);
			printf("%d番目の要素”%s”を削除しました\n", iterator, name);
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
	// 新規作成するセルのメモリ確保
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
		printf("”%s”:,\n", endCell->name);
		//printf("(%p):", endCell);
		//printf("%p\n", endCell->next);
		no++;
	}
}

void indexSpecify(CELL* endCell, int iterator)
{
	printf("%d:", iterator);
	printf("”%s”,\n", endCell->name);
}

CELL* getInsertAddressSo(CELL* endCELL, int iterator)
{
	for (int i = 1; i < iterator; i++) {
		if (endCELL->next) {
			endCELL = endCELL->next;
		}
		else {
			printf("%d番目の要素が見つかりませんでした。", iterator);
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
			printf("%d番目の要素が見つかりませんでした。", iterator);
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
			printf("%d番目の要素が見つかりませんでした。", iterator);
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
