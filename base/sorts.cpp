#include <iostream>

#include "my_utility.h"

int main() {
	const size_t size = 5;
	int array[size]{ 1,2,3,4,5 };

	pop<int>(array, size, 2);

	std::cout << sum_range(1, 10);

}
