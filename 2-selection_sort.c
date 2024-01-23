#include "sort.h"
#include <stdlib.h>
/**
* selection_sort - sorts an array of integers in ascending order using
* selection sort algorithm
* @array: pointer to array
* @size: size of array
*/
void selection_sort(int *array, size_t size)
{
	int i, j, temp, min_idx, no_min = 1;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < (int)size - 1; i++)
	{
		min_idx = i;
		no_min = 1;
		for (j = i + 1; j < (int)size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
				no_min = 0;
			}
		}
		if (no_min)
		{
			break;
		}
		if (min_idx != i)
		{
			/*swap two elements*/
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}

	}

}
