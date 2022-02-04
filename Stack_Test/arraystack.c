#include "arraystack.h"
#include <stdlib.h>
#include <stdio.h>

// typedef struct ArrayStackNodeType {
// 	char data;
// } ArrayStackNode;

// typedef struct ArrayStackType {
// 	int maxElementCount;		// 최대 원소의 개수
// 	int currentElementCount;	// 현재 원소의 개수
// 	ArrayStackNode *pElement;	// 노드 저장을 위한 1차원 array
// } ArrayStack;

ArrayStack* createArrayStack(int maxElementCount)
{
	ArrayStack *p;

    p = malloc(sizeof(ArrayStack));
    if (p == NULL)
        return (NULL);
    p->maxElementCount = maxElementCount;
    p->currentElementCount = 0;
    p->pElement = (ArrayStackNode *)malloc(sizeof(ArrayStackNode) * maxElementCount);
	if (!p->pElement)
		return (NULL);
    return (p);
}

int pushAS(ArrayStack* pStack, ArrayStackNode element)
{
	if (!pStack || isArrayStackFull(pStack))
		return (EXIT_FAILURE);
	pStack->pElement[pStack->currentElementCount] = element;
	pStack->currentElementCount += 1;
	return (EXIT_SUCCESS);
}

ArrayStackNode* popAS(ArrayStack* pStack)
{
    int ret_idx;
    
	if (!pStack || isArrayStackEmpty(pStack))
        return (NULL);
    ret_idx = pStack->currentElementCount - 1;
    pStack->currentElementCount -= 1;
    return (&pStack->pElement[ret_idx]);
}

ArrayStackNode* peekAS(ArrayStack* pStack)
{
	ArrayStackNode *node;

	if (!pStack || isArrayStackEmpty(pStack))
		return (NULL);
	node = &pStack->pElement[pStack->currentElementCount - 1];
    return (node);
}

void deleteArrayStack(ArrayStack* pStack)
{
	free(pStack->pElement);
	free(pStack);
}

int isArrayStackFull(ArrayStack* pStack)
{
	if (!pStack)
		return (-1);
	return (pStack->currentElementCount == pStack->maxElementCount);
}

int isArrayStackEmpty(ArrayStack* pStack)
{
	if (!pStack)
		return (-1);
    if (pStack->currentElementCount == 0)
        return (TRUE);
    return (FALSE);
}

void display(ArrayStack *pStack)
{
	if (!pStack || !pStack->pElement)
		return ;
	printf("maxElementCount : %d\n", pStack->maxElementCount);
	printf("currentElementCount : %d\n", pStack->currentElementCount);
	printf("Stack : ");
	for (int i = 0 ; i < pStack->currentElementCount ; i++)
		printf("%c ", pStack->pElement[i].data);
	printf("\n");
}

int main(void)
{
	ArrayStack *pStack;
	ArrayStackNode element;
	ArrayStackNode *peek;
	ArrayStackNode *pop;

	pStack = createArrayStack(10);
	
	element.data = 'a';
	for (int i = 0 ; i < pStack->maxElementCount ; i++)
	{
		pushAS(pStack, element);
		display(pStack);
		element.data++;
	}
	printf("isArrayStackFull : %s\n", isArrayStackFull(pStack) ? "True" : "False");
	for (int i = 0 ; i < pStack->maxElementCount ; i++)
	{
		peek = peekAS(pStack);
		pop = popAS(pStack);
		printf("peek : %c, pop : %c\n", peek->data, pop->data);
		display(pStack);
	}
	printf("isArrayStackEmpty : %s\n", isArrayStackEmpty(pStack) ? "True" : "False");
	deleteArrayStack(pStack);
	system("leaks a.out");

}
