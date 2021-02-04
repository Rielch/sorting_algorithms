#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *
 * @array: array of integers
 * @size: size of the array
 * Return: Void
 */

void quick_sort(int *array, size_t size)
{
	int low = 0, high = size - 1;

	recursive_quicksort(array, size, low, high);
}

/**
 * Lomuto - Lomuto partitioning
 *
 * @array: array of integers
 * @size: size of the array
 * @low: index of the first element of the array
 * @high: index of the last element of the array
 * Return: index of the pivot
 */

int Lomuto(int *array, size_t size, int low, int high)
{
	int i = low, j, tmp;

	for (j = low; j < high; j++)
	{
		if (array[j] < array[high])
		{
			if (array[j] != array[i])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[high] != array[i])
	{
		tmp = array[i];
		array[i] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i);
}

/**
 * recursive_quicksort - recursive function of the quicksort
 *
 * @array: array of integers
 * @size: size of the array
 * @low: index of the first element of the array
 * @high: index of the last element of the array
 * Return: Void
 */

void recursive_quicksort(int *array, size_t size, int low, int high)
{
	int a;

	if (low < high)
	{
		a = Lomuto(array, size, low, high);
		recursive_quicksort(array, size, low, a - 1);
		recursive_quicksort(array, size, a + 1, high);
	}
}
