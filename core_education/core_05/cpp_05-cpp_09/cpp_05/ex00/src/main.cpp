#include "Bureaucrat.hpp"
#include <stdlib.h>
#include <unistd.h>

void	catch_initialisation_error() {

}

int	main(void)
{
	int n = 0;
	{
		std::cout << BOLDBLUE << "test " << n << ": Initialisation with too low grade\n" << RESET;
		unsigned int grade = 151;
		try {
			Bureaucrat Bob(grade);
			std::cout << "Bob was created:  " << Bob << "\n";
		}
		catch (std::exception &e) {
			std::cout << "Bob was not created: ";
			std::cout << e.what();
		}
		std::cout << "\n";
		n++;
	}

	{
		std::cout << BOLDBLUE << "test " << n << ": Initialisation with too high grade\n" << RESET;
		unsigned int grade = 0;
		try {
			Bureaucrat Bob(grade);
			std::cout << "Bob was created:  " << Bob;
		}
		catch (std::exception &e) {
			std::cout << "Bob was not created: ";
			std::cout << e.what();
		}
		std::cout << "\n";
		n++;
	}


	{
		std::cout << BOLDBLUE << "test " << n << ": Initialisation with correct grade\n" << RESET;
		srand((unsigned) time(NULL) + n);
		unsigned int grade = rand() % 150 + 1;
		try {
			Bureaucrat Bob(grade);
			std::cout << "Bob was created: " << Bob;
		}
		catch (std::exception &e) {
			std::cout << "Bob was not created: ";
			std::cout << e.what();
		}
		std::cout << "\n";
		n++;
	}

	{
		std::cout << BOLDBLUE << "test " << n << ": Decrement to too low grade\n" << RESET;
		unsigned int grade = 150;
		try {
			Bureaucrat Bob(grade);
			Bob.decrementGrade();
			std::cout << "Bob was created and decremented: grade " << Bob;
		}
		catch (std::exception &e) {
			std::cout << "Bob was not decremented: ";
			std::cout << e.what();
		}
		std::cout << "\n";
		n++;
	}

	{
		std::cout << BOLDBLUE << "test " << n << ": Increment to too high grade\n" << RESET;
		unsigned int grade = 1;
		try {
			Bureaucrat Bob(grade);
			Bob.incrementGrade();
			std::cout << "Bob was created and incremented: " << Bob;
		}
		catch (std::exception &e) {
			std::cout << "Bob was not incremented: ";
			std::cout << e.what();
		}
		std::cout << "\n";
		n++;
	}

	{
		std::cout << BOLDBLUE << "test " << n << ": Correct decrement\n" << RESET;
		srand((unsigned) time(NULL) + n);
		unsigned int grade = rand() % 149 + 1;
		try {
			Bureaucrat Bob(grade);
			Bob.decrementGrade();
			std::cout << "Bob was created and decremented: " << Bob;
		}
		catch (std::exception &e) {
			std::cout << "Bob was not decremented: ";
			std::cout << e.what();
		}
		std::cout << "\n";
		n++;
	}

	{
		std::cout << BOLDBLUE << "test " << n << ": Correct increment\n" << RESET;
		srand((unsigned) time(NULL) + n);
		unsigned int grade = rand() % 149 + 2;
		try {
			Bureaucrat Bob(grade);
			Bob.incrementGrade();
			std::cout << "Bob was created and incremented: " << Bob;
		}
		catch (std::exception &e) {
			std::cout << "Bob was not incremented: ";
			std::cout << e.what();
		}
		std::cout << "\n";
		n++;
	}
}

