#ifndef HEAP_H
# define HEAP_H
typedef struct heapNodeType{
	int data;
}heapNode;

typedef struct heapType{
	int maxElementCount;
	int currentElementCount;
	heapNode *pElement;
}heap;

heap	*createHeap(int maxElementCount);
void	deleteHeap(heap *pHeap);
void	swap(int *a, int *b);
int		isHeapEmpty(heap *pHeap);
int		isHeapFull(heap *pHeap);
int		insertMaxHeapNode(heap *pHeap, heapNode element);
int		insertMinHeapNode(heap *pHeap, heapNode element);
int		deleteMaxHeapNode(heap *pHeap);
int		deleteMinHeapNode(heap *pHeap);
void	display(heap *pHeap);

#endif
