#include "linkedstack.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	LinkedStack *stack;
	StackNode node;
	StackNode *pop;
	StackNode *peek;

	stack = createLinkedStack();

	node.data = 'a';
	for (int i = 0; i < 5 ; i++)
	{
		pushLS(stack, node);
		displayLinkedStack(stack);
		node.data++;
	}
	for (int i = 0 ; i < 5 ; i++)
	{
		peek = peekLS(stack);
		pop = popLS(stack);
		printf("peek : %c, pop : %c\n", peek->data, pop->data);
		free(pop);
		displayLinkedStack(stack);
	}
	printf("isEmpty : %s\n", isLinkedStackEmpty(stack) ? "true" : "false");
	deleteLinkedStack(stack);
	// system("leaks a.out");
}
