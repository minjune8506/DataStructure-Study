#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 8

int		is_descending(int *ary, int arraySize)
{
	for (int i = 0 ; i < arraySize ; i++)
		if (ary[i] < ary[i + 1])
			return (0);
	return (1);
}

int		is_ascending(int *ary, int arraySize)
{
	for (int i = 0 ; i < arraySize ; i++)
		if (ary[i] > ary[i + 1])
			return (0);
	return (1);
}

void	print_array(int *ary, int arraySize)
{
	for (int i = 0 ; i < arraySize ; i++)
		printf("%d ",ary[i]);
	printf("\n");
}

void	switch_LR(int left, int right, int *ary)
{
	int temp;
	
	temp = ary[left];
	ary[left] = ary[right];
	ary[right] = temp;
}

int		partition(int ary[], int start, int end)
{
	int left = start, right = end - 1;
    int pivot = end;
	
	while (left < right)
	{
		while (ary[left] < ary[pivot] && left <= end)
			left++;
		while (ary[right] > ary[pivot] && right >= start)
			right--;
        if (left < right)
            switch_LR(left, right, ary);
	}
	if (left >= right)
		switch_LR(left, pivot, ary);
	return (left);
}

void	quick_sort(int ary[], int start, int end)
{
	int pivot;

	if (end - start <= 0)
		return ;
	pivot = partition(ary, start, end);
	quick_sort(ary, start, pivot - 1);
    quick_sort(ary, pivot + 1, end);
}

int		main(void)
{
	// int ary[ARRAY_SIZE] = {80, 50, 70, 10, 60, 20, 40, 30};
	// int ary[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};
	// int ary[ARRAY_SIZE] = {8, 7, 6, 5, 4, 3, 2, 1};
	int ary[ARRAY_SIZE] = {70, 60, 80, 30, 40, 10, 50, 24};
	printf("before sorting : ");
	print_array(ary, ARRAY_SIZE);
	quick_sort(ary, 0, ARRAY_SIZE - 1);
	if (!is_ascending(ary, ARRAY_SIZE))
	{
		printf("array not sorted\n");
		exit(1);
	}
	printf("after sorting  : ");
	print_array(ary, ARRAY_SIZE);
}
