#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct ListNodeType
{
	int vertexID;
	int weight;
	struct ListNodeType *pLink;
}ListNode;

typedef struct LinkedListType
{
	int currentElementCount;
	int vertexID;
	ListNode headerNode;
}LinkedList;

ListNode	*createListNode(int vertexID, int weight);
LinkedList	*createLinkedList(int vertexID);
ListNode	*getLLElement(LinkedList* pList, int position);
int			addLLElement(LinkedList* pList, int position, ListNode element);
int			removeLLElement(LinkedList* pList, int position);
void		clearLinkedList(LinkedList* pList);
void		deleteLinkedList(LinkedList* pList);
#endif
