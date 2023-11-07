#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <cmath>
# include <cctype>

const double EPSILON = 1e-9;
const std::string RED = "\033[31m";
const std::string RESET = "\033[0m";

typedef struct
{
	std::string	date;
	char		pipe;
	double		value;
}	pentry;

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		void exchange(std::string data);
		void initialise(std::string pathname);

	private:
		bool parseEntry(std::string data, pentry &entry);
		bool isValidDate(std::string date);
		bool isValidLine(std::string &line);

		std::map<std::string, double> database;
		bool isInitialised;
};

#endif