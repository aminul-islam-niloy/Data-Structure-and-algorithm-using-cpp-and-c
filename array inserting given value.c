#include <stdio.h>

int main()
{
	int arr[]={7,3,9,5,2,6};
	int i, x, pos, n = 5;

	x = 1;
	pos = 4;
	n++;

	for (i = n-1; i >= pos; i--)
		arr[i] = arr[i - 1];
	arr[pos - 1] = x;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
