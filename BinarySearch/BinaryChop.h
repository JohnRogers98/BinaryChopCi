#pragma once
#include <math.h>

int SearchIndexOfElementInArrayRecursive(int element, int *array)
{
	int minIndex = 0;
	int maxIndex = GetArraySize(array);

	return SearchIndex(array, &minIndex, &maxIndex, element);
}

int SearchIndex(int *array, int *minIndex, int *maxIndex, int element)
{
	int averangeIndex = GetAverangeIndex(*minIndex, *maxIndex);

	int status = CompareSearchElementWithElementInIndex(element, array[averangeIndex]);

	if (status == 0)
		return averangeIndex;
	if (status == -1)
		*maxIndex = averangeIndex;
	else
		*minIndex = averangeIndex;


	if (*maxIndex - *minIndex == 1)
	{
		if (status == -1) 
		{
			if (array[*minIndex] == element)
			{
				return *minIndex;
			}
		}
		else 
		{
			if (array[*maxIndex] == element)
			{
				return *maxIndex;
			}
		}
		return -1;
	}

	SearchIndex(array, minIndex, maxIndex, element);
}


int SearchIndexOfElementInArrayImperative(int element, int* array)
{
	int minIndex = 0;
	int maxIndex = GetArraySize(array);
	int averangeIndex = GetAverangeIndex(minIndex, maxIndex);

	int status;

	while ((status = CompareSearchElementWithElementInIndex(element, array[averangeIndex])) != 0)
	{
		if (status == -1)
			maxIndex = averangeIndex;
		else
			minIndex = averangeIndex;
		averangeIndex = GetAverangeIndex(minIndex, maxIndex);

		if (maxIndex - minIndex == 1)
		{
			if (status == -1)
			{
				if (array[minIndex] == element)
				{
					return minIndex;
				}
			}
			else
			{
				if (array[maxIndex] == element)
				{
					return maxIndex;
				}
			}
			return -1;
		}
	}
	return averangeIndex;
}


int GetAverangeIndex(int minIndex, int maxIndex)
{
	return ceil(
		((double)maxIndex - (double)minIndex) / 2) + minIndex;
}


int CompareSearchElementWithElementInIndex(int searchElement, int elementInIndex)
{
	if (searchElement == elementInIndex)
		return 0;
	else if (searchElement > elementInIndex)
		return 1;
	else
		return -1;
}


int GetArraySize(int* array)
{
	return sizeof(array);
}