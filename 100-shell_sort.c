#include "sort.h"
/**
* shell_sort -  sorts an array of integers in ascending order
* using the Shell sort algorithm, using the Knuth sequence
* @array: Array to sort.
* @size: Size of the array.
*/
void shell_sort(int *array, size_t size)
{
	int temp;
	unsigned int k = 1, i, j, select;

	while (k < size)
		k = k * 3 + 1;
	while (k > 1)
	{
		k = (k - 1) / 3;
		for (i = 0; i < size - 1; i++)
		{
			select = i;
			for (j = i + k; j < size; j += k)
			{
				if (array[j] < array[select])
				{
					select = j;
					temp = array[select];
					array[select] = array[i];
					array[i] = temp;
				}
			}
		}
		print_array(array, size);
	}
}
