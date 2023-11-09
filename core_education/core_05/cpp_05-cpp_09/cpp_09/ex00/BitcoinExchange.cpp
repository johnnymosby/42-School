#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): isInitialised(false) {}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::initialise(char const *pathname) {
	std::ifstream file;
	file.open(pathname);
	if (!file.is_open()) {
		std::cerr << RED << "Error: Failed to open the file\n" << RESET;
		return ;
	} else {
		isInitialised = true;
	}

	std::string line;
	getline(file, line);
	if (line != "date,exchange_rate") {
		std::cerr << RED << "Error: wrong columns in data file\n" << RESET;
		file.close();
		return ;
	}

	std::string date;
	double value;
	while (getline(file, line)) {
		if (!line.empty()) {
			if (isValidLine(line, date, value))
				database[date] = value;
		}
	}
	
	file.close();
}

void BitcoinExchange::processFile(char const * input_pathname) {
	if (isInitialised == false) {
		std::cerr << RED << "Error: BitcoinExchange was not initialised\n" << RESET;
		return ;
	}

	if (database.begin() == database.end()) {
		std::cerr << RED << "Error: database is empty\n" << RESET;
		return ;
	}

	std::ifstream file_input(input_pathname);
	if (!file_input.is_open()) {
		std::cerr << RED << "Error: could not open file\n" << RESET;
		return ;
	}

	std::string line;
	std::string date;
	double value;
	// std::cout << std::fixed << std::setprecision(3);
	getline(file_input, line);
	if (!file_input.eof()) {
		if (line != "date | value" && isValidEntry(line, date, value))
			exchange(date, value);
	}
	while (getline(file_input, line)) {
		if (!line.empty()) {
			if (isValidEntry(line, date, value))
				exchange(date, value);
		}
	}
}

void BitcoinExchange::exchange(const std::string & date, double value) {
	std::map<std::string, double>::const_iterator iter;
	iter = database.find(date);

	if (iter == database.end()) {
		iter = database.lower_bound(date);
		if (iter != database.begin()) {
			iter--;
		}
	}
	if (fabs(fabs(value) - std::numeric_limits<double>::max() / fabs(iter->second)) < EPSILON) {
		std::cerr << RED << "Error: overflow\n" << RESET;
		return ;
	}
	std::cout << date << " | " << std::left << std::setw(10) << formatDouble(value);
	std::cout << " =>  " << iter->first << " | " << std::setw(16) << formatDouble(iter->second);
	std::cout << " :   " << std::setw(16) << formatDouble(value * iter->second);
	std::cout << "\n";
}

std::string BitcoinExchange::formatDouble(double n) {
	std::ostringstream os;
	os << std::fixed << std::setprecision(3) << n;
	std::string formatted_double = os.str();

	formatted_double = formatted_double.substr(0, formatted_double.find('.') + 4);
	std::string::iterator iter = std::find(formatted_double.begin(), formatted_double.end(), '.');
	if (iter == formatted_double.end())
		return formatted_double;
	std::string::iterator riter = formatted_double.end();
	riter--;
	while (formatted_double.begin() != riter) {
		if (*riter == '0')
			*riter = '\0';
		else if (*riter == '.') {
			*riter = '\0';
			break ;
		}
		else
			break ;
		riter--;
	}
	return formatted_double.c_str();
}

bool BitcoinExchange::isValidEntry(std::string data, std::string &date, double &value) {
	std::istringstream estream(data);
	char pipe;

	estream >> date >> pipe >> value;
	if (estream.fail() || !estream.eof()) {
		std::cerr << RED << "Error: bad input => " << data << "\n" << RESET;
		return false;
	}
	if ((value < 0 || value > 1000)
		|| (fabs(value) < EPSILON || fabs(value - 1000) < EPSILON)) {
		std::cerr << RED << "Error: value is not between 0 and 1000 " << data << "\n" << RESET;
		return false;
	}

	if (isValidDate(date) == false)
		return false;
	return true;
}

bool BitcoinExchange::isValidDate(std::string date) {
	if (date.size() != 10 || date[4] != '-' | date[7] != '-') {
		std::cerr << RED << "Error: bad date => " << date << "\n" << RESET;
		return false;
	}

	std::istringstream estream(date);
	int year;
	int month;
	int day;
	char sep[2];

	estream >> year >> sep[0] >> month >> sep[1] >> day;

	if (estream.fail() || !estream.eof()) {
		std::cerr << RED << "Error: bad date => " << date << "\n" << RESET;
		return false;
	}
	if (sep[0] != '-' || sep[1] != '-'
		|| year < 1
		|| (month < 1 || month > 12)
		|| (day < 1 || day > 31)
		|| (month == 2 && day == 30)) {
		std::cerr << RED << "Error: bad date => " << date << "\n" << RESET;
		return false;
	}
	if ((month >= 8 && month % 2 == 1 && day == 31)
		|| (month <= 7 && month % 2 == 0 && day == 31)) {
		std::cerr << RED << "Error: bad date => " << date << "\n" << RESET;
		return false;
	}
	if (month == 2
		&& ((year % 400 != 0 && year % 100 == 0) || year % 4 != 0)
		&& day == 29) {
		std::cerr << RED << "Error: bad date => " << date << ": February 29 is not part of the year\n" << RESET;
		return false;
	}

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
	if (line_stream.fail() || !line_stream.eof()) {
		std::cerr << RED << "Error\n" << RESET;
		return false;
	}
	if (!isValidDate(date))
		return false;
	return true;
}

bool BitcoinExchange::lineHasOnlyOneComma(std::string const &line)
{
	std::string::const_iterator first_comma;
	std::string::const_iterator second_comma;

	first_comma = std::find(line.begin(), line.end(), ',');
	if (first_comma == line.end()) {
		std::cerr << RED << "Error: no comma in a line from data file\n" << RESET;
		return false;
	}
	second_comma = first_comma;
	second_comma++;
	second_comma = std::find(second_comma, line.end(), ',');
	if (second_comma != line.end()) {
		std::cerr << RED << "Error: second comma in a line from data file\n" << RESET;
		return false;
	}
	return true;
}
