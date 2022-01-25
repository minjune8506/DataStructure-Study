/*
 * Linked List
 * Author	: minjkim2, dkim2
 * Language	:  C
 */
#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*
 * error() - Print error mesage and Exit
 *
 * return	: None
 * message	: Error Message
 */
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(EXIT_FAILURE);
}

/*
 * createListNode() - Create List Node
 *
 * return	: node의 포인터
 * data		: node에 저장될 data
 */
ListNode *createListNode(int data)
{
	ListNode *node;
	
	node = (ListNode *)malloc(sizeof(ListNode));
	if (!node)
		error("Memory Allocation Error");
	node->data = data;
	node->pLink = NULL;
	return (node);
}

/*
 * createLinkedList() - Create Linked List
 *
 * return	: LinkedList의 포인터
 */
LinkedList *createLinkedList()
{
	LinkedList *list;

	list = (LinkedList *)malloc(sizeof(LinkedList));
	if (!list)
		error("Memory Allocation Error");
	list->currentElementCount = 0;
	list->headerNode = NULL;
	return (list);
}

/*
 * getNodeAt() - position 위치의 node 반환
 *
 * return	: Node의 포인터
 * pList	: Linked List의 포인터
 * position	: 반환할 위치
 */
ListNode *getNodeAt(LinkedList *pList, int position)
{
	ListNode *temp;
	int i;
	
	if (!pList || position < 0 || position >= pList->currentElementCount)
		return NULL;
	temp = pList->headerNode;
	for (i = 0 ; i < position ; i++)
		temp = temp->pLink;
	return temp;
}

/*
 * addFrst() - Linked List의 첫 위치에 element 추가
 *
 * return	: 1 / 0
 * pList	: Linked List의 포인터
 * element	: 추가할 element
 */
int addFirst(LinkedList *pList, ListNode element)
{
	ListNode *node;
	ListNode *temp;

	if (!pList)
		return (EXIT_FAILURE);
	node = createListNode(element.data);
	temp = pList->headerNode;
	if (!temp)
		pList->headerNode = node;
	else
	{
		node->pLink = temp;
		pList->headerNode = node;
	}
	pList->currentElementCount++;
	return (EXIT_SUCCESS);
}

/*
 * addLast() - Linked List의 마지막 위치에 element 추가
 *
 * return	: 1 / 0
 * pList	: Linked List의 포인터
 * element	: 추가할 element
 */
int addLast(LinkedList *pList, ListNode element)
{
	ListNode *node;
	ListNode *temp;

	if (!pList)
		return (EXIT_FAILURE);
	node = createListNode(element.data);
	temp = pList->headerNode;
	if (!temp)
		pList->headerNode = node;
	else
	{
		while (temp->pLink)
			temp = temp->pLink;
		temp->pLink = node;
	}
	pList->currentElementCount++;
	return (EXIT_SUCCESS);
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
	ListNode *temp;
	ListNode *node;
	int i;
	
	if (!pList || position < 0)
		return (EXIT_FAILURE);
	if (position > getLinkedListLength(pList))
		position = getLinkedListLength(pList);
	i = 0;
	if (!pList->headerNode || position == 0)
		addFirst(pList, element);
	else
	{
		node = createListNode(element.data);
		temp = pList->headerNode;
		if (position == pList->currentElementCount)
			addLast(pList, element);
		else
		{
			temp = getNodeAt(pList, position - 1);
			node->pLink = temp->pLink;
			temp->pLink = node;
			pList->currentElementCount++;
		}
	}
	return (EXIT_SUCCESS);
}

/*
 * removeFirst() - Linked List의 첫 위치의 node 삭제
 *
 * return	: 1 / 0
 * pList	: Linked List의 포인터
 */
int removeFirst(LinkedList *pList)
{
	ListNode *removed;

	if (!pList || !pList->headerNode)
		return (EXIT_FAILURE);
	removed = pList->headerNode;
	pList->headerNode = pList->headerNode->pLink;
	free(removed);
	pList->currentElementCount--;
	return (EXIT_SUCCESS);
}

/*
 * removeLast() - Linked List의 마지막 위치의 node 삭제
 *
 * return	: 1 / 0
 * pList	: Linked List의 포인터
 */
int removeLast(LinkedList *pList)
{
	ListNode *curr;
	ListNode *prev;

	if (!pList || !pList->headerNode)
		return (EXIT_FAILURE);
	curr = pList->headerNode;
	prev = curr;
	while (curr->pLink)
	{
		prev = curr;
		curr = curr->pLink;
	}
	prev->pLink = NULL;
	free(curr);
	pList->currentElementCount--;
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
	ListNode *curr;
	ListNode *prev;
	int i;

	if (!pList || position < 0 || position >= getLinkedListLength(pList) || !pList->headerNode)
		return (EXIT_FAILURE);
	curr = pList->headerNode;
	if (position == 0)
		removeFirst(pList);
	else
	{
		i = 0;
		prev = curr;
		while (i < position)
		{
			prev = curr;
			curr = curr->pLink;
		}
		prev->pLink = curr->pLink;
		free(curr);
		pList->currentElementCount--;
	}
	return (EXIT_SUCCESS);
}

/*
 * getLinkedListLength() - Linked List의 노드의 갯수 반환
 *
 * return	: 노드의 갯수
 * pList	: Linked List의 포인터
 */
int getLinkedListLength(LinkedList* pList)
{
	ListNode *temp;
	int length;

	length = 0;
	temp = pList->headerNode;
	while (temp)
	{
		length++;
		temp = temp->pLink;
	}
	return (length);
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
	temp = pList->headerNode;
	while (temp)
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


/*
 * getLLElement() - position 위치의 node 반환
 *
 * return	: Node의 포인터
 * pList	: Linked List의 포인터
 * position	: 반환할 Node의 위치
 */
ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode *temp;
	int i;

	if (!pList || position < 0)
		return (NULL);
	temp = pList->headerNode;
	if (!temp)
		return (NULL);
	i = 0;
	while (i < position)
	{
		i++;
		temp = temp->pLink;
	}
	return (temp);
}

/*
 * display() - Linked List 내용 출력
 *
 * return	: None
 * pList	: Linked List의 포인터
 */
void display(LinkedList *pList)
{
	ListNode *temp;

	temp = pList->headerNode;
	printf("currentElementCount : %d\n", pList->currentElementCount);
	if (!temp)
	{
		printf("Empty List\n");
		return ;
	}
	while (temp)
	{
		printf("%d -> ", temp->data);
		temp = temp->pLink;
	}
	printf("\n");
}

int main(void)
{
	LinkedList *list;
	ListNode *get_node;
	ListNode node;
	
	list = createLinkedList();
	node.data = 10;
	addLLElement(list, 0, node);
	display(list);
	node.data = 20;
	addLLElement(list, 1, node);
	display(list);
	node.data = 30;
	addLLElement(list, 0, node);
	display(list);
	node.data = 40;
	addLLElement(list, 1, node);
	// 30 -> 40 -> 10 -> 20
	display(list);


	get_node = getLLElement(list, 2);
	printf("get_node : %d\n", get_node->data); // 10

	removeFirst(list);
	// 40 -> 10 -> 20
	display(list);

	removeLast(list);
	// 40 -> 10
	display(list);

	removeLLElement(list, 0);
	// 10
	display(list);
	removeLLElement(list, 1);
	// 10
	display(list);

	printf("---------\n");
	removeLLElement(list, 0);
	display(list);
	
	clearLinkedList(list);
	printf("---------\n");
	display(list);
}
