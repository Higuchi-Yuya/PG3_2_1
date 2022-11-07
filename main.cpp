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

	// �擪�Z����錾
	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	int iterator;
	int inputValue;
	CELL *insertCell;

	while (true) {

		printf("���Ԗڂ̃Z���̌��ɑ}�����܂����H\n");
		scanf_s("%d", &iterator);

		printf("�}������l����͂��Ă��������H\n");
		scanf_s("%s", &name, 8);

		// �C�ӂ̃Z�������ɒǉ�
		insertCell = getInsertAddress(&head, iterator);
		create(insertCell, name);

		// ���X�g�ꗗ�̕\��
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
