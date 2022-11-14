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

	const char* Yamanote[] = { "‘å‹{","‚³‚¢‚½‚ÜV“sS","—^–ì","–k‰Y˜a","‰Y˜a",
							   "“ì‰Y˜a","˜n","¼ìŒû","ìŒû","Ô‰H",
							   "“Œ\ð","‰¤Žq","ã’†—¢","“c’[","¼“ú•é—¢",
							   "“ú•é—¢","éò’J","ã–ì","Œä“k’¬","H—tŒ´",
							   "_“c","“Œ‹ž","—LŠy’¬","V‹´","•l¼’¬",
							   "“c’¬","•iì","‘åˆä’¬","‘åX","Š—“c",
							   "ìè","’ßŒ©","VŽqˆÀ","“Œ_“Þì","‰¡•l",
							   "÷–Ø’¬","ŠÖ“à","Îì’¬","ŽRŽè","ªŠÝ",
							   "ˆéŽq","V™“c","—mŒõ‘ä","`“ì‘ä","–{‹½‘ä","‘å‘D" };

	// æ“ªƒZƒ‹‚ðéŒ¾
	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	int iterator;
	int inputValue;
	CELL *insertCell;

	while (true) {

		printf("‰½”Ô–Ú‚ÌƒZƒ‹‚ÌŒã‚ë‚É‘}“ü‚µ‚Ü‚·‚©H\n");
		scanf_s("%d", &iterator);

		printf("‘}“ü‚·‚é’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢H\n");
		scanf_s("%s", &name, 15);

		// ”CˆÓ‚ÌƒZƒ‹‚ðŒã‚ë‚É’Ç‰Á
		insertCell = getInsertAddress(&head, iterator);
		create(insertCell, name);

		// ƒŠƒXƒgˆê——‚Ì•\Ž¦
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
