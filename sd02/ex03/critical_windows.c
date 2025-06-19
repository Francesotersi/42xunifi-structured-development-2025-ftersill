#include "critical_windows.h"

int average(const int *arr, int size)
{
	int total = 0;
	int tmp = 0;

	if (size <= 0)
		return (-1);
	while (tmp < size)
	{
		total += arr[tmp];
		tmp++;
	}
	return (total / size);
}

int	bigger_than_(int limiter, int *arr)
{
	int	i = 0;

	while (i < 5)
	{
		if (arr[i] > limiter)
			return (1);
		i++;
	}
	return (0);
}

int	atleast(int limiter, int *arr)
{
	int	i = 0;
	int count = 0;

	while (i < 5)
	{
		if (arr[i] >= limiter)
			count++;
		i++;
	}
	if (count >= 3)
		return (0);
	return (1);
}

int critical_checker(const int *day_one, int temp, int *critical_num)
{
	int arr[] = {day_one[temp], day_one[temp + 1], day_one[temp + 2], \
		day_one[temp + 3], day_one[temp + 4]};
	if (atleast(70, arr) == 1)
		return (1);
	if (average(arr, 5) < 90)
		return (1);
	if (bigger_than_(150, arr) == 1)
		return (1);
	(*critical_num)++;
	return (0);
}

int count_critical_windows(const int *readings, int size)
{
	int tmp = 0;
	int critical_num = 0;

	while (tmp < size)
	{
		if (tmp + 4 < size)
		{
			if (critical_checker(readings, tmp, &critical_num) == 1)
			{
				tmp++;
				continue ;
			}
		}
		tmp++;
	}
	return (critical_num);
}

// int main()
// {
// 	int arr[] = {90, 110, 130, 100, 149, 70, 10};
// 	int size = 7;

// 	printf("critical windows = %d\n", count_critical_windows(arr, size));
// 	return (0);
// }
