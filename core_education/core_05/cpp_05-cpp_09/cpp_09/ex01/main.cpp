#include "RPN.hpp"

static std::string formatDouble(double n) {
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

static bool RPN(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: wrong number of arguments\n";
		return 1;
	}

	if (isValidInput(argv[1]) == false) {
		std::cerr << "Error: wrong input\n";
		return 1;
	}
	double answer;
	if (calculate(argv[1], answer) == false) {
		std::cerr << "Error: wrong input\n";
		return 1;
	} else {
		std::cout << formatDouble(answer) << "\n";
		return 0;
	}
}



int main(int argc, char **argv) {
	try {
		return RPN(argc, argv);
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << "\n";
		return 1;
	}
}
