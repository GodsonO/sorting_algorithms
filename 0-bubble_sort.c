#include "sort.h"
/**
* bubble_sort - sorts an array of integers in ascending
* order using the Bubble sort algorithm
* @array: the array to sort.
* @size: Size of the array.
*/
void bubble_sort(int *array, size_t size)
{
	int n = size - 1, i, j = 0, contain;

	while (j < n)
	{
		for (i = 0; i < n; i++)
		{
			if (array[i] > array[i + 1])
			{
				contain = array[i + 1];
				array[i + 1] = array[i];
				array[i] = contain;
				print_array(array, size);
			}
		}
		++j;
	}
}
