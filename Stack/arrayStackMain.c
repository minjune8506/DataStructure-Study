#include "arraystack.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	ArrayStack *pStack;
	ArrayStackNode node;
	ArrayStackNode *pop;
	ArrayStackNode *peek;

	pStack = createArrayStack(10);
	node.data = 'a';
	for (int i = 0 ; i < pStack->maxElementCount ; i++)
	{
		pushAS(pStack, node);
		displayArrayStack(pStack);
		node.data++;
	}
	printf("is_full : %s\n", isArrayStackFull(pStack) ? "true" : "false");
	for (int i = 0 ; i < pStack->maxElementCount ; i++)
	{
		peek = peekAS(pStack);
		pop = popAS(pStack);
		printf("peek : %c\n", peek->data);
		printf("pop : %c\n", pop->data);
		displayArrayStack(pStack);
	}
	printf("is_empty : %s\n", isArrayStackEmpty(pStack) ? "true" : "false");
	deleteArrayStack(pStack);
	// system("leaks a.out");
}

