#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in
 * ascending order using Counting Sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	int max = array[0], *count, *output;

	for (size_t i = 0; i < size; i++)
		max = (array[i] > max) ? array[i] : max;
	count = calloc(max + 1, sizeof(int));
	if (!count)
		return;

	output = malloc(size * sizeof(int));
	if (!output)
	{
		free(count);
		return;
	}
	for (size_t i = 0; i < size; i++)
		count[array[i]]++;

	for (int i = 1; i <= max; i++)
		count[i] += count[i - 1];

	for (ssize_t i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (size_t i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
