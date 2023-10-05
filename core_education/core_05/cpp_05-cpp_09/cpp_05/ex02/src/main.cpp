#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int n = 0;
	{
		std::cout << BOLDBLUE << "test " << n << ": ShrubberyCreationForm\n" << RESET;
		try
		{
			Bureaucrat bur("FirstShrubbery", 20);
			ShrubberyCreationForm form1("Shrubbery");
			form1.execute(bur);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		n++;
	}
}