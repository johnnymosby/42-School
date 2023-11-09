#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <cmath>
# include <cctype>
# include <algorithm>
# include <iterator>
# include <iomanip>

const double EPSILON = 1e-9;
const std::string RED = "\033[31m";
const std::string RESET = "\033[0m";

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		void processFile(char const * input_file);
		void initialise(char const *input_pathname);

	private:
		bool isValidEntry(std::string data, std::string &date, double &value);
		bool isValidDate(std::string date);
		bool isValidLine(std::string &line, std::string &date, double &value);
		bool lineHasOnlyOneComma(std::string const &line);
		void exchange(const std::string & date, double value);

		std::map<std::string, double> database;
		bool isInitialised;
};

#endif