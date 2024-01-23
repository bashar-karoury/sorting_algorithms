#include "sort.h"
/**
* bubble_sort - sort array of integers in ascending order using Bubble
* sort algorithm
* @array: pointer to array
* @size: size of array
*/
void bubble_sort(int *array, size_t size)
{
	int i = 0;
	int k = (int)(size - 1);
	int noswap = 1;
	int j = 0;
	int temp = 0;

	if ((array == NULL) || (size < 2))
		return;
	for (i = 0; i < k; i++)
	{
		if (noswap && i)
			return;

		for (j = 0; j < k - i; j++)
		{
			/*compare with next el=ement, swap if it is greater*/
			if (array[j] > array[j + 1])
			{
				/*swap*/
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				/*print array*/
				print_array(array, size);
				noswap = 0;
			}
		}
	}
}
