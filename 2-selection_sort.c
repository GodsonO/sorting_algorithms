#include "sort.h"
/**
* selection_sort - sorts an array of integers in ascending
* order using the Selection sort algorithm
* @array: Array to be sorted.
* @size: Size of the array.
*/
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, select;
	int contain;

	for (i = 0; i < size - 1; i++)
	{
		select = i;
		for (j = i + 1; j < size; j++)
			if (array[select] > array[j])
			select = j;
		if (select == i)
			continue;
		contain = array[i];
		array[i] = array[select];
		array[select] = contain;
		print_array(array, size);
	}
}
