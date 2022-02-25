#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *      10
 *   20     34
 * 30  24  40  46
 */
int main(void)
{
	heap *minHeap;
	heapNode element;

	minHeap = createHeap(10);
	element.data = 30;
	insertMinHeapNode(minHeap, element);
	element.data = 20;
	insertMinHeapNode(minHeap, element);
	element.data = 40;
	insertMinHeapNode(minHeap, element);
	element.data = 10;
	insertMinHeapNode(minHeap, element);
	element.data = 24;
	insertMinHeapNode(minHeap, element);
	element.data = 34;
	insertMinHeapNode(minHeap, element);
	element.data = 46;
	insertMinHeapNode(minHeap, element);
	display(minHeap);

/**
 *       20
 *   24      34
 * 30  46  40
 */
	printf("%d\n", deleteMinHeapNode(minHeap));
	display(minHeap);
	deleteHeap(minHeap);
	minHeap = NULL;
	// system("leaks a.out");
}
