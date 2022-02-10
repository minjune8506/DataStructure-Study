#include "arrayqueue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * createArrayQueue() : Array Queue생성
 * 
 * return : Array Queue의 포인터
 * maxElementCount : Array Queue의 최대 원소 갯수
 */
ArrayQueue* createArrayQueue(int maxElementCount)
{
	ArrayQueue *que = NULL;

	if (maxElementCount < 0)
		return (0);
	que = (ArrayQueue *)malloc(sizeof(ArrayQueue));
	if (!que)
		return (NULL);
	que->maxElementCount = maxElementCount;
	que->currentElementCount = 0;
	que->front = 0;
	que->rear = 0;
	que->pElement = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode) * maxElementCount);
	if (!que->pElement)
		return (NULL);
	memset(que->pElement, 0, sizeof(ArrayQueueNode) * maxElementCount);
	return (que);
}

/**
 * enqueueAQ() : Array Queue에 element추가
 * 
 * return : 0 (EXIT_SUCCESS) / 1 (EXIT_FAILURE)
 * pQueue : Array Queue의 포인터
 * element : Array Queue에 추가할 element
 */
int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	if (!pQueue || isArrayQueueFull(pQueue))
		return (EXIT_FAILURE);
	pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
	pQueue->pElement[pQueue->rear] = element;
	pQueue->currentElementCount++;
	return (EXIT_SUCCESS);
}

/**
 * dequeueAQ : Array Queue의 front + 1 위치의 element 삭제
 * 
 * return : Array Qeueue Node의 포인터
 * pQueue : Array Queue의 포인터
 */
ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode *node;

	if (!pQueue || isArrayQueueEmpty(pQueue))
		return (NULL);
	pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
	node = &pQueue->pElement[pQueue->front];
	pQueue->currentElementCount--;
	return (node);
}

/**
 * peekAQ() : Array Queue의 front + 1 위치의 element 반환
 * 
 * return : Array Queue의 맨 앞 Node의 포인터
 * pQueue : Array Queue의 포인터
 */
ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode *node;
	int front;

	if (!pQueue || isArrayQueueEmpty(pQueue))
		return (NULL);
	front = (pQueue->front + 1) % pQueue->maxElementCount;
	node = &pQueue->pElement[front];
	return (node);
}

/**
 * deleteArrayQueue : Array Queue 메모리 해제
 * 
 * return : None
 * pQueue : Array Queue의 포인터
 */
void deleteArrayQueue(ArrayQueue* pQueue)
{
	if (!pQueue)
		return ;
	if (pQueue->pElement)
		free(pQueue->pElement);
	pQueue->pElement = NULL;
	free(pQueue);
}

/**
 * isArrayQueueFull() : Array Queue가 가득 찼는지 검사
 * 
 * return : True / False
 * pQueue : Array Queue의 포인터
 */
int isArrayQueueFull(ArrayQueue* pQueue)
{
	if (!pQueue)
		return (-1);
	return ((pQueue->rear + 1) % pQueue->maxElementCount == pQueue->front);
}

/**
 * isArrayQueueEmpty() : Array Queue가 비었는지 검사
 * 
 * return : True / False
 * pQueue : Array Queue의 포인터
 */
int isArrayQueueEmpty(ArrayQueue* pQueue)
{
	if (!pQueue)
		return (-1);
	return (pQueue->front == pQueue->rear);
}

/**
 * display() : Array Queue 출력
 * 
 * pQueue : Array Queue의 포인터
 */
void display(ArrayQueue* pQueue)
{
	printf("maxElementCount : %d\n", pQueue->maxElementCount);
	printf("currentElementCount : %d\n", pQueue->currentElementCount);
	printf("front : %d, rear : %d\n", pQueue->front, pQueue->rear);
	printf(" -------------------\n|");
	for (int i = 0 ; i < pQueue->maxElementCount ; i++)
	{
		if (pQueue->pElement[i].data == '\0')
			printf("   |");
		else
			printf(" %c |", pQueue->pElement[i].data);
	}	
	printf("\n");
	printf(" -------------------\n\n");
}

int main(void)
{
	ArrayQueue *que;
	ArrayQueueNode node;
	ArrayQueueNode *temp;

	que = createArrayQueue(5);
	node.data = 'a';

	for (int i = 0 ; i < que->maxElementCount - 1 ; i++)
	{
		enqueueAQ(que,  node);
		node.data++;
		display(que);
	}
	printf("isArrayQueueFull : %s\n\n", isArrayQueueFull(que) ? "True" : "False");
	for (int i = 0 ; i < que->maxElementCount - 1 ; i++)
	{
		printf("peek : %c\n", peekAQ(que)->data);
		temp = dequeueAQ(que);
		printf("dequeue : %c\n", temp->data);
		temp->data = 0;
		display(que);
	}
	printf("isArrayQueueEmpty : %s\n\n", isArrayQueueEmpty(que) ? "True" : "False");
	for (int i = 0 ; i < que->maxElementCount - 1 ; i++)
	{
		enqueueAQ(que,  node);
		node.data++;
		display(que);
	}
	deleteArrayQueue(que);
	// system("leaks a.out");
}
