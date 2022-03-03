#include "circularlist.h"
#include <stdio.h>
#include <stdlib.h>

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
