#include "linkedstack.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// typedef struct StackNodeType
// {
// 	char data;
// 	struct StackNodeType* pLink;
// } StackNode;

// typedef struct LinkedStackType
// {
// 	int currentElementCount;
// 	StackNode* pTopElement;
// } LinkedStack;

LinkedStack* createLinkedStack()
{
    LinkedStack *p;
	
	p = (LinkedStack *)malloc(sizeof(LinkedStack));
    if (!p)
		return (NULL);
	p->currentElementCount = 0;
    p->pTopElement = NULL;
	return (p);
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
// Node x : -> top포인터에 추가
// Node o : 0 -> 1 -> 2 -> 처음부분에 노드 추가하고 pLink를 이어준다.
int pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode *node;
    StackNode *tmp;

    if (!pStack)
        return (EXIT_FAILURE);
	node = createStackNode(element.data);
    if (!pStack->pTopElement) // NULL -> Node x
		pStack->pTopElement = node;
	else // Node o
	{
        tmp = pStack->pTopElement;
        pStack->pTopElement = node;
        node->pLink = tmp;
	}
	pStack->currentElementCount++;
	return (EXIT_SUCCESS);
}

StackNode* popLS(LinkedStack* pStack)
{
	StackNode *tmp;

	if (!pStack || isLinkedStackEmpty(pStack))
		return (NULL);
	tmp = pStack->pTopElement;
	pStack->pTopElement = tmp->pLink;
	pStack->currentElementCount--;
	return (tmp);
}

StackNode* peekLS(LinkedStack* pStack)
{
    if (!pStack || isLinkedStackEmpty(pStack))
		return (NULL);
	return (pStack->pTopElement);
}

void deleteLinkedStack(LinkedStack* pStack)
{
	StackNode *node;
	StackNode *temp;

	node = pStack->pTopElement;
	while (node != NULL)
	{
		temp = node;
		node = node->pLink;
		free(temp);
		pStack->currentElementCount--;
	}
	assert(pStack->currentElementCount == 0);
	free(pStack);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	if (!pStack)
		return (-1);
	return (pStack->currentElementCount == 0);
}

void display(LinkedStack *pStack)
{
	StackNode *node;
	
	if (!pStack)
		return ;
	printf("currentElementCount : %d\n", pStack->currentElementCount);
	printf("Stack : ");
	for (node = pStack->pTopElement ; node ; node = node->pLink)
		printf("%c ", node->data);
	printf("\n");
}

int main(void)
{
	LinkedStack *pStack;
	StackNode node;
	StackNode *peek;
	StackNode *pop;

	pStack = createLinkedStack();
	node.data = 'a';
	for (int i = 0 ; i < 10 ; i++)
	{
		pushLS(pStack, node);
		display(pStack);
		node.data++;
	}
	for (int i = 0 ; i < 10 ; i++)
	{
		peek = peekLS(pStack);
		pop = popLS(pStack);
		printf("peek : %c, pop : %c\n", peek->data, pop->data);
		//pop 이후 free를 어디에서 해줘야하는가
		free(pop);
		display(pStack);
	}
	isLinkedStackEmpty(pStack);
	deleteLinkedStack(pStack);
	system("leaks a.out");
}
