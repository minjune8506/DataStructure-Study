#ifndef _LINKEDLIST_
#define _LINKEDLIST_

typedef struct ListNodeType
{
	int data;
	struct ListNodeType* pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	// 현재 저장된 원소의 개수
	ListNode *headerNode;		// 헤더 노드(Header Node)
} LinkedList;

ListNode	*createListNode(int data);
LinkedList	*createLinkedList();

int			addFirst(LinkedList *pList, ListNode element);
int			addLast(LinkedList *pList, ListNode element);
int			addLLElement(LinkedList* pList, int position, ListNode element);

int			removeFirst(LinkedList *pList);
int			removeLast(LinkedList *pList);
int			removeLLElement(LinkedList* pList, int position);

ListNode	*getNodeAt(LinkedList *pList, int position);
ListNode*	getLLElement(LinkedList* pList, int position);

int			getLinkedListLength(LinkedList* pList);
void		clearLinkedList(LinkedList* pList);
void		deleteLinkedList(LinkedList* pList);

void		display(LinkedList *pList);
void		error(char *message);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif