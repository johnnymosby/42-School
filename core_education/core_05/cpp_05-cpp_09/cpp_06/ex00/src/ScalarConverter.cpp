#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &cpy) { *this = cpy; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
	if (this != &other) *this = other;
	return *this;
}

void ScalarConverter::convert(const std::string &input) {
	printCharacter(input);
}

void ScalarConverter::printCharacter(const std::string &input) {
	std::cout << "char: ";
	if (isCharacter(input) == false) {
		std::cout << "impossible";
	} else if (isDisplayable(input) == false) {
		std::cout << "Non displayable";
	} else {
		std::cout << input[0];
	}
	std::cout << "\n";
}

bool ScalarConverter::isCharacter(const std::string &input) {
	if (input.length() > 1) {
		return false;
	}
	else {
		return true;
	}
}

bool ScalarConverter::isDisplayable(const std::string &input) {
	return std::isalpha(input[0]);
}
