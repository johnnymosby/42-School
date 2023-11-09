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

const double EPSILON = 1e-9;
const std::string RED = "\033[31m";
const std::string RESET = "\033[0m";

typedef struct s_entry
{
	std::string	date;
	char		pipe;
	double		value;
}	t_entry;

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		void exchange(char const * input_file);
		void initialise(char const *pathname);

	private:
		bool parseEntry(std::string data, t_entry &entry);
		bool isValidDate(std::string date);
		bool isValidLine(std::string &line, std::string &date, double &value);
		bool lineHasOnlyOneComma(std::string const &line);

		std::map<std::string, double> database;
		bool isInitialised;
};

#endif