#include "first_last.h"

void first_last(int arr[], int size, int target, int *first, int *last)
{
	int tmp = 0;
	bool check = false;

	while (tmp <= size)
	{
		if (arr[tmp] == target && check == false)
		{
			*first = tmp;
			check = true;
		}
		else if (arr[tmp] == target && check == true)
			*last = tmp;
		tmp++;
	}
	if (tmp >= size && *first < 0)
		*first = -1;
	if (tmp >= size && *last < 0)
		*last = -1;
}

// int main()
// {
// 	int size = 6;
// 	int arr[] = {40, 4, 20, 10, 1, 4};
// 	int first = -2;
// 	int last = -2;

// 	first_last(arr, size, 4, &first, &last);
// 	printf("first = %d\n last = %d\n", first, last);
// 	return (0);
// }
