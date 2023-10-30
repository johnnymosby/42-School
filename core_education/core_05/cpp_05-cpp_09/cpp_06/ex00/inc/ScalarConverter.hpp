#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
	private:
		static bool isCharacter(const std::string &input);
		static bool isDisplayable(const std::string &input);
		static void printCharacter(const std::string &input);
		static void printInteger(const std::string &input);
		static void printFloat(const std::string &input);
		static void printDouble(const std::string &input);

	public:
		ScalarConverter(void);
		~ScalarConverter();
		ScalarConverter &operator=(ScalarConverter const &other);

		static void convert(const std::string &input);
};

#endif