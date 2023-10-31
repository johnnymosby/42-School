#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &copy) {*this = copy;}
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
	if (this != &other) {
		*this = other;
	}
	return *this;
}

std::string ScalarConverter::trimWhitespace(const std::string& input) {
	size_t start = input.find_first_not_of(" \t\n\r");
	size_t end = input.find_last_not_of(" \t\n\r");

	if (start == std::string::npos)
		return "";

	return input.substr(start, end - start + 1);
}

void ScalarConverter::convert(const std::string &input) {
	std::string	trimmedInput = trimWhitespace(input);

	if (isSpecialNumericValue(trimmedInput)) {
		printSpecialNumericValue(trimmedInput);
	}
	else if (isCharacter(trimmedInput)) {
		printCharacter(trimmedInput);
	} else {
		printNumber(trimmedInput);
	}
}

void ScalarConverter::printSpecialNumericValue(const std::string &input) {
	int 		len = input.size();
	std::string	input_no_f = input;

	if (input == "+inff" || input == "-inff" || input == "nanf") {
		input_no_f.erase(len - 1);
	}

	std::cout << "char: impossible\n"
				<< "int: impossible\n"
				<< "float: " << input_no_f << "f\n"
				<< "double: " << input_no_f << '\n';
}

bool ScalarConverter::isSpecialNumericValue(const std::string &input) {
	if (input == "+inf" || input == "-inf" || input == "nan" ||
		input == "+inff" || input == "-inff" || input == "nanf")
		return true;
	else
		return false;
}

void ScalarConverter::printImpossible(void) {
	std::cout << "char: impossible\n"
		<< "int: impossible\n"
		<< "float: impossible\n"
		<< "double: impossible\n";
}

void ScalarConverter::printCharacter(const std::string &input) {
	double num;

	std::cout << "char: ";
	if (isDisplayable(input) == false) {
		std::cout << "Non displayable";
	} else {
		std::cout << input[0];
	}
	std::cout << "\n";

	if (isdigit(input[0])) {
		num = input[0] - '0';
	} else {
		num = static_cast<double>(input[0]);
	}
	std::cout << "int: " << static_cast<int>(num) << '\n';
	std::cout << std::fixed << "float: " << std::setprecision(1) << static_cast<float>(num) << "f\n";
	std::cout << std::fixed << "double: " << std::setprecision(1) << num << '\n';
}

void ScalarConverter::printNumber(const std::string &input) {
	int 				len = input.size();
	std::string			input_no_f = input;

	if (input_no_f[len - 1] == 'f') {
		input_no_f = input_no_f.substr(0, len - 1);
	}

	std::istringstream	input_stream(input_no_f);
	double				num;

	input_stream >> num;
	if (input_stream.fail() || !input_stream.eof()) {
		printImpossible();
	} else {
		std::cout << "char: impossible\n"
					<< "int: " << static_cast<int>(num) << '\n'
					<< "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f\n"
					<< "double: " << std::fixed << std::setprecision(1) << num << '\n';
	}
}

bool ScalarConverter::isCharacter(const std::string &input) {
	return (input.length() < 2);
}

bool ScalarConverter::isDisplayable(const std::string &input) {
	return std::isprint(input[0]) && !std::isdigit(input[0]);
}
