#include "PmergeMe.hpp"

const std::vector<int>& getJacobsthalNumbers() {
	static std::vector<int> jacobsthalNumbers;

	if (jacobsthalNumbers.empty()) {
		jacobsthalNumbers.push_back(0);
		jacobsthalNumbers.push_back(1);

		for (int i = 2; i < INDEX_BIGGEST_TYPE_INT_JACOBSTHAL_NUMBER; i++) {
			jacobsthalNumbers.push_back(jacobsthalNumbers[i - 1] + 2 * jacobsthalNumbers[i - 2]);
		}
	}

	return jacobsthalNumbers;
}
