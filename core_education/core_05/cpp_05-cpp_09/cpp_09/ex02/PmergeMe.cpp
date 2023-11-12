#include "PmergeMe.hpp"

const int INDEX_BIGGEST_TYPE_INT_JACOBSTHAL_NUMBER = 33;

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

int binary_search(std::vector <int> const &vec, int target) {
	int low = 0;
	int high = vec.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (vec[mid] == target) {
			return mid;
		} else if (vec[mid] < target) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return low;
}

void sort(std::vector<int> &vec_orig) {
	if (vec_orig.size() <= 1)
		return ;

	std::vector<int>::iterator begin = vec_orig.begin();
	std::vector<int>::iterator end = vec_orig.end();
	std::vector<int>::iterator middle = vec_orig.size() / 2 + begin;
	std::vector<int> left(begin, middle), right;
	int leftover = 0;
	if (vec_orig.size() % 2 != 0) {
		end--;
		leftover = *(end);
	}
	right = std::vector<int>(middle, end);
	for (u_long i = 0; i < (vec_orig.size() / 2); i++) {
		if (left[i] > right[i])
			std::swap(left[i], right[i]);
	}
	std::vector<int> old_right = right;
	sort(right.begin(), right.end());
	std::vector<int> old_left = left;
	for (u_long i = 0; i < right.size(); i++) {
		std::vector<int>::iterator it = std::find(old_right.begin(), old_right.end(), right[i]);
		if (it != old_right.end()) {
			int index = std::distance(old_right.begin(), it);
			left[i] = old_left[index];
		}
	}
	std::vector<int> result = right;
	if (leftover != 0) {
		left.push_back(leftover);
	}
	result.insert(result.begin(), left[0]);
	if (left.begin() + 1 != left.end())
		result.insert(result.begin() + binary_search(result, left[1]), left[1]);
	std::vector<int> const & jacobsthal_numbers = getJacobsthalNumbers();
	int index;
	for (int i = 2; i <= binary_search(jacobsthal_numbers, left.size() - 1); i++) {
		if ((static_cast<int>(left.size()) - 1) < jacobsthal_numbers[i]) {
			index = static_cast<int>(left.size()) - 1;
		} else {
			index = jacobsthal_numbers[i];
		}
		while (index != jacobsthal_numbers[i - 1]) {
			result.insert(result.begin() + binary_search(result, left[index]), left[index]);
			index--;
		}
	}
	vec_orig = result;
}
