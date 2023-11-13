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
	clock_t start_vec;
	clock_t end_vec;
	std::vector<int> vec_old;
	if (parseInput(argc, argv, vec_old) == 1)
		return 1;
	std::vector<int> vec_new = vec_old;
	start_vec = clock();
	sort(vec_new);
	end_vec = clock();
	std::cout << std::fixed << std::setprecision(5);
	printResponse(vec_old, vec_new);
	double time_vec = (double)(end_vec - start_vec) / CLOCKS_PER_SEC;
	std::cout << "Vector of size " << vec_old.size() << ": " << time_vec << " us\n";
	std::deque<int> deque(vec_old.begin(), vec_old.end());
	start_vec = clock();
	sort(deque);
	end_vec = clock();
	time_vec = (double)(end_vec - start_vec) / CLOCKS_PER_SEC;
	std::cout << "Deque of size " << deque.size() << ":  " << time_vec << " us\n";
	return 0;
}
