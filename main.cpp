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

	// �擪�Z����錾
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
			printf("\n[�v�f�̑���]\n");
			printf("1.�v�f�̕\��\n");
			printf("2.�v�f�̑}��\n");
			if (head.next != nullptr) {
				printf("3.�v�f�̕ҏW\n");
				printf("4.�v�f�̍폜\n");
			}
			printf("\n------------------------------------\n");
			printf("�����I�����Ă�������\n");

			scanf_s("%d", &operationNum);
			break;
		#pragma region �v�f�̕\��
		case 1:// �v�f�̕\��
			printf("\n[�v�f�̕\��]\n");
			printf("1.�v�f�̈ꗗ�\��\n");
			printf("2.�v�f�̔ԍ����w�肵�ėv�f��\��\n");
			printf("9.�v�f����ɖ߂�\n");

			printf("\n�����I�����Ă�������\n");
			scanf_s("%d", &displayNum);

			switch (displayNum)
			{
			case 1:
				printf("\n[�v�f�̈ꗗ�\��]\n");
				printf("�v�f��:%d", num);
				printf("�v�f�ꗗ:{\n");
				// ���X�g�ꗗ�̕\��
				index(&head, no);
				printf("}\n");
				printf("\n------------------------------------\n");
				printf("1.�v�f�̕\���ɖ߂�\n");
				printf("2.�v�f�̑���ɖ߂�\n");
				scanf_s("%d", &operationNum);
				if (operationNum == 2) {
					operationNum = 0;
				}
				break;
			case 2:
				// �ԍ����w�肵�ėv�f��\��
				printf("\n[�ԍ����w�肵�ĕ\��]\n");
				printf("�\���������v�f�̔ԍ����w�肵�Ă��������B\n");
				scanf_s("%d", &iterator);
				// �C�ӂ̃Z�������ɒǉ�
				insertCell = getInsertAddressHe(&head, iterator);
				indexSpecify(insertCell, iterator);
				printf("\n------------------------------------\n");
				printf("1.�v�f�̕\���ɖ߂�\n");
				printf("2.�v�f�̑���ɖ߂�\n");
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

		#pragma region �v�f�̑}��
		case 2:
			iterator = 0;
			printf("\n[�v�f�̑}��]\n");
			printf("�v�f��ǉ�����ꏊ���w�肵�Ă��������B�Ō���ɒǉ�����ꍇ�͉������͂��Ȃ��ł��������B\n");
			scanf_s("%d", &iterator);
			// �C�ӂ̃Z�������ɒǉ�
			insertCell = getInsertAddressSo(&head, iterator);
			iteratorCount_ = iteratorCount(&head, iterator);
			printf("�ǉ�����v�f�̒l����͂��Ă�������\n");
			scanf_s("%s", &name, 15);

			create(insertCell, name);

			printf("�v�f�h%s�h��%d�Ԗڂɑ}������܂���\n", name, iteratorCount_);

			num++;
			operationNum = 0;
			break;
#pragma endregion

		#pragma region �v�f�̕ҏW
		case 3:
			printf("\n[�v�f�̕ҏW]\n");
			printf("�ҏW�������v�f�̔ԍ����w�肵�Ă�������\n");
			scanf_s("%d", &iterator);
			// �C�ӂ̃Z�������ɒǉ�
			insertCell = getInsertAddressHe(&head, iterator);
			printf("%d�Ԗڂ̗v�f�̕ύX����l����͂��Ă��������B\n", iterator);
			scanf_s("%s", &name, 15);

			strcpy_s(insertCell->name, 15, name);

			printf("%d�Ԗڂ̗v�f�̒l���h%s�h�ɕύX����܂���\n", iterator, name);
			operationNum = 0;
			break;
#pragma endregion

		#pragma region �v�f�̍폜
		case 4:
			printf("\n[�v�f�̍폜]\n");
			printf("�폜�������v�f�ԍ����w�肵�Ă��������B\n");
			scanf_s("%d", &iterator);

			insertCell = getInsertAddressHe(&head, iterator);
			strcpy_s(name, 15, insertCell->name);
			

			deleteCell(&head,iterator);
			printf("%d�Ԗڂ̗v�f�h%s�h���폜���܂���\n", iterator, name);
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
	// �V�K�쐬����Z���̃������m��
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
		printf("�h%s�h:,\n", endCell->name);
		//printf("(%p):", endCell);
		//printf("%p\n", endCell->next);
		no++;
	}
}

void indexSpecify(CELL* endCell, int iterator)
{
	printf("%d:", iterator);
	printf("�h%s�h,\n", endCell->name);
}

CELL* getInsertAddressSo(CELL* endCELL, int iterator)
{
	for (int i = 1; i < iterator; i++) {
		if (endCELL->next) {
			endCELL = endCELL->next;
		}
		else {
			printf("%d�Ԗڂ̗v�f��������܂���ł����B", iterator);
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
			printf("%d�Ԗڂ̗v�f��������܂���ł����B", iterator);
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
			printf("%d�Ԗڂ̗v�f��������܂���ł����B", iterator);
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
