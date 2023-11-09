#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2 || argv[1][0] == '\0') {
		std::cout << "Error: could not open file.\n";
		return 1;
	}

	BitcoinExchange exchanger;
	exchanger.initialise("data.csv");
	exchanger.processFile(argv[1]);
	return 0;
}
