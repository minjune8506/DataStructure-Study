#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *     46
 *  24    40
 * 10 20 30 34
 */
int main(void)
{
	heap *maxHeap;
	heapNode element;

	maxHeap = createHeap(10);
	element.data = 30;
	insertMaxHeapNode(maxHeap, element);
	element.data = 20;
	insertMaxHeapNode(maxHeap, element);
	element.data = 40;
	insertMaxHeapNode(maxHeap, element);
	element.data = 10;
	insertMaxHeapNode(maxHeap, element);
	element.data = 24;
	insertMaxHeapNode(maxHeap, element);
	element.data = 34;
	insertMaxHeapNode(maxHeap, element);
	element.data = 46;
	insertMaxHeapNode(maxHeap, element);
	display(maxHeap);
/**
 *     40
 *  24    34
 * 10 20 30
 */
	printf("%d\n", deleteMaxHeapNode(maxHeap));
	display(maxHeap);
	deleteHeap(maxHeap);
	maxHeap = NULL;
	// system("leaks a.out");
}
