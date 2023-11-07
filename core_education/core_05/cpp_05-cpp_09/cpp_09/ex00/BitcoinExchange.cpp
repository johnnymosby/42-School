#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): isInitialised(false) {}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::initialise(std::string pathname) {
	std::ifstream file;
	std::string line;

	file.open(pathname);
	if (!file.is_open()) {
		std::cout << "Error: Failed to open the file\n";
		return ;
	}
	isInitialised = true;
	getline(file, line);
	if (line != "date,exchange_rate") {
		std::cout << "Error: wrong columns\n";
		file.close();
		return ;
	}
	while (getline(file, line)) {
		if (!file.eof()) {
			if (!isValidLine(line))
				continue ;
		}
	}
}

void BitcoinExchange::exchange(std::string data) {
	pentry entry;

	if (isInitialised == false) {
		std::cout << "Error: BitcoinExchange was not initialised\n";
		return ;
	}

	if (parseEntry(data, entry) == false) {
		std::cerr << "Error!\n";
		return ;
	}
}

bool BitcoinExchange::parseEntry(std::string data, pentry &entry) {
	std::istringstream estream(data);

	estream >> entry.date >> entry.pipe >> entry.value;
	if (estream.fail() || estream.eof()
		|| (entry.value < 0 || entry.value > 1000)
		|| (fabs(entry.value) < EPSILON || fabs(entry.value - 1000) < EPSILON))
		return false;
	if (isValidDate(entry.date) == false)
		return false;
}

bool BitcoinExchange::isValidDate(std::string date) {
	if (date.size() != 10 || date[4] != '-' | date[7] != '-')
		return false;

	std::istringstream estream(date);
	int year;
	int month;
	int day;
	char sep[2];

	estream >> year >> sep[0] >> month >> sep[1] >> day;
	if (estream.fail() || estream.eof()
		|| sep[0] != '-' || sep[1] != '-'
		|| year < 1
		|| (month < 1 || month > 12)
		|| (day < 1 || day > 31)
		|| (month == 2 && day == 30))
		return false;
	if (month >= 8 && month % 2 == 1 && day == 31
		|| month <= 7 && month % 2 == 0 && day == 31)
		return false;
	if (month == 2
		&& (year % 400 != 0 && year % 100 == 0 || year % 4 != 0)
		&& day == 29)
		return false;
	return true;
}

bool BitcoinExchange::isValidLine(std::string &line) {
	bool comma_was_met = 0;
	bool displayable_char_was_met = false;

	for (std::string::iterator iter = line.begin(); iter != line.end(); iter++) {
		if (!std::isspace(*iter))
			displayable_char_was_met = true;
		if (*iter == ',') {
			if (comma_was_met != false)
				return false;
			comma_was_met = true;
			
		}
	}
}
