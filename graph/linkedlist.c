#include "linkedgraph.h"
#include <stdlib.h>
#include <assert.h>

/*
 * createListNode() - Create List Node
 *
 * return	: node의 포인터
 * data		: node에 저장될 data
 */
ListNode *createListNode(int vertexID, int weight)
{
	ListNode *node;
	
	node = (ListNode *)malloc(sizeof(ListNode));
	if (!node)
		return (NULL);
	node->vertexID = vertexID;
	node->weight = weight;
	node->pLink = NULL;
	return (node);
}

/*
 * createLinkedList() - Create Linked List
 *
 * return	: LinkedList의 포인터
 */
LinkedList *createLinkedList(int vertexID)
{
	LinkedList *list;

	list = (LinkedList *)calloc(1, sizeof(LinkedList));
	if (!list)
		return (NULL);
	list->vertexID = vertexID;
	return (list);
}

/*
 * getLLElement() - position 위치의 node 반환
 *
 * return	: Node의 포인터
 * pList	: Linked List의 포인터
 * position	: 반환할 Node의 위치
 */
ListNode *getLLElement(LinkedList* pList, int position)
{
	ListNode *temp;
	int i;

	if (!pList || position < -1 || position >= pList->currentElementCount)
		return (NULL);
	if (position == -1)
		return (&pList->headerNode);
	temp = pList->headerNode.pLink;
	i = 0;
	while (i < position)
	{
		i++;
		temp = temp->pLink;
	}
	return (temp);
}

/*
 * addLLElement() - Linked List의 position 위치에 element 추가
 *
 * return	: 1 / 0
 * pList	: Linked List의 포인터
 * position : element를 추가할 위치
 * element	: 추가할 element
 */
int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode *prev;
	ListNode *node;
	int i;
	
	if (!pList || position < 0 || position > pList->currentElementCount)
		return (EXIT_FAILURE);
	i = 0;
	node = createListNode(element.vertexID, element.weight);
	prev = getLLElement(pList, position - 1);
	node->pLink = prev->pLink;
	prev->pLink = node;
	pList->currentElementCount++;
	return (EXIT_SUCCESS);
}

/*
 * removeLLElement() - Linked List의 position 위치의 node 삭제
 *
 * return	: 1 / 0
 * pList	: Linked List의 포인터
 * position	: 삭제할 node의 위치
 */
int removeLLElement(LinkedList* pList, int position)
{
	ListNode *removed;
	ListNode *prev;

	if (!pList || position < 0 || position >= pList->currentElementCount || !pList->headerNode.pLink)
		return (EXIT_FAILURE);
	prev = getLLElement(pList, position - 1);
	removed = prev->pLink;
	prev->pLink = removed->pLink;
	free(removed);
	pList->currentElementCount--;
	return (EXIT_SUCCESS);
}

/*
 * clearLinkedList() - Linked List의 노드 삭제
 *
 * return	: None
 * pList	: Linked List의 포인터
 */
void clearLinkedList(LinkedList* pList)
{
	ListNode *temp;
	ListNode *removed;

	if (!pList)
		return ;
	temp = pList->headerNode.pLink;
	while (pList->currentElementCount)
	{
		removed = temp;
		temp = temp->pLink;
		free(removed);
		pList->currentElementCount--;
	}
	assert(pList->currentElementCount == 0);
}

/*
 * deleteLinkedList() - Destroy Linked List
 *
 * return	: None
 * pList	: Linked List의 포인터
 */
void deleteLinkedList(LinkedList* pList)
{
	if (!pList)
		return ;
	clearLinkedList(pList);
	free(pList);
}
