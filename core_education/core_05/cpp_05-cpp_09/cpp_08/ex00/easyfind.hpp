#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>
#include <iterator>
#include <list>
#include <deque>
#include <algorithm>

class notFoundException: public std::exception {
	public:
		const char * what() const throw() {
			return "The value was not found";
		}
};

template<class T>
int easyfind(T &container, int target) {
	typename T::iterator iter;
	iter = std::find(container.begin(), container.end(), target);
	if (iter != container.end())
		return std::distance(container.begin(), iter);
	else
		throw notFoundException();
}

#endif