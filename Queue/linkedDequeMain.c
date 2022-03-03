#include "linkeddeque.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	LinkedDeque *pDeque;
	DequeNode node;
	DequeNode *delete;
	DequeNode *peek;

	pDeque = createLinkedDeque();
	node.data = 'a';
	for (int i = 0 ; i < 5 ; i++)
	{
		insertFrontLD(pDeque, node);
		node.data++;
	}
	displayLinkedDeque(pDeque);
	for (int i = 0 ; i < 5 ; i++)
	{
		insertRearLD(pDeque, node);
		node.data++;
	}
	displayLinkedDeque(pDeque);
	for (int i = 0 ; i < 5 ; i++)
	{
		peek = peekFrontLD(pDeque);
		delete = deleteFrontLD(pDeque);
		printf("peek : %c, delete : %c\n", peek->data, delete->data);
		free(delete);
		node.data++;
	}
	printf("\n");
	displayLinkedDeque(pDeque);
	for (int i = 0 ; i < 5 ; i++)
	{
		peek = peekRearLD(pDeque);
		delete = deleteRearLD(pDeque);
		printf("peek : %c, delete : %c\n", peek->data, delete->data);
		free(delete);
		node.data++;
	}
	printf("\n");
	displayLinkedDeque(pDeque);
	printf("isLinkedDequeEmpty : %s\n", isLinkedDequeEmpty(pDeque) ? "true" : "false");
	deleteLinkedDeque(pDeque);
	// system("leaks a.out");
}
