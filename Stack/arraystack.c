/*
 * Array Stack
 * Author: minjkim2
 * Language:  C
 */
#include "arraystack.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * createArrayStack() - Create Array Stack
 * 
 * return : Pointer of Array Stack
 * maxElementCount : Array Stack의 최대 원소 개수
*/
ArrayStack *createArrayStack(int maxElementCount)
{
	ArrayStack *pStack;

	if (maxElementCount <= 0)
		return (NULL);
	pStack =(ArrayStack *)malloc(sizeof(ArrayStack));
	if (!pStack)
		return (NULL);
	pStack->maxElementCount = maxElementCount;
	pStack->currentElementCount = 0;
	pStack->pElement = (ArrayStackNode *)malloc(sizeof(ArrayStackNode) * maxElementCount);
	if (!pStack->pElement)
		return (NULL);
	for (int i = 0 ; i < maxElementCount ; i++)
		pStack->pElement[i].data = 0;
	return (pStack);
}

/*
 * pushAS() - Add Element to Array Stack
 *
 * return : 1 / 0
 * pStack : Array Stack의 포인터
 * element : Array Stack에 추가 할 element
*/
int pushAS(ArrayStack *pStack, ArrayStackNode element)
{
	if (!pStack || isArrayStackFull(pStack))
		return (EXIT_FAILURE);
	pStack->pElement[pStack->currentElementCount] = element;
	pStack->currentElementCount++;
	return (EXIT_SUCCESS);
}

/*
 * popAS() - ArrayStack의 제일 위에 있는 node 꺼내기
 *
 * return : Array Stack Node의 포인터
 * pStack : Array Stack의 포인터
*/
ArrayStackNode *popAS(ArrayStack *pStack)
{
	ArrayStackNode *node;

	if (!pStack || isArrayStackEmpty(pStack))
		return (NULL);
	node = &pStack->pElement[pStack->currentElementCount - 1];
	pStack->currentElementCount--;
	return (node);
}

/*
 * peekAS() - ArrayStack의 제일 위에있는 node 보기
 *
 * return : Array Stack Node의 포인터
 * pStack : Array Stack의 포인터
*/
ArrayStackNode *peekAS(ArrayStack *pStack)
{
	ArrayStackNode *node;

	if (!pStack || isArrayStackEmpty(pStack))
		return (NULL);
	node = &pStack->pElement[pStack->currentElementCount - 1];
	return (node);
}

/*
 * deleteArrayStack() - ArrayStack 제거
 *
 * return : None
 * pStack : Array Stack의 포인터
*/
void deleteArrayStack(ArrayStack *pStack)
{
	free(pStack->pElement);
	free(pStack);
}

/*
 * isArrayStackFull() - ArrayStack이 가득 찼는지 검사
 *
 * return : TRUE / FALSE
 * pStack : Array Stack의 포인터
*/
int isArrayStackFull(ArrayStack *pStack)
{
	if (!pStack)
		return (-1);
	return (pStack->currentElementCount == pStack->maxElementCount);
}

/*
 * isArrayStackEmpty() - ArrayStack이 비었는지 검사
 *
 * return : TRUE / FALSE
 * pStack : ArrayStack의 포인터
*/
int isArrayStackEmpty(ArrayStack *pStack)
{
	if (!pStack)
		return (-1);
	return (pStack->currentElementCount == 0);
}

/*
 * display - Print Array Stack
 *
 * return : None
 * pStack : Array Stack의 포인터
*/
void display(ArrayStack *pStack)
{
	if (!pStack || !pStack->pElement)
		return ;
	printf("currentElementCount : %d\n", pStack->currentElementCount);
	printf("maxElementCount : %d\n", pStack->maxElementCount);
	printf("Stack : ");
	for (int i = 0 ; i < pStack->currentElementCount ; i++)
		printf("%c ",pStack->pElement[i].data);
	printf("\n");
}

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
		display(pStack);
		node.data++;
	}
	printf("is_full : %s\n", isArrayStackFull(pStack) ? "true" : "false");
	for (int i = 0 ; i < pStack->maxElementCount ; i++)
	{
		peek = peekAS(pStack);
		pop = popAS(pStack);
		printf("peek : %c\n", peek->data);
		printf("pop : %c\n", pop->data);
		display(pStack);
	}
	printf("is_empty : %s\n", isArrayStackEmpty(pStack) ? "true" : "false");
	deleteArrayStack(pStack);
	// system("leaks a.out");
}
