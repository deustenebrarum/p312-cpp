#include <iostream>

bool is_prime(int number) {
	for (
		int divider = 2; 
		divider <= sqrt(number); 
		divider++
	) {
		if (number % divider == 0) return false;
	}
	return true;
}

size_t count_primes(
	const int array[],
	const size_t size
) {
	size_t count = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (is_prime(array[i])) count++;
	}

	return count;
}

void count_primes_example() {
	const int array[]{ 1,8, 1009, 3, 4 };

	std::cout << count_primes(array, 4);
}
