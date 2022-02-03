/*
 * Linked Stack
 * Author: minjkim2
 * Language:  C
 */
#include "linkedstack.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

LinkedStack *createLinkedStack()
{
	LinkedStack *stack;
 
	stack = (LinkedStack *)malloc(sizeof(LinkedStack));
	if (!stack)
		return (NULL);
	stack->currentElementCount = 0;
	stack->pTopElement = NULL;
	return (stack);
}

StackNode *createStackNode(char data)
{
	StackNode *node;

	node = (StackNode *)malloc(sizeof(StackNode));
	if (!node)
		return (NULL);
	node->data = data;
	node->pLink = NULL;
	return (node);
}

int pushLS(LinkedStack *pStack, StackNode element)
{
	StackNode *node;

	if (!pStack)
		return (EXIT_FAILURE);
	node = createStackNode(element.data);
	if (!pStack->pTopElement) // Empty Stack
		pStack->pTopElement = node;
	else
	{
		node->pLink = pStack->pTopElement;
		pStack->pTopElement = node;
	}
	pStack->currentElementCount++;
	return (EXIT_SUCCESS);
}

StackNode *popLS(LinkedStack *pStack)
{
	StackNode *node;

	if (!pStack || !pStack->pTopElement)
		return (NULL);
	node = pStack->pTopElement;
	pStack->pTopElement = pStack->pTopElement->pLink;
	pStack->currentElementCount--;
	return (node);
}

StackNode *peekLS(LinkedStack *pStack)
{
	StackNode *node;

	if (!pStack || !pStack->pTopElement)
		return (NULL);
	node = pStack->pTopElement;
	return (node);
}

void deleteLinkedStack(LinkedStack *pStack)
{
	StackNode *iter;
	StackNode *removed;
	
	iter = pStack->pTopElement;
	while (iter)
	{
		removed = iter;
		iter = iter->pLink;
		free(removed);
		pStack->currentElementCount--;
	}
	assert(pStack->currentElementCount == 0);
	free(pStack);
}

int isLinkedStackFull(LinkedStack *pStack)
{

}

int isLinkedStackEmpty(LinkedStack *pStack)
{
	return (pStack->currentElementCount == 0);
}

void display(LinkedStack *pStack)
{
	StackNode *iter;

	if (!pStack)
		return ;
	printf("currentElementcount : %d\n", pStack->currentElementCount);
	if (!pStack->pTopElement)
		printf("Empty stack\n");
	else
	{
		iter = pStack->pTopElement;
		printf("Stack : ");
		for ( ; iter != NULL ; iter = iter->pLink)
			printf("%c ", iter->data);
		printf("\n");
	}
}

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
		display(stack);
		node.data++;
	}
	for (int i = 0 ; i < 5 ; i++)
	{
		peek = peekLS(stack);
		pop = popLS(stack);
		printf("peek : %c, pop : %c\n", peek->data, pop->data);
		free(pop);
		display(stack);
	}
	printf("isEmpty : %s\n", isLinkedStackEmpty(stack) ? "true" : "false");
	deleteLinkedStack(stack);
	// system("leaks a.out");
}
