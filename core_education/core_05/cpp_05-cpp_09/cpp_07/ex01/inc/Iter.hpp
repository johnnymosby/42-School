#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <class T, class Func>
void iter(T *address, size_t len, Func func) {
	for (size_t i = 0; i < len; i++) {
		func(address[i]);
	}
}

#endif