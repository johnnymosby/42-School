#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): isInitialised(false) {}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::initialise(char const *pathname) {
	std::ifstream file;
	file.open(pathname);
	if (!file.is_open()) {
		std::cout << "Error: Failed to open the file\n";
		return ;
	} else {
		isInitialised = true;
	}

	std::string line;
	getline(file, line);
	if (line != "date,exchange_rate") {
		std::cout << "Error: wrong columns in data file\n";
		file.close();
		return ;
	}

	std::string date;
	double value;
	while (getline(file, line)) {
		if (!file.eof()) {
			if (!isValidLine(line, date, value))
				continue ;
			database[date] = value;
		}
	}
	file.close();
}

void BitcoinExchange::exchange(char const * input_file) {
	if (isInitialised == false) {
		std::cout << "Error: BitcoinExchange was not initialised\n";
		return ;
	}


	t_entry entry;
	if (parseEntry(data, entry) == false) {
		std::cerr << "Error!\n";
		return ;
	}
}

bool BitcoinExchange::parseEntry(std::string data, t_entry &entry) {
	std::istringstream estream(data);
	estream >> entry.date >> entry.pipe >> entry.value;
	if (estream.fail() || !estream.eof()
		|| (entry.value < 0 || entry.value > 1000)
		|| (fabs(entry.value) < EPSILON || fabs(entry.value - 1000) < EPSILON))
		return false;

	if (isValidDate(entry.date) == false)
		return false;
	return true;
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

	if (estream.fail() || !estream.eof()
		|| sep[0] != '-' || sep[1] != '-'
		|| year < 1
		|| (month < 1 || month > 12)
		|| (day < 1 || day > 31)
		|| (month == 2 && day == 30))
		return false;
	if ((month >= 8 && month % 2 == 1 && day == 31)
		|| (month <= 7 && month % 2 == 0 && day == 31))
		return false;
	if (month == 2
		&& ((year % 400 != 0 && year % 100 == 0) || year % 4 != 0)
		&& day == 29)
		return false;

	return true;
}

bool BitcoinExchange::isValidLine(std::string &line, std::string &date, double &value) {
	if (lineHasOnlyOneComma(line) == false)
		return false;

	std::string::iterator commaIter;
	commaIter = std::find(line.begin(), line.end(), ',');
	*commaIter = ' ';

	std::istringstream line_stream(line);
	line_stream >> date >> value;
	if (line_stream.fail() || !line_stream.eof())
		return false;
	if (!isValidDate(date) || (value < 0 || value > 1000))
		return false;
	return true;
}

bool BitcoinExchange::lineHasOnlyOneComma(std::string const &line)
{
	std::string::const_iterator first_comma;
	std::string::const_iterator second_comma;

	first_comma = std::find(line.begin(), line.end(), ',');
	if (first_comma == line.end())
		return false;
	second_comma = first_comma;
	second_comma++;
	second_comma = std::find(second_comma, line.end(), ',');
	if (second_comma == line.end())
		return false;
	return true;
}
