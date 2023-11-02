#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <class T>
void iter(T *address, size_t len, void(*func)(T const &)) {
	if (len < 0) {
		std::cout << "Length cannot be lower than 0\n";
		return ;
	}
	for (size_t i = 0; i < len; i++) {
		func(address[i]);
	}
}

#endif