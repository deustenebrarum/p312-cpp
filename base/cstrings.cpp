#include <iostream>

// c-строки / c-strings
size_t mystrlen(const char* str) {
	size_t count = 0;
	for (; str[count] != '\0'; count++);
	return count;
}

char* mystrcpy(char* str1, const char* str2) {
	for (size_t i = 0; str2[i] != '\0'; i++)
	{
		str1[i] = str2[i];
	}

	return str1;
}

char* mystrcat(char* str1, const char* str2) {
	size_t size1 = mystrlen(str1);

	mystrcpy(str1 + size1, str2);

	return str1;
}

char* mystrchr(char* str, const char symbol) {
	for (; 
		*str != '\0' && *str != symbol; 
		str++
	);

	return *str == '\0' ? nullptr : str;
}

char* mystrstr(char* str, const char* substr) {
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		bool is_found = true;
		for (size_t j = 0; substr[j] != 0; j++)
		{
			if (str[i + j] != substr[j]) {
				is_found = false;
				break;
			}
		}

		if (is_found) return str + i;
	}

	return nullptr;
}

const char* random_word() {
	const size_t size = 9;
	const char const* dictionary[size]{
		"sport", "hobby", "motorcycle",
		"human", "authority", "process",
		"period", "cycle", "horror",
	};

	return dictionary[rand() % size];
}

void print_game(
	int lives,
	const char* guessed_word,
	const char* guessed_symbols
) {
	system("cls");
	std::cout << lives << "\n\n";
	std::cout << guessed_word << "\n\n";
	std::cout << guessed_symbols << "\n\n";
}

void update_guessed_word(
	const char* word, 
	char* guessed_word, 
	char symbol
) {
	size_t size = strlen(word);
	for (size_t i = 0; i < size; i++)
	{
		if (word[i] == symbol) {
			guessed_word[i] = symbol;
		}
	}
}

int main() {
	srand(time(0));
	int lives = 5;

	const char* word = random_word();
	const size_t word_size = strlen(word);

	char* guessed_symbols = new char[word_size + 1] {};

	char* guessed_word = new char[word_size + 1] {};
	for (size_t i = 0; i < word_size; i++)
	{
		guessed_word[i] = '_';
	}

	while (true) {
		print_game(lives, guessed_word, guessed_symbols);
		if (lives == 0 || strcmp(word, guessed_word) == 0) break;

		char input;
		std::cin >> input;

		if (strchr(word, input) && !strchr(guessed_symbols, input)) {
			update_guessed_word(word, guessed_word, input);

			size_t guessed_symbols_size = strlen(guessed_symbols);
			guessed_symbols[guessed_symbols_size] = input;
		}
		else {
			lives--;
		}
	}
}
