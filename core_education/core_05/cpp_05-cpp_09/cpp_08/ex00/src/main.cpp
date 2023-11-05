#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main() {
	int index;
	int value;

	std::vector<int> container_0;
	for (int i = 0; i < 20; i++) {
		container_0.push_back(i);
	}
	try
	{
		value = -10;
		index = easyfind(container_0, value);
		std::cout << "The position of value " << value << " is " << index << "\n";
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		value = 10;
		index = easyfind(container_0, value);
		std::cout << "The position of value " << value << " is " << index << "\n";
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}