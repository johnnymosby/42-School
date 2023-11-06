#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <vector>
# include <algorithm>
# include <iterator>

class Span {
	public:
		Span(u_int size = 0);
		Span(const Span &copy);
		~Span();

		Span &operator=(const Span &other);
		void addNumber(int num);
		void addVector(const std::vector <int> &vec);
		int shortestSpan(void);
		int longestSpan(void);

		class noSpaceLeft: public std::exception {
			public:
				const char * what() const throw();
		};
		class noSpaceForSecondVector: public std::exception {
			public:
				const char * what() const throw();
		};
		class noSpanFound: public std::exception {
			public:
				const char * what() const throw();
		};

	private:
		std::vector<int> data_;
		u_int	size_;
		u_int	maxSize_;
};

#endif