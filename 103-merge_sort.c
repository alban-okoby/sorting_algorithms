#include "sort.h"
#include <stdlib.h>

/**
 * merge - Merges two sub-arrays into one sorted array
 * @array: The original array
 * @left: Pointer to the left sub-array
 * @right: Pointer to the right sub-array
 * @size: Size of the sub-arrays
 */
void merge(int *array, int *left, int *right, size_t size)
{
	int *merged;
	size_t i = 0, j = 0, k = 0;

	merged = malloc(size * sizeof(int));
	if (!merged)
		return;

	while (i < size / 2 && j < size - size / 2)
	{
		if (left[i] <= right[j])
			merged[k++] = left[i++];
		else
			merged[k++] = right[j++];
	}
	while (i < size / 2)
		merged[k++] = left[i++];

	while (j < size - size / 2)
		merged[k++] = right[j++];

	for (i = 0; i < size; i++)
		array[i] = merged[i];
	free(merged);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t mid = size / 2;
        int *left = array;
        int *right = array + mid;

	if (!array || size < 2)
		return;

	if (size % 2 != 0)
		mid++;

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, right, size);
}
