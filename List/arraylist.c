#include "arraylist.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

ArrayList *createArrayList(int maxElementCount)
{
	ArrayList *ary;

	if (maxElementCount <= 0)
		return (NULL);
	ary = (ArrayList *)malloc(sizeof(ArrayList));
    if (!ary)
        return (NULL);
	ary->maxElementCount = maxElementCount;
	ary->currentElementCount = 0;
	ary->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
    if (!ary->pElement)
        return (NULL);
	for (int i = 0; i < ary->maxElementCount ; i++)
		ary->pElement[i].data = 0;
	return (ary);
}

void clearArrayList(ArrayList* pList)
{
    if (!pList)
        return ;
	for (int i = 0; i < pList->currentElementCount ; i++)
	{
		pList->pElement[i].data = 0;
		pList->currentElementCount--;
	}
	assert(pList->currentElementCount == 0);
}

void deleteArrayList(ArrayList* pList)
{
    if (!pList)
        return ;
    free(pList->pElement);
    free(pList);
}

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	if (!pList || position < 0 || position >= pList->maxElementCount)
		return (EXIT_FAILURE);
	if (pList->currentElementCount != 0)
		for (int i = pList->currentElementCount; position < i; i--)
			pList->pElement[i] = pList->pElement[i - 1];
	pList->pElement[position] = element;
	pList->currentElementCount++;
	return (EXIT_SUCCESS);
}

int removeALElement(ArrayList* pList, int position)
{
	int i;

	if (!pList || position < 0 || position >= pList->currentElementCount)
		return (EXIT_FAILURE);
	for (i = position; i < pList->currentElementCount - 1; i++)
		pList->pElement[i] = pList->pElement[i + 1];
	pList->pElement[i].data = 0;
	pList->currentElementCount--;
	return (EXIT_SUCCESS);
}

void displayArrayList(ArrayList *pList)
{
	printf("maxElementCount : %d\n", pList->maxElementCount);
	printf("currentElementCount : %d\n", pList->currentElementCount);
	for (int i = 0 ; i < pList->maxElementCount ; i++)
		printf("%d ", pList->pElement[i].data);
	printf("\n");
}

int getArrayListLength(ArrayList* pList)
{
	if (!pList)
		return (-1);
	return (pList->currentElementCount);
}

int isArrayListFull(ArrayList* pList)
{
	if (!pList)
		return (-1);
	return (pList->maxElementCount == pList->currentElementCount);
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	ArrayListNode *node;

	if (!pList || position < 0 || position >= pList->currentElementCount)
		return (NULL);
	node = &pList->pElement[position];
	return (node);
}

int main(void)
{
	ArrayList *arrayList;
	ArrayListNode node;
	ArrayListNode *get_node;

	arrayList = createArrayList(10);
	
	node.data = 10;
	addALElement(arrayList, 0, node);
	node.data = 20;
	addALElement(arrayList, 1, node);
	node.data = 30;
	addALElement(arrayList, 2, node);
	node.data = 40;
	addALElement(arrayList, 1, node);

	displayArrayList(arrayList);
	// 10 40 20 30
	
	get_node = getALElement(arrayList, 2);
	printf("node : %d\n", get_node->data); // 20
	printf("length : %d\n", getArrayListLength(arrayList));
	printf("is_full : %d\n",isArrayListFull(arrayList));

	removeALElement(arrayList, 3);
	// 10 40 20
	displayArrayList(arrayList);
	removeALElement(arrayList, 1);
	// 10 20
	displayArrayList(arrayList);
	
	removeALElement(arrayList, 0);
	// 20
	displayArrayList(arrayList);
	clearArrayList(arrayList);
	// deleteArrayList(arrayList);
}
