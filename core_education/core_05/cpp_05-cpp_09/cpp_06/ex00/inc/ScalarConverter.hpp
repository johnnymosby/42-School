#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include "definitions.hpp"
# include <iomanip>

class ScalarConverter
{
	private:
		static bool isCharacter(const std::string &input);
		static bool isDisplayable(const std::string &input);
		static void printCharacter(const std::string &input);

		static bool isSpecialNumericValue(const std::string &input);
		static void printSpecialNumericValue(const std::string &input);
		static void printImpossible(void);
		static void printNumber(const std::string &input);

		static std::string trimWhitespace(const std::string& input);

	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &copy);
		~ScalarConverter();
		ScalarConverter &operator=(ScalarConverter const &other);

		static void convert(const std::string &input);
};

#endif