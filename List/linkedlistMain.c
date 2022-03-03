#include "linkedlist.h"
#include <stdlib.h>

int main(void)
{
	LinkedList *list;
	ListNode node;
	
	list = createLinkedList();

	node.data = 10;
	addLLElement(list, 0, node);
	displayLinkedList(list);
	// 10

	node.data = 20;
	addLLElement(list, 0, node);
	displayLinkedList(list);
	// 20 -> 10

	node.data = 30;
	addLLElement(list, 1, node);
	displayLinkedList(list);
	// 20 -> 30 -> 10

	node.data = 40;
	addLLElement(list, 3, node);
	displayLinkedList(list);
	// 20 -> 30 -> 10 -> 40

	// removeLLElement(list, 0);
	// displayLinkedList(list);
	// // 30 -> 10 -> 40

	// removeLLElement(list, 1);
	// displayLinkedList(list);
	// // 30 -> 40

	// removeLLElement(list, 1);
	// displayLinkedList(list);
	// // 30

	// removeLLElement(list, 0);
	// displayLinkedList(list);
	// Empty List

	// clearLinkedList(list);
	// deleteLinkedList(list);
	// system("leaks a.out");
	reverseLinkedList(list);
	displayLinkedList(list);
}
