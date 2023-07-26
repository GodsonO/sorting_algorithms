#include "sort.h"

void lomuto_sort(int *arr, int left, int right, size_t size);
int lomuto_partition(int *arr, int left, int right, size_t size);

/**
  * quick_sort - sorts an array of integers in ascending order
  * using the Quick sort algorithm
  * @array: array to be sorted
  * @size: size of array
  */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	lomuto_sort(array, 0, size - 1, size);
}

/**
  * lomuto_sort - recursive sorting algorithm
  * @arr: array
  * @left: The starting index
  * @right: ending index
  * @size: size of array
  */
void lomuto_sort(int *arr, int left, int right, size_t size)
{
	int p;

	if (right > left)
	{
		p = lomuto_partition(arr, left, right, size);
		lomuto_sort(arr, left, p - 1, size);
		lomuto_sort(arr, p + 1, right, size);
	}
}

/**
  * lomuto_partition - split array
  * @arr: array
  * @left: starting index
  * @right: ending index
  * @size: the array size
  * Return: partition index
  */
int lomuto_partition(int *arr, int left, int right, size_t size)
{
	int x, y, pivot, contain;

	pivot = arr[right];
	x = left;

	for (y = left; y < right; y++)
	{
		if (arr[y] < pivot)
		{
			if (x != y)
			{
				contain = arr[y];
				arr[y] = arr[x];
				arr[x] = contain;
				print_array(arr, size);
			}
			x++;
		}
	}
	if (arr[x] != arr[right])
	{
		contain = arr[x];
		arr[x] = arr[right];
		arr[right] = contain;
		print_array(arr, size);
	}

	return (x);
}
