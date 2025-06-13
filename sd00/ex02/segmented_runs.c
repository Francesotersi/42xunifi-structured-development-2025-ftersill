#include "segmented_runs.h"

int	seg_size_and_greater(const int *arr, int size, int *tmp)
{
	int	i = (*tmp);
	int num_counter = 0;

	while (i < size && arr[i] != -1)
	{
		if (i + 1 < size && arr[i + 1] && arr[i + 1] != -1 && \
		arr[i] > arr[i + 1])
		{
			while ((*tmp) < size && arr[(*tmp)] != -1)
				(*tmp)++;
			return (1);
		}
		num_counter++;
		i++;
	}
	if (num_counter < 3)
	{
		while ((*tmp) < size && arr[(*tmp)] != -1)
			(*tmp)++;
		return (1);
	}
	(*tmp) = i;
	return (0);
}

int count_segments(const int *arr, int size)
{
	int	tmp = 0;
	int seg_counter = 0;

	while (tmp < size)
	{
		if (arr[tmp] == -1)
		{
			tmp++;
			continue ;
		}
		if (seg_size_and_greater(arr, size, &tmp) == 1)
			continue ;
		seg_counter++;
		tmp++;
	}
	return (seg_counter);
}

int main()
{
	int arr[] = {2, 3, 4, -1, 5, 8, 7, -1, 1, 2, 3, 4};
	int size = 12;

	printf("segment number = %d\n", count_segments(arr, size));
	return (0);
}
