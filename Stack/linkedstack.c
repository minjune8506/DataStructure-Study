/*
 * Linked Stack
 * Author: minjkim2
 * Language:  C
 */
#include "linkedstack.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/**
 * createLinkedStack() : Linked Stack 생성
 * 
 * return : Linked Stack의 포인터
 */
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

/**
 * createStackNode() : Stack Node 생성
 * 
 * return : Stack Node의 포인터 
 * data : Node의 데이터
 */
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

/**
 * pushLS() : Linked Stack에 Node 추가
 * 
 * return : 1 (EXIT_FAILURE) / 0 (EXIT_SUCCESS)
 * pStack : Linked Stack의 포인터
 * element : Linked Stack에 추가할 Node element
 */
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

/**
 * popLS() : Linked Stack의 Node 제거
 * 
 * return : Stack의 Top Node의 포인터
 * pStack : Linked Stack의  포인터
 */
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

/**
 * peekLS() : Linked Stack의 Node 반환
 * 
 * return : Stack의 Top Node의 포인터
 * pStack : Linked Stack의  포인터
 */
StackNode *peekLS(LinkedStack *pStack)
{
	StackNode *node;

	if (!pStack || !pStack->pTopElement)
		return (NULL);
	node = pStack->pTopElement;
	return (node);
}

/**
 * deleteLinkedStack() : Linked Stack 제거
 * 
 * return : None
 * pStack : Linked Stack의  포인터
 */
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

/**
 * isLinkedStackEmpty() : Linked Stack이 비어있는지 확인
 * 
 * return : True / False
 * pStack : Linked Stack의  포인터
 */
int isLinkedStackEmpty(LinkedStack *pStack)
{
	if (!pStack)
		return (-1);
	return (pStack->currentElementCount == 0);
}

/**
 * displayLinkedStack() : Linked Stack 출력
 * 
 * return : None
 * pStack : Linked Stack의  포인터
 */
void displayLinkedStack(LinkedStack *pStack)
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
