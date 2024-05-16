#include <iostream>
#include "my_utility.h"

int* union_set(
	const int* array1,
	const size_t size1,
	const int* array2,
	const size_t size2
) {
	int* array_res = new int[size1 + size2];

	size_t count = 0;
	for (size_t i = 0; i < size1; i++)
	{
		if(!has(
			array_res, count, array1[i]
		)) {
			array_res[count] = array1[i];
			count++;
		}
	}

	for (size_t i = 0; i < size2; i++)
	{
		if (!has(
			array_res, count, array2[i]
		)) {
			array_res[count] = array2[i];
			count++;
		}
	}

	return array_res;
}

size_t count_by_sign(
	const int* array,
	size_t size,
	int signed_number
) {
	size_t count = 0;
	for (size_t i = 0; i < size; i++)
	{
		bool is_right_sign = array[i] == 0;
		if (signed_number > 0) {
			is_right_sign = array[i] > 0;
		}
		else if (signed_number < 0) {
			is_right_sign = array[i] < 0;
		}

		if (is_right_sign) count++;
	}

	return count;
}

int* find(
	int* array,
	size_t size,
	const int* sub_array,
	size_t sub_size
) {
	for (size_t i = 0; i < size - sub_size + 1; i++)
	{
		bool is_subsequence = true;
		for (size_t j = 0; j < sub_size; j++)
		{
			if (array[i + j] != sub_array[j]) {
				is_subsequence = false;
				break;
			}
		}
		if (is_subsequence) {
			return array + i;
		}
	}

	return nullptr;
}

void sum_prod(
	const int* array, size_t size,
	int& sum, int& prod
) {
	sum = 0;
	prod = 1;

	for (size_t i = 0; i < size; i++)
	{
		sum += array[i];
		prod *= array[i];
	}
}



// функция должна принимать массив
// старый размер и желаемый новый размер
// выдавать новый массив с теми же элементами
// и желаемым размером

int main() {
	size_t size = 5;
	int* array1 = new int[size]{ 1,2,3,4,5 };
	
	array1 = reallocate(array1, 5, 10);
	
	pop(array1, size, 3);
	size = 4;

	print(array1, size);
}
