#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <set>
# include <utility>
# include <string>
# include <iostream>
# include <cstdlib>
# include <cctype>
# include <algorithm>
# include <ctime>
# include <iomanip>

const int INDEX_BIGGEST_TYPE_INT_JACOBSTHAL_NUMBER = 33;

const std::vector<int>& getJacobsthalNumbers();

template <class T>
int binary_search(T const &vec, int target) {
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

template <class T>
void sort(T &vec_orig) {
	if (vec_orig.size() <= 1)
		return ;

	typename T::iterator begin(vec_orig.begin()), end(vec_orig.end());
	typename T::iterator middle = vec_orig.size() / 2 + begin;
	T left(begin, middle), right;
	int leftover = 0;
	if (vec_orig.size() % 2 != 0) {
		end--;
		leftover = *(end);
	}
	right = T(middle, end);
	for (u_long i = 0; i < (vec_orig.size() / 2); i++) {
		if (left[i] > right[i])
			std::swap(left[i], right[i]);
	}
	T old_right = right;
	sort(right);
	T old_left = left;
	for (u_long i = 0; i < right.size(); i++) {
		typename T::iterator it = std::find(old_right.begin(), old_right.end(), right[i]);
		if (it != old_right.end()) {
			int index = std::distance(old_right.begin(), it);
			left[i] = old_left[index];
		}
	}
	T result = right;
	if (leftover != 0) {
		left.push_back(leftover);
	}
	result.insert(result.begin(), left[0]);
	std::vector<int> const & jacobsthal_numbers = getJacobsthalNumbers();
	int index;
	T search_range;
	for (int i = 1; i <= binary_search(jacobsthal_numbers, left.size() - 1); i++) {
		if ((static_cast<int>(left.size()) - 1) < jacobsthal_numbers[i]) {
			index = static_cast<int>(left.size()) - 1;
		} else {
			index = jacobsthal_numbers[i];
		}
		while (index != jacobsthal_numbers[i - 1]) {
			search_range = T(result.begin(), std::find(result.begin(), result.end(), right[index]) + 1);
			result.insert(result.begin() + binary_search(result, left[index]), left[index]);
			index--;
		}
	}
	vec_orig = result;
}

#endif
