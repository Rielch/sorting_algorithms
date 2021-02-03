#include "sort.h"

/**
 * selection_sort - sorts a rray of integers in ascending order
 *
 * @array: array of integers
 * @size: size of the array
 * Return: Void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, actual, min;
	int tmp;

	for (actual = 0; actual < size; actual++)
	{
		min = actual;
		for (i = actual; i < size; i++)
		{
			if (array[i] < array[min])
				min = i;
		}
		if (min != actual)
		{
			tmp = array[actual];
			array[actual] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
