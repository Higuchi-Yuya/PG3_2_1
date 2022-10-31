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

	// �擪�Z����錾
	CELL head;
	head.next = nullptr;


	while (true) {

		scanf_s("%s", name, 8);
		scanf_s("%s", kashidasi, 8);
		scanf_s("%s", henkyaku, 8);

		// �Ō���ɃZ����ǉ�
		create(&head, name, kashidasi, henkyaku);

		// ���X�g�ꗗ�̕\��
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

	// �V�K�쐬����Z���̃|�C���^�[���l���l
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
