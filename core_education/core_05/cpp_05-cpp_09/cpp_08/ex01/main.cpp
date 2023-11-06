#include "Span.hpp"
#include <iostream>

int main() {
	std::cout << "subject test:\n";
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		
		try {
			sp.addNumber(42);
		} catch (std::exception &e) {
			std::cout << e.what() << "\n";
		}
		std::cout << "\n";
	}


	std::cout << "empty span test:\n";
	{
		Span emptySpan = Span();
		try {
			emptySpan.addNumber(42);
		} catch (std::exception &e) {
			std::cout << e.what() << "\n";
		}
		try {
			emptySpan.shortestSpan();
		} catch (std::exception &e) {
			std::cout << e.what() << "\n";
		}
		try {
			emptySpan.longestSpan();
		} catch (std::exception &e) {
			std::cout << e.what() << "\n";
		}
		std::cout << "\n";
	}


	std::cout << "20k numbers test\n";
	{
		Span twenty_k_values = Span(20000);
		std::vector<int>first_half(10000, 21);
		std::vector<int>second_half(10000, 42);
		twenty_k_values.addVector(first_half);
		twenty_k_values.addVector(second_half);
		try {
			twenty_k_values.addNumber(42);
		} catch (std::exception &e) {
			std::cout << e.what() << "\n";
		}
		std::cout << twenty_k_values.shortestSpan() << "\n"
					<< twenty_k_values.longestSpan() << "\n";
	}
	return 0;
}