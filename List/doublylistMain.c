#include "doublylist.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	DoublyList *list;
	DoublyListNode node;

	list = createDoublyList();

	node.data = 10;
	addDLElement(list, 0, node);
	displayDoublyList(list);
	// 10

	node.data = 20;
	addDLElement(list, 0, node);
	displayDoublyList(list);
	// 20 -> 10

	node.data = 30;
	addDLElement(list, 2, node);
	displayDoublyList(list);
	// 20 -> 10 -> 30

	// removeDLElement(list, 0);
	// displayDoublyList(list);
	// // 10 -> 30

	// removeDLElement(list, 1);
	// displayDoublyList(list);
	// // 10

	// removeDLElement(list, 0);
	// displayDoublyList(list);
	// // NULL
	clearDoublyList(list);
	deleteDoublyList(list);
	// system("leaks a.out");
}
