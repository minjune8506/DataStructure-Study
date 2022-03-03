#include "arraylist.h"
#include <stdio.h>
#include <stdlib.h>

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
