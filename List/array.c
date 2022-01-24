#include <stdio.h>

int main(void)
{
	int arr[5] = {1, 2, 3, 4, 5};

	printf("%p\n", &arr[0]); // 주소가 4씩 증가한다.
	printf("%p\n", &arr[1]);
	printf("%p\n", &arr[2]);
	printf("%p\n", &arr[3]);
	printf("%p\n", &arr[4]);
}
