#include "PmergeMe.hpp"

static bool stringHasOnlyDigits(char const *arg) {
	while (*arg != '\0') {
		if (!isdigit(*arg))
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
			vec.push_back(std::stoi(*argv));
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
	}
	else return 0;
}

int main(int argc, char **argv) {
	std::vector<int> vec;
	if (parseInput(argc, argv, vec) == 1)
		return 1;
}
