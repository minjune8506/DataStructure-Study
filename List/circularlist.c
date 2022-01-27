#include "circularlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

CircularList *createCircularList()
{
	CircularList *list;
	
	list = (CircularList *)malloc(sizeof(CircularList));
	if (!list)
		return (NULL);
	list->currentElementCount = 0;
	list->pLink = NULL;
	return (list);
}

CircularListNode *createCListNode(int data)
{
	CircularListNode *node;

	node = (CircularListNode *)malloc(sizeof(CircularListNode));
	if (!node)
		return (NULL);
	node->data = data;
	node->pLink = NULL;
	return (node);
}

int addFirst(CircularList *pList, CircularListNode *element)
{
	CircularListNode *last_node;

	if (!pList || !element)
		return (EXIT_FAILURE);
	if (!pList->pLink) // 공백 리스트인 경우
	{
		pList->pLink = element;
		element->pLink = element;
	}
	else // 공백 리스트가 아닌 경우
	{
		last_node = getCLElement(pList, pList->currentElementCount - 1);
		last_node->pLink = element;
		element->pLink = pList->pLink;
		pList->pLink = element;
	}
	return (EXIT_SUCCESS);
}

int addCLElement(CircularList* pList, int position, CircularListNode element)
{
	CircularListNode *node;
	CircularListNode *temp;

	if (!pList || position < 0 || position > pList->currentElementCount)
		return (EXIT_FAILURE);
	node = createCListNode(element.data);
	if (position == 0 || !pList->pLink) // 첫 노드
		addFirst(pList, node);
	else
	{
		temp = getCLElement(pList, position - 1);
		node->pLink = temp->pLink;
		temp->pLink = node;
	}
	pList->currentElementCount++;
	return (EXIT_SUCCESS);
}

int removeFirst(CircularList *pList)
{
	CircularListNode *removed;
	CircularListNode *node;

	if (!pList)
		return (EXIT_FAILURE);
	if (pList->currentElementCount == 1)
	{
		removed = pList->pLink;
		pList->pLink = NULL;
	}
	else
	{
		// 마지막 노드가 가리키는 위치를 바꿔야 함
		// 첫노드 의 다음으로
		removed = pList->pLink;
		node = getCLElement(pList, pList->currentElementCount - 1);
		node->pLink = removed->pLink;
		pList->pLink = removed->pLink;
	}
	free(removed);
	return (EXIT_SUCCESS);
}

int removeCLElement(CircularList* pList, int position)
{
	CircularListNode *removed;
	CircularListNode *node;

	if (!pList || position < 0 || position >= pList->currentElementCount || !pList->pLink)
		return (EXIT_FAILURE);
	// 첫번쨰 노드 제거인가?
	// -> 리스트의 마지막 노드 인가? (노드가 1개인가?)
	// -> 1개 : 빈리스트
	// -> x : 연결 바꿔주면 될듯.
	if (position == 0)
		removeFirst(pList);
	else
	{
		node = getCLElement(pList, position - 1);
		removed = node->pLink;
		node->pLink = removed->pLink;
		free(removed);
	}
	pList->currentElementCount--;
	return (EXIT_SUCCESS);
}

CircularListNode* getCLElement(CircularList* pList, int position)
{
	CircularListNode *node;
	int i;

	if (!pList || position < 0 || position >= pList->currentElementCount)
		return (NULL);
	i = 0;
	node = pList->pLink;
	while (i < position)
	{
		node = node->pLink;
		i++;
	}
	return (node);
}

void clearCircularList(CircularList* pList)
{
	int i = 0;
	CircularListNode *temp;
	CircularListNode *removed;

	if (!pList)
		return ;
	temp = pList->pLink;
	while (i < pList->currentElementCount)
	{
		removed = temp;
		temp = temp->pLink;
		free(removed);
		pList->currentElementCount--;
	}
	assert(pList->currentElementCount == 0);	
}

void deleteCircularList(CircularList* pList)
{
	if (!pList)
		return ;
	clearCircularList(pList);
	free(pList);
}

int getCircularListLength(CircularList* pList)
{
	if (!pList)
		return (EXIT_FAILURE);
	return (pList->currentElementCount);
}

void displayCircularList(CircularList* pList)
{
	int i;
	CircularListNode *node;

	if (!pList)
		return ;
	i = 0;
	node = pList->pLink;
	if (!node)
	{
		printf("NULL\n");
		return ;
	}
	while (i < pList->currentElementCount + 1)
	{
		printf("%d -> ", node->data);
		node = node->pLink;
		i++;
	}
	printf("\n");
}

int main(void)
{
	CircularList *list;
	CircularListNode node;

	list = createCircularList();
	node.data = 10;
	addCLElement(list, 0, node);
	displayCircularList(list);
	// 10

	node.data = 20;
	addCLElement(list, 0, node);
	displayCircularList(list);
	// 20 -> 10

	node.data = 30;
	addCLElement(list, 2, node);
	displayCircularList(list);
	// 20 -> 10 -> 30

	printf("length : %d\n", getCircularListLength(list));
	// removeCLElement(list, 1);
	// displayCircularList(list);
	// // 20 -> 30

	// removeCLElement(list, 0);
	// displayCircularList(list);
	// // 30

	// removeCLElement(list, 0);
	// displayCircularList(list);
	// // NULL

	clearCircularList(list);
	deleteCircularList(list);
	// system("leaks a.out");
}
