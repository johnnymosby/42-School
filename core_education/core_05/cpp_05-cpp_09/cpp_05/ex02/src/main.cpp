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
		std::cout << BOLDBLUE << "test " << n << ": ShrubberyCreationForm not signed\n" << RESET;
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

	{
		std::cout << BOLDBLUE << "test " << n << ": ShrubberyCreationForm signed\n" << RESET;
		try
		{
			Bureaucrat bur("FirstShrubbery", 20);
			ShrubberyCreationForm form1("Shrubbery");
			form1.beSigned(bur);
			form1.execute(bur);
			std::cout << form1 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		n++;
	}

	{
		std::cout << BOLDBLUE << "test " << n << ": ShrubberyCreationForm not signed because grade is too low\n" << RESET;
		try
		{
			Bureaucrat bur("FirstShrubbery", 140);
			ShrubberyCreationForm form1("Shrubbery");
			form1.beSigned(bur);
			form1.execute(bur);
			std::cout << form1 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		n++;
	}

	/* ---------------------------------------------------------------------------------------- */
	{
		std::cout << BOLDBLUE << "test " << n << ": RobotomyRequestForm not signed\n" << RESET;
		try
		{
			Bureaucrat bur("Bobby", 20);
			RobotomyRequestForm form1("Request");
			form1.execute(bur);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		n++;
	}

	{
		std::cout << BOLDBLUE << "test " << n << ": RobotomyRequestForm signed with 50 percent chance\n" << RESET;
		try
		{
			Bureaucrat bur("Bobby", 20);
			RobotomyRequestForm form1("Request");
			form1.beSigned(bur);
			form1.execute(bur);
			std::cout << form1 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		n++;
	}

	{
		std::cout << BOLDBLUE << "test " << n << ": RobotomyRequestForm not signed because grade is too low\n" << RESET;
		try
		{
			Bureaucrat bur("Bobby", 140);
			RobotomyRequestForm form1("Request");
			form1.beSigned(bur);
			form1.execute(bur);
			std::cout << form1 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		n++;
	}

	/* ---------------------------------------------------------------------------------------- */
	{
		std::cout << BOLDBLUE << "test " << n << ": PresidentialPardonForm not signed\n" << RESET;
		try
		{
			Bureaucrat bur("President", 20);
			PresidentialPardonForm form1("Pardon");
			form1.execute(bur);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		n++;
	}

	{
		std::cout << BOLDBLUE << "test " << n << ": PresidentialPardonForm signed\n" << RESET;
		try
		{
			Bureaucrat bur("President", 20);
			PresidentialPardonForm form1("Pardon");
			form1.beSigned(bur);
			form1.execute(bur);
			std::cout << form1 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		n++;
	}

	{
		std::cout << BOLDBLUE << "test " << n << ": PresidentialPardonForm not signed because grade is too low\n" << RESET;
		try
		{
			Bureaucrat bur("President", 140);
			PresidentialPardonForm form1("Pardon");
			form1.beSigned(bur);
			form1.execute(bur);
			std::cout << form1 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		n++;
	}
}
