#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

#include <iostream>

template <class T>
void swap(T &a, T &b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <class T>
T &min(T &a, T &b) {
	return a > b ? b : a;
}

template <class T>
T &max(T &a, T&b) {
	return a > b ? a : b;
}

#endif