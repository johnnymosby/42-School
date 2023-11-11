#include "PmergeMe.hpp"

void sort(std::vector<int> &vec_orig) {
	if (vec_orig.size() <= 1)
		return ;

	std::vector<int>::iterator begin = vec_orig.begin();
	std::vector<int>::iterator end = vec_orig.end();
	std::vector<int>::iterator middle = vec_orig.size() / 2 + begin;
	std::vector<int> left(begin, middle), right;
	int leftover;
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
	for (u_long i = 0; i < left.size(); i++) {
		std::vector<int>::iterator index_insert = std::lower_bound(result.begin(), result.end(), left[i]);
		result.insert(index_insert, left[i]);
	}
	if (vec_orig.size() % 2 != 0) {
		std::vector<int>::iterator index_insert = std::lower_bound(result.begin(), result.end(), leftover);
		result.insert(index_insert, leftover);
	}
	vec_orig = result;
}
