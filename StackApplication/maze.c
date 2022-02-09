#include "mapdef.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

char map[WIDTH][HEIGHT] = {
	{'s', 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 0, 1, 1, 1, 1},
	{1, 1, 1, 0, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 'e'}
};

MapPosition start = {0, 0, RIGHT};
MapPosition end = {WIDTH - 1, HEIGHT - 1};

LinkedStack *createLinkedStack()
{
	LinkedStack *stack;
 
	stack = (LinkedStack *)malloc(sizeof(LinkedStack));
	if (!stack)
		return (NULL);
	stack->currentElementCount = 0;
	stack->pTopElement = NULL;
	return (stack);
}

StackNode *createStackNode(MapPosition data)
{
	StackNode *node;

	node = (StackNode *)malloc(sizeof(StackNode));
	if (!node)
		return (NULL);
	node->data = data;
	node->pLink = NULL;
	return (node);
}

int pushLS(LinkedStack *pStack, MapPosition element)
{
	StackNode *node;

	if (!pStack)
		return (EXIT_FAILURE);
	node = createStackNode(element);
	if (!pStack->pTopElement) // Empty Stack
		pStack->pTopElement = node;
	else
	{
		node->pLink = pStack->pTopElement;
		pStack->pTopElement = node;
	}
	pStack->currentElementCount++;
	return (EXIT_SUCCESS);
}

StackNode *popLS(LinkedStack *pStack)
{
	StackNode *node;

	if (!pStack || !pStack->pTopElement)
		return (NULL);
	node = pStack->pTopElement;
	pStack->pTopElement = pStack->pTopElement->pLink;
	pStack->currentElementCount--;
	return (node);
}

StackNode *peekLS(LinkedStack *pStack)
{
	StackNode *node;

	if (!pStack || !pStack->pTopElement)
		return (NULL);
	node = pStack->pTopElement;
	return (node);
}

void deleteLinkedStack(LinkedStack *pStack)
{
	StackNode *iter;
	StackNode *removed;
	
	iter = pStack->pTopElement;
	while (iter)
	{
		removed = iter;
		iter = iter->pLink;
		free(removed);
		pStack->currentElementCount--;
	}
	assert(pStack->currentElementCount == 0);
	free(pStack);
}

int isLinkedStackEmpty(LinkedStack *pStack)
{
	return (pStack->currentElementCount == 0);
}

void display(LinkedStack *pStack)
{
	StackNode *iter;

	if (!pStack)
		return ;
	printf("currentElementcount : %d\n", pStack->currentElementCount);
	if (!pStack->pTopElement)
		printf("Empty stack\n");
	else
	{
		iter = pStack->pTopElement;
		printf("Stack : ");
		for ( ; iter != NULL ; iter = iter->pLink)
		{
			printf("( %d, %d ) -> ", iter->data.x, iter->data.y);
		}
		printf("\n");
	}
}

void print_maze()
{
	for (int i = 0 ; i < HEIGHT ; i++)
	{
		for (int j = 0 ; j < WIDTH ; j++)
		{
			if (map[i][j] == WALL)
				printf("◼︎ ");
			else if (map[i][j] == NOT_VISIT)
				printf("◻︎ ");
			else if (map[i][j] == RIGHT)
				printf("> ");
			else if (map[i][j] == LEFT)
				printf("< ");
			else if (map[i][j] == DOWN)
				printf("V ");
			else if (map[i][j] == UP)
				printf("^ ");
			else
				printf("%c ", map[i][j]);
		}
		printf("\n");
	}
}

void push_pos(int x, int y, int direction, LinkedStack *pStack)
{
	MapPosition data;
	
	if (x < 0 || y < 0 || x > WIDTH - 1 || y > HEIGHT - 1)
		return ;
	data.x = x;
	data.y = y;
	data.direction = direction;
	if (map[y][x] == NOT_VISIT || map[y][x] == 'e')
		pushLS(pStack, data);
}

int main(void)
{
	LinkedStack *pStack;
	MapPosition curr = start;
	StackNode *node;

	print_maze();
	pStack = createLinkedStack();
	while (curr.x != end.x || curr.y != end.y)
	{
		map[curr.y][curr.x] = curr.direction;
		push_pos(curr.x + 1, curr.y, RIGHT, pStack); // right
		push_pos(curr.x, curr.y + 1, DOWN, pStack); // down
		push_pos(curr.x - 1, curr.y, LEFT, pStack); // left
		push_pos(curr.x, curr.y - 1, UP, pStack); // up
		if (isLinkedStackEmpty(pStack))
		{
			fprintf(stderr, "Error\n");
			exit(1);
		}
		node = popLS(pStack);
		curr.x = node->data.x;
		curr.y = node->data.y;
		curr.direction = node->data.direction;
		free(node);
		printf("(%d, %d) ->", curr.x, curr.y);
	}
	printf("\n");
	// display(pStack);
	print_maze();
	// system("leaks a.out");
}
