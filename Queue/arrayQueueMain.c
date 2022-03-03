#include "arrayqueue.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	ArrayQueue *que;
	ArrayQueueNode node;
	ArrayQueueNode *temp;

	que = createArrayQueue(5);
	node.data = 'a';

	for (int i = 0 ; i < que->maxElementCount - 1 ; i++)
	{
		enqueueAQ(que,  node);
		node.data++;
		displayArrayQueue(que);
	}
	printf("isArrayQueueFull : %s\n\n", isArrayQueueFull(que) ? "True" : "False");
	for (int i = 0 ; i < que->maxElementCount - 1 ; i++)
	{
		printf("peek : %c\n", peekAQ(que)->data);
		temp = dequeueAQ(que);
		printf("dequeue : %c\n", temp->data);
		temp->data = 0;
		displayArrayQueue(que);
	}
	printf("isArrayQueueEmpty : %s\n\n", isArrayQueueEmpty(que) ? "True" : "False");
	for (int i = 0 ; i < que->maxElementCount - 1 ; i++)
	{
		enqueueAQ(que,  node);
		node.data++;
		displayArrayQueue(que);
	}
	deleteArrayQueue(que);
	// system("leaks a.out");
}
