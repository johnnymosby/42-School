#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return false;
	std::string input = argv[1];
	ScalarConverter::convert(input);
}
