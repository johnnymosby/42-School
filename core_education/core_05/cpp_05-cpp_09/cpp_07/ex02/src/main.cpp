#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750
#define RESET			"\033[0m"
#define RED			"\033[31m"

int test_on_main_from_subject() {
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

int main() {
	Array<int>arrayNoValues;

	unsigned int size = 4;
	int value;
	Array<int>arrayWithValues(size);
	for (unsigned int i = 0; i < size; i++) {
		value = rand();
		std::cout << "Element " << i << ": " << value << "\n";
		arrayWithValues[i] = value;
	}
	std::cout << '\n';
	try {
		std::cout << RED << "Trying to access out of bounds (too big index)\n" << RESET;
		std::cout << arrayWithValues[size] << "\n";
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	std::cout << '\n';
	try {
		std::cout << RED << "Trying to access out of bounds (too small index)\n" << RESET;
		std::cout << arrayWithValues[-1] << "\n";
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	std::cout << '\n';

	Array<int>copiedArray(arrayWithValues);
	for (unsigned int i = 0; i < arrayWithValues.size(); i++) {
		std::cout << "Element " << i << ": " << copiedArray[i] << "\n";
	}
	std::cout << '\n';

	copiedArray[2] = 0;
	std::cout << "Testing if changing one array changes another:\n"
				<< "copiedArray[2]: " << copiedArray[2]
				<< "\nArrayWithValues[2] " << arrayWithValues[2] << "\n\n";
	std::cout << '\n';

	copiedArray = arrayWithValues;
	for (unsigned int i = 0; i < arrayWithValues.size(); i++) {
		std::cout << "Element " << i << ": " << copiedArray[i] << "\n";
	}
	std::cout << '\n';


	copiedArray[2] = 0;
	std::cout << "Testing if changing one array changes another:\n"
				<< "copiedArray[2]: " << copiedArray[2]
				<< "\nArrayWithValues[2] " << arrayWithValues[2] << "\n\n";
	std::cout << '\n';

	std::cout << "Test from the main.cpp included in subject. Throws two exceptions:\n\n";
	test_on_main_from_subject();

	return 0;
}
