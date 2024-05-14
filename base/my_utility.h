#pragma once
#include <iostream>

// функция печати массива на экран
template <typename T>
void print(const T array[], const size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl;
}

// функция генерации рандомных значений
// для массива в диапазоне
void generate_random_values(
	int array[],
	const size_t size,
	const int min,
	const int max
) {
	for (size_t i = 0; i < size; i++)
	{
		array[i] = rand() % (max - min) + min;
	}
}

// функция сортировки массива
// улучшенной версией сортировки
// пузырьком(с проверкой отсортированности)
template <typename T>
void sort(T* array, const size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		bool is_sorted = true;
		for (size_t j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j - 1]) {
				std::swap(array[j], array[j - 1]);
				is_sorted = false;
			}
		}
		if (is_sorted) break;
	}
}

// функция переворачивания массива
void reverse(int array[], const size_t size) {
	for (size_t i = 0; i < size / 2; i++)
	{
		std::swap(array[i], array[size - 1 - i]);
	}
}

// функция поиска индекса элемента в массиве
template <typename T>
size_t index_of(
	const T array[], 
	const size_t size,
	const T value
) {
	for (size_t i = 0; i < size; i++)
	{
		if (value == array[i]) return i;
	}
	throw std::invalid_argument(
		"array has no such value"
	);
}

// функция проверки наличия элемента в массиве
template <typename T>
bool has(
	const T array[],
	const size_t size,
	const T value
) {
	for (size_t i = 0; i < size; i++)
	{
		if (value == array[i]) return true;
	}
	return false;
}

// функция удаление элемента массива
// (последний элемент после сдвига 
// просто заменить на 0)
template <typename T>
T pop(
	T* array,
	const size_t size,
	const size_t index
) {
	if (index >= size) {
		throw std::invalid_argument(
			"index must be lesser than size"
		);
	}

	const T removed_value = array[index];

	for (size_t i = index; i < size - 1; i++)
	{
		array[i] = array[i + 1];
	}
	array[size - 1] = T();

	return removed_value;
}

// функция бинарного поиска в массиве
template <typename T>
size_t binary_index_of(
	const T array[],
	const size_t size,
	const T value
) {
	size_t left_border = 0;
	size_t right_border = size - 1;

	while (left_border <= right_border) {
		size_t middle_index = 
			(left_border + right_border) / 2;
		if (array[middle_index] == value) {
			return middle_index;
		}
		if (array[middle_index] < value) {
			right_border = middle_index - 1;
		} else if (array[middle_index] > value) {
			left_border = middle_index + 1;
		}
	}
	throw std::invalid_argument(
		"array has no such value"
	);
}

int* concat(
	const int* array1,
	const size_t size1,
	const int* array2,
	const size_t size2
) {
	int* array_res = new int[size1 + size2];

	for (size_t i = 0; i < size1; i++)
	{
		array_res[i] = array1[i];
	}

	for (size_t i = 0; i < size2; i++)
	{
		array_res[size1 + i] = array2[i];
	}

	return array_res;
}

void reallocate(
	int*& array,
	size_t size, size_t new_size
) {
	int* new_array = new int[new_size];
	const size_t min_size = std::min(
		size, new_size
	);
	for (size_t i = 0; i < min_size; i++)
	{
		new_array[i] = array[i];
	}
	delete[] array;
	array = new_array;
}
