#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
void swap(int *a, int *b);
void sort_partition(int *array, int start, int end, int size);
/**
* quick_sort - sorts an array of integers in ascending order using
* quick sort algorithm
* @array: pointer to array
* @size: size of array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_partition(array, 0, (int)(size - 1), (int)size);
}

/**
* sort_partition - sorts array using quich sort technique
* @array: array to sort
* @start: start index
* @end: end index
* @size: size of array for printing
*/
void sort_partition(int *array, int start, int end, int size)
{
	/*select pivot as last element*/
	int pivot = array[end];
	int left = start;
	int right = end - 1;
	int found = 0;

	if (start >= end)
		return;
	for (left = start; left < end && left <= right; left++)
	{
		if (array[left] > pivot)
		{
			found = 1;
			/*find smallest from right*/
			while (array[right] > pivot && right > left)
				right--;
			if (left != right)
			{
				swap(&(array[left]), &(array[right]));
				print_array(array, size);
			}
		}

	}
	if (left < end || found)
	{
		swap(&(array[right]), &(array[end]));
		print_array(array, size);
	}
	else
		right = end;

	sort_partition(array, start, right - 1, size);
	sort_partition(array, right + 1, end, size);
}

/**
* swap - swaps values of two pointers
* @a: pointer to first element
* @b: pointer to second element
*/
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
