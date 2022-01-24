#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

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

LinkedList *createLinkedList()
{
	LinkedList *list;

	list = (LinkedList *)malloc(sizeof(LinkedList));
	list->currentElementCount = 0;
	list->headerNode = NULL;
	return (list);
}

ListNode *get_node_at(LinkedList *pList, int position)
{
	int i;
	ListNode *temp;
	
	if (!pList || position < 0 || position >= pList->currentElementCount)
		return NULL;
	temp = pList->headerNode;
	for (i = 0 ; i < position ; i++)
		temp = temp->pLink;
	return temp;
}

int add_first(LinkedList *pList, ListNode element)
{
	ListNode *node;
	ListNode *temp;

	if (!pList)
		return (1);
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
	return (0);
}

int add_last(LinkedList *pList, ListNode element)
{
	ListNode *node;
	ListNode *temp;

	if (!pList)
		return (1);
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
	return (0);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode *temp;
	ListNode *node;
	int i;
	
	if (!pList || position < 0)
		return (1);
	if (position > getLinkedListLength(pList))
		position = getLinkedListLength(pList);
	i = 0;
	if (!pList->headerNode)
		add_first(pList, element);
	else
	{
		node = createListNode(element.data);
		temp = pList->headerNode;
		if (position == pList->currentElementCount)
			add_last(pList, element);
		else if (position == 0)
			add_first(pList, element);
		else
		{
			temp = get_node_at(pList, position - 1);
			node->pLink = temp->pLink;
			temp->pLink = node;
			pList->currentElementCount++;
		}
	}
	return (0);
}

int remove_first(LinkedList *pList)
{
	ListNode *removed;

	if (!pList)
		return (1);
	if (!pList->headerNode && !pList->currentElementCount)
		return (1);
	removed = pList->headerNode;
	pList->headerNode = pList->headerNode->pLink;
	free(removed);
	pList->currentElementCount--;
	return (0);
}

int remove_last(LinkedList *pList)
{
	ListNode *curr;
	ListNode *prev;

	if (!pList)
		return (1);
	if (!pList->headerNode && !pList->currentElementCount)
		return (1);
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
	return (0);
}

int removeLLElement(LinkedList* pList, int position)
{
	ListNode *curr;
	ListNode *prev;
	int i;

	if (!pList || position < 0)
		return (1);
	if (position >= getLinkedListLength(pList))
		return (1);
	curr = pList->headerNode;
	if (!curr) // 리스트에 노드가 없을 경우
		return (0);
	if (position == 0)
		remove_first(pList);
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
	return (0);
}

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

// LinkedList를 destroy
void deleteLinkedList(LinkedList* pList)
{
	if (!pList)
		return ;
	clearLinkedList(pList);
	free(pList);
}

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
	while (i <= position)
	{
		i++;
		temp = temp->pLink;
	}
	return (temp);
}

void display(LinkedList *list)
{
	ListNode *temp;

	temp = list->headerNode;
	if (!temp)
		return ;
	printf("currentElementCount : %d\n", list->currentElementCount);
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

	remove_first(list);
	// 40 -> 10 -> 20
	display(list);

	remove_last(list);
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
