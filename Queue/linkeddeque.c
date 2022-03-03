#include "linkeddeque.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

/**
 * createLinkedDeque() : Linked Deque 생성
 * 
 * return : Linked Deque의 포인터
 */
LinkedDeque* createLinkedDeque()
{
	LinkedDeque *pDeque;

	pDeque = (LinkedDeque *)malloc(sizeof(LinkedDeque));
	if (!pDeque)
		return (NULL);
	memset(pDeque, 0 , sizeof(LinkedDeque));
	return (pDeque);
}

/**
 * createNode() : Deque Node 생성
 * 
 * return : Deque Node의 포인터
 * element : 추가할 DequeNode element 
 */
DequeNode *createNode(DequeNode element)
{
	DequeNode *node;

	node = (DequeNode *)malloc(sizeof(DequeNode));
	if (!node)
		return (NULL);
	node->data = element.data;
	node->pLLink = NULL;
	node->pRLink = NULL;
	return (node);
}

/**
 * insertFrontLD() : Linked Deque의 front에 node 추가
 * 
 * return : 1 (EXIT_FAILURE) / 0 (EXIT_SUCCESS)
 * pDeque : Linked Deque의 포인터
 * element : 추가할 element
 */
int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *node;

	if (!pDeque)
		return (EXIT_FAILURE);
	node = createNode(element);
	if (!pDeque->pFrontNode)
	{
		pDeque->pFrontNode = node;
		pDeque->pRearNode = node;
	}
	else
	{
		pDeque->pFrontNode->pLLink = node;
		node->pRLink = pDeque->pFrontNode;
		pDeque->pFrontNode = node;
	}
	pDeque->currentElementCount++;
	return(EXIT_SUCCESS);
}

/**
 * insertRearLD() : Linked Deque의 rear에 node 추가
 * 
 * return : 1 (EXIT_FAILURE) / 0 (EXIT_SUCCESS)
 * pDeque : Linked Deque의 포인터
 * element : 추가할 element
 */
int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
    DequeNode *node;
	
    if (!pDeque)
        return (EXIT_FAILURE);
    node = createNode(element);
    if (!pDeque->pRearNode)
	{
		pDeque->pFrontNode = node;
		pDeque->pRearNode = node;
	}
	else
	{
		pDeque->pRearNode->pRLink = node;
		node->pLLink = pDeque->pRearNode;
		pDeque->pRearNode = node;
	}
	pDeque->currentElementCount++;
	return(EXIT_SUCCESS);
}

/**
 * deleteFrontLD() : Linked Deque의 front의 node 제거
 * 
 * return : front node의 포인터
 * pDeque : Linked Deque의 포인터
 */
DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
	DequeNode *node;

	if (!pDeque || isLinkedDequeEmpty(pDeque))
		return (NULL);
	node = pDeque->pFrontNode;
	if (pDeque->currentElementCount == 1)
	{
		pDeque->pFrontNode = NULL;
		pDeque->pRearNode = NULL;
	}
	else
	{
		pDeque->pFrontNode = node->pRLink;
		pDeque->pFrontNode->pLLink = NULL;
	}
	pDeque->currentElementCount--;
	return (node);
}

/**
 * deleteRearLD() : Linked Deque의 rear의 node 제거
 * 
 * return : rear node의 포인터
 * pDeque : Linked Deque의 포인터
 */
DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode *node;

    if (!pDeque || isLinkedDequeEmpty(pDeque))
        return (NULL);
	node = pDeque->pRearNode;
	if (pDeque->currentElementCount == 1)
	{
		pDeque->pFrontNode = NULL;
		pDeque->pRearNode = NULL;
	}
	else
	{
		pDeque->pRearNode = node->pLLink;
		pDeque->pRearNode->pRLink = NULL;
	}
	pDeque->currentElementCount--;
	return (node);
}

/**
 * peekFrontLD() : Linked Deque의 front의 node 반환
 * 
 * return : front node의 포인터
 * pDeque : Linked Deque의 포인터
 */
DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
	DequeNode *node;
	if (!pDeque || isLinkedDequeEmpty(pDeque))
		return (NULL);
	node = pDeque->pFrontNode;
	return (node);
}

/**
 * peekRearLD() : Linked Deque의 rear의 node 반환
 * 
 * return : rear node의 포인터
 * pDeque : Linked Deque의 포인터
 */
DequeNode* peekRearLD(LinkedDeque* pDeque)
{
	DequeNode *node;
	
	if (!pDeque || isLinkedDequeEmpty(pDeque))
		return (NULL);
	node = pDeque->pRearNode;
	return (node);
}

/**
 * deleteLinkedDeque() : Linked Deque 메모리 해제
 * 
 * return : None
 * pDeque : Linked Deque의 포인터
 */
void deleteLinkedDeque(LinkedDeque* pDeque)
{
	DequeNode *node;
	DequeNode *temp;

	node = pDeque->pFrontNode;
	while (node)
	{
		temp = node;
		node = node->pRLink;
		free(temp);
		pDeque->currentElementCount--;
	}
	assert(pDeque->currentElementCount == 0);
	free(pDeque);
}

/**
 * isLinkedDequeEmpty() : Linked Deque가 비어있는지 확인
 * 
 * return : True / False
 * pDeque : Linked Deque의 포인터
 */
int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
    return (pDeque->currentElementCount == 0);
}

/**
 * display() : Linked Deque 출력
 * 
 * return : None
 * pDeque : Linked Deque의 포인터
 */
void displayLinkedDeque(LinkedDeque *pDeque)
{
	DequeNode *node;

	printf("currentElementCount : %d\n", pDeque->currentElementCount);
	node = pDeque->pFrontNode;
	if (!node)
	{
		printf("Empty Deque\n\n");
		return ;
	}
	while (node)
	{
		if (node->pRLink)
			printf("%c -> ", node->data);
		else
			printf("%c", node->data);
		node = node->pRLink;
	}
	printf("\n\n");
}
