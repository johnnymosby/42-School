#include "PmergeMe.hpp"

static bool stringHasOnlyDigits(char const *arg) {
	while (*arg != '\0') {
		if (isdigit(*arg) == false)
			return false;
		arg++;
	}
	return true;
}

static bool inputHasOnlyDigits(char const * const *argv) {
	while (*argv != NULL) {
		if (!stringHasOnlyDigits(*argv))
			return false;
		argv++;
	}
	return true;
}

static bool fillVector(std::vector<int> &vec, char const * const *argv) {
	while (*argv != NULL) {
		try {
			vec.push_back(std::atoi(*argv));
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << ": " << *argv << "\n";
			return false;
		}
		argv++;
	}
	return true;
}

static bool hasDuplicates(std::vector<int> const &vec) {
	std::set<int> s(vec.begin(), vec.end());
	return s.size() != vec.size();
}

static int parseInput(int argc, char const * const *argv, std::vector<int> &vec) {
	argv++;
	if (argc == 1) {
		std::cerr << "Error: no input\n";
		return 1;
	} else if (!inputHasOnlyDigits(argv)) {
		std::cerr << "Error: non-digit values\n";
		return 1;
	}

	if (fillVector(vec, argv) == false) {
		return 1;
	} else if (hasDuplicates(vec)) {
		std::cerr << "Error: duplicates in the input\n";
		return 1;
	} else if (std::find(vec.begin(), vec.end(), 0) != vec.end()) {
		std::cerr << "Error: 0 in the input\n";
		return 1;
	} 
	else
		return 0;
}

static void printResponse(std::vector<int> vec_old, std::vector<int> vec_new) {
	std::cout << "Before: ";
	for (u_long i = 0; i < vec_old.size(); i++)
		std::cout << vec_old[i] << " ";
	std::cout << "\n";
	std::cout << "After:  ";
	for (u_long i = 0; i < vec_new.size(); i++)
		std::cout << vec_new[i] << " ";
	std::cout << "\n";
}


int main(int argc, char **argv) {
	clock_t beginning, end, parsing_start;
	double vec_time, deque_time, vec_parsing, deque_parsing;

	std::cout << std::fixed << std::setprecision(5);

	parsing_start = clock();
	std::vector<int> vec_old;
	if (parseInput(argc, argv, vec_old) == 1)
		return 1;
	std::vector<int> vec_new = vec_old;

	beginning = clock();
	sort(vec_new);
	end = clock();

	vec_parsing = difftime(beginning, parsing_start);
	vec_time = difftime(end, beginning);

	parsing_start = clock();
	std::deque<int> deque(vec_old.begin(), vec_old.end());
	beginning = clock();
	sort(deque);
	end = clock();
	deque_time = difftime(end, beginning);
	deque_parsing = difftime(beginning, parsing_start);
	printResponse(vec_old, vec_new);
	std::cout << "Vector of size " << vec_old.size() << ": " << vec_time << " us\n";
	std::cout << "Deque of size " << deque.size() << ":  " << deque_time << " us\n";
	std::cout << "Vector of size " << vec_old.size() << ": " << vec_time + vec_parsing << " us (time with data management)\n";
	std::cout << "Deque of size " << deque.size() << ":  " << deque_parsing + deque_time << " us (time with data management)\n";
	return 0;
}
