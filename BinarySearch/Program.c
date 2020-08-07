#include <stdio.h>
#include "BinaryChop.h"

#define ELEMENT 4

const int ARRAY[5] = { 4, 8, 9, 11, 20 };

int main() 
{
	int searchIndex = SearchIndexOfElementInArrayRecursive(ELEMENT, ARRAY);
	printf("%d", searchIndex);
	return 0;
}