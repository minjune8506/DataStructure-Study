#include "arraylist.h"
#include <stdlib.h>
#include <stdio.h>

ArrayList *createArrayList(int maxElementCount)
{
	ArrayList *ary;

	if (maxElementCount <= 0)
		return (NULL);
	ary = (ArrayList *)malloc(sizeof(ArrayList));
    if (ary == NULL)
        return (NULL);
	ary->maxElementCount = maxElementCount;
	ary->currentElementCount = 0;
	ary->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
    if (ary->pElement == NULL)
        return (NULL);
	for (int i = 0; i < ary->maxElementCount ; i++)
		ary->pElement[i].data = 0;
	return (ary);
}

void clearArrayList(ArrayList* pList)
{
    if (!pList)
        return ;
	for (int i = 0; i < pList->maxElementCount ; i++)
		pList->pElement[i].data = 0;
    pList->currentElementCount = 0;
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
		return (-1);
	if (pList->currentElementCount >= pList->maxElementCount)
		return (-1);
	if (pList->currentElementCount != 0)
	{
		for (int i = pList->currentElementCount; position <= i; i--)
			pList->pElement[i] = pList->pElement[i - 1];
		pList->pElement[position] = element;
	}
	else
		pList->pElement[position] = element;
	pList->currentElementCount++;
	return (0);
}

int removeALElement(ArrayList* pList, int position)
{
	if (!pList || position < 0 || position >= pList->currentElementCount)
		return (-1);
	for (; position <= pList->currentElementCount - 1; position++)
		pList->pElement[position] = pList->pElement[position + 1];
	pList->pElement[position].data = 0;
	pList->currentElementCount--;
	return (0);
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
	if (pList == NULL)
		return (-1);
	return (pList->currentElementCount);
}

int isArrayListFull(ArrayList* pList)
{
	if (!pList)
		return (-1);
	return pList->maxElementCount == pList->currentElementCount;
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
	printf("node : %d\n", get_node->data);
	printf("length : %d\n", getArrayListLength(arrayList));
	printf("is_full : %d\n",isArrayListFull(arrayList));

	removeALElement(arrayList, 1);
	// 10 20 30
	displayArrayList(arrayList);
	removeALElement(arrayList, 1);
	// 10 30
	displayArrayList(arrayList);
	// 30
	removeALElement(arrayList, 0);
	displayArrayList(arrayList);

}
