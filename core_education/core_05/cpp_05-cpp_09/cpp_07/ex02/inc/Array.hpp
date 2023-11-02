#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <class T>
class Array {
	public:
		Array(): size_(0), data_(NULL) {}
		Array(unsigned int size): size_(size), data_(new T[size]) {}
		Array(Array &copy): size_(copy.size_), data_(new T[copy.size_]) {
			for (unsigned int i = 0; i < size_; i++) {
				data_[i] = copy.data_[i];
			}
		}

	private:
		T				*data_;
		unsigned int	size_;
};

#endif