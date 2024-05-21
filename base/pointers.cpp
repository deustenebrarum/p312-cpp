#include <iostream>
#include "my_utility.h"

bool is_even(int x) {
	return x % 2 == 0;
}

int* sums_paired(
	int* array1,
	int* array2,
	size_t size
) {
	int* result = new int[size];

	for (size_t i = 0; i < size; i++)
	{
		result[i] = array1[i] + array2[i];
	}

	return result;
}

void pointers_example() {
	int array[5]{ 1,2,3,4,5 };
	int* f = filter(is_even, array, 5);

	print(f, 5);
	delete[] f;
}
