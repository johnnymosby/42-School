#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <set>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		void exchange(std::string entry);

	private:
		bool parseEntry(std::string entry);

		std::multiset<std::string, double> database;
};

#endif