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
	if (start >= end)
		return;
	while (right > left)
	{
		while (array[right] > pivot && right > left)
			right--;
		while (array[left] < pivot && right > left)
			left++;
		if (right != left)
		{
			swap(&(array[right]), &(array[left]));
			print_array(array, size);
		}
	}
	if ((array[end] < array[left]) && (end != left))
	{	
		swap(&(array[left]), &(array[end]));
		print_array(array, size);
	}
	printf("left at %d = %d\n", left, array[left]);
	printf("right at %d = %d\n", right, array[right]);
	printf("[%d --- %d ]\n", array[start], array[left - 1]);
	sort_partition(array, start, left - 1, size);
	
	printf("[%d --- %d ]\n", array[left + 1], array[end]);
	sort_partition(array, left + 1, end, size);
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
