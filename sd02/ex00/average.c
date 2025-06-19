#include "average.h"

float average(const int *arr, int size)
{
	float total = 0;
	int tmp = 0;

	if (size <= 0)
		return (-1);
	while (tmp < size)
	{
		if (arr[tmp] >= 0 && arr[tmp] <= 100)
			total += (float)arr[tmp];
		tmp++;
	}
	return (total / (float)size);
}

// int main()
// {
// 	int size = 4;
// 	int arr[] = {2, 20, 10, 5};

// 	printf("%f\n", average(arr, size));
// 	return (0);
// }
