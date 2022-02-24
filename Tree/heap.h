#ifndef HEAP_H
# define HEAP_H

#include <stdlib.h>
#include <stdio.h>

typedef struct heapNodeType{
	int data;
}heapNode;

typedef struct heapType{
	int maxElementCount;
	int currentElementCount;
	heapNode *rootNode; // 배열
}heap;

heap *createHeap(int maxElementCount);
void deleteHeap(heap *pHeap);
void insertMaxHeapNode(heap *pHeap, heapNode element);
void insertMinHeapNode(heap *pHeap, heapNode element);
int deleteMaxHeapNode(heap *pHeap);
void swap(int *a, int *b);
int isHeapEmpty(heap *pHeap);
int isHeapFull(heap *pHeap);
void display(heap *pHeap);
#define TRUE 1
#define FALSE 0

#endif
