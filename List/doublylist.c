#include "doublylist.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

DoublyList *createDoublyList()
{
	DoublyList *list;

	list = (DoublyList *)calloc(1, sizeof(DoublyList));
	if (!list)
		return (NULL);
	list->headerNode.pLLink = &list->headerNode;
	list->headerNode.pRLink = &list->headerNode;
	return (list);
}

DoublyListNode *createNode(element data)
{
	DoublyListNode *node;

	node = calloc(1, sizeof(DoublyListNode));
	if (!node)
		return (NULL);
	node->data = data;
	return (node);
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	DoublyListNode *node;
	DoublyListNode *prev;

	if (!pList || position < 0 ||position > pList->currentElementCount)
		return (EXIT_FAILURE);
	node = createNode(element.data);
	prev = getDLElement(pList, position - 1);
	node->pLLink = prev;
	node->pRLink = prev->pRLink;
	prev->pRLink->pLLink = node;
	prev->pRLink = node;
	pList->currentElementCount++;
	return (EXIT_SUCCESS);
}

int removeDLElement(DoublyList* pList, int position)
{
	DoublyListNode *target;
	DoublyListNode *prev;

	if (!pList || position < 0 || position >= pList->currentElementCount || pList->headerNode.pRLink == &pList->headerNode)
		return (EXIT_FAILURE);;
	target = getDLElement(pList, position);
	prev = target->pLLink;
	prev->pRLink = target->pRLink;
	target->pRLink->pLLink = target->pLLink;
	free(target);
	pList->currentElementCount--;
	return (EXIT_SUCCESS);
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	DoublyListNode *node;
	int i;

	if (!pList || position < -1 || position >= pList->currentElementCount)
		return (NULL);
	if (position == -1)
		return (&pList->headerNode);
	if (position < pList->currentElementCount / 2)
	{
		i = 0;
		node = pList->headerNode.pRLink;
		while (i < position)
		{
			node = node->pRLink;
			i++;
		}
	}
	else
	{
		i = pList->currentElementCount - 1;
		node = pList->headerNode.pLLink;
		while (i > position)
		{
			node = node->pLLink;
			i--;
		}
	}
	return (node);
}

int getDoublyListLength(DoublyList* pList)
{
	if (!pList)
		return (-1);
	return (pList->currentElementCount);
}

void clearDoublyList(DoublyList* pList)
{
	DoublyListNode *temp;
	DoublyListNode *removed;

	if (!pList)
		return ;
	temp = pList->headerNode.pRLink;
	while (0 < pList->currentElementCount)
	{
		removed = temp;
		temp = temp->pRLink;
		free(removed);
		pList->currentElementCount--;
	}
	assert(pList->currentElementCount == 0);
}

void deleteDoublyList(DoublyList* pList)
{
	if (!pList)
		return ;
	clearDoublyList(pList);
	free(pList);
}

void displayDoublyList(DoublyList* pList)
{
	DoublyListNode *temp;
	
	if (!pList)
		return ;
	temp = pList->headerNode.pRLink;
	printf("currElementCount : %d\n", getDoublyListLength(pList));
	if (temp == &pList->headerNode)
	{
		printf("Empty\n");
		return ;
	}
	while (temp != &pList->headerNode)
	{
		printf("%d -> ", temp->data);
		temp = temp->pRLink;
	}
	printf("\n");
}

// int	main(void)
// {
// 	DoublyList *list;
// 	DoublyListNode node;

// 	list = createDoublyList();

// 	node.data = 10;
// 	addDLElement(list, 0, node);
// 	displayDoublyList(list);
// 	// 10

// 	node.data = 20;
// 	addDLElement(list, 0, node);
// 	displayDoublyList(list);
// 	// 20 -> 10

// 	node.data = 30;
// 	addDLElement(list, 2, node);
// 	displayDoublyList(list);
// 	// 20 -> 10 -> 30

// 	// removeDLElement(list, 0);
// 	// displayDoublyList(list);
// 	// // 10 -> 30

// 	// removeDLElement(list, 1);
// 	// displayDoublyList(list);
// 	// // 10

// 	// removeDLElement(list, 0);
// 	// displayDoublyList(list);
// 	// // NULL
// 	clearDoublyList(list);
// 	deleteDoublyList(list);
// 	// system("leaks a.out");
// }
