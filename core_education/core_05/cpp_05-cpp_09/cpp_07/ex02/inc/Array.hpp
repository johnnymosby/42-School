#ifndef ARRAY_HPP
# define ARRAY_HPP

template <class T>
class Array {
	public:
		Array() {
			size_ = 0;
			data_ = NULL;
		}
		Array(unsigned int size) {
			size_ = size;
			data_ = new T[size];
		}
		Array(const Array &copy) {
			size_ = copy.size_;
			data_ = new T[copy.size_];
			for (unsigned int i = 0; i < size_; i++) {
				data_[i] = copy.data_[i];
			}
		}

		~Array() {
			delete [] data_;
		}

		Array & operator=(const Array &other) {
			if (this != &other) {
				delete [] data_;
				size_ = other.size_;
				data_ = new T[size_];
				for (unsigned int i = 0; i < size_; i++) {
					data_[i] = other.data_[i];
				}
			}
			return (*this);
		}

		T const & operator[] (unsigned int ind) const {
			if (ind < size_)
				return data_[ind];
			throw IndexIsOutOfBoundsException();
		}

		T & operator[] (unsigned int ind) {
			if (ind < size_)
				return data_[ind];
			throw IndexIsOutOfBoundsException();
		}

		class IndexIsOutOfBoundsException: public std::exception {
			public:
				char const * what() const throw() {
					return "Error: Index is out of bounds!\n";
				}
		};

		unsigned int size(void) const {
			return size_;
		}

	private:
		T				*data_;
		unsigned int	size_;
};

#endif