#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << RED << "Provide ONE argument\n" << RESET;
		return 1;
	}
	std::string input = argv[1];
	ScalarConverter::convert(input);


	// std::cout << '\n';
	// ScalarConverter::convert("0");
	// std::cout << '\n';
	// ScalarConverter::convert("nan");
	// std::cout << '\n';
	// ScalarConverter::convert("42.0f");
	// std::cout << '\n';

	// ScalarConverter::convert("]");
	// std::cout << '\n';
	// ScalarConverter::convert("-");
	// std::cout << '\n';
	// ScalarConverter::convert("a");
	// std::cout << '\n';
	// ScalarConverter::convert("42");
	// std::cout << '\n';
	// ScalarConverter::convert("-42");
	// std::cout << '\n';
	// ScalarConverter::convert("-42f");
	// std::cout << '\n';
	// ScalarConverter::convert("-42.0");
	// std::cout << '\n';
	// ScalarConverter::convert("+inf");
	// std::cout << '\n';
	// ScalarConverter::convert("-inf");
	// std::cout << '\n';
	// ScalarConverter::convert("+inff");
	// std::cout << '\n';
	// ScalarConverter::convert("-inff");
	// std::cout << '\n';
	// ScalarConverter::convert("nanf");
}
