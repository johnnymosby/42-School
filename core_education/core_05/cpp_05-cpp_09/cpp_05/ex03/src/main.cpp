#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int n = 0;
	static const char *form_names[] = {"shrubbery request", "robotomy request", "pardon request"};

	{
		std::cout << BOLDBLUE << "test " << n << ": ShrubberyCreationForm returned by an Intern and executed\n" << RESET;

		Bureaucrat bureacrat("Bob", 20);
		Intern intern;
		AForm * form;
		form = intern.makeForm(form_names[n], "form_target");
		form->beSigned(bureacrat);
		form->execute(bureacrat);
		std::cout << BOLDGREEN << "Tree was created\n" << RESET;
		n++;
		if (form != NULL)
			delete form;
	}

	{
		std::cout << BOLDBLUE << "test " << n << ": RobotomyRequestForm returned by an Intern and executed\n" << RESET;

		Bureaucrat bureacrat("Bob", 20);
		Intern intern;
		AForm * form;
		form = intern.makeForm(form_names[n], "form_target");
		form->beSigned(bureacrat);
		form->execute(bureacrat);
		n++;
		if (form != NULL)
			delete form;
	}

	{
		std::cout << BOLDBLUE << "test " << n << ": PresidentialPardonForm returned by an Intern and executed\n" << RESET;

		Bureaucrat bureacrat("Bob", 20);
		Intern intern;
		AForm * form;
		form = intern.makeForm(form_names[n], "form_target");
		form->beSigned(bureacrat);
		form->execute(bureacrat);
		n++;
		if (form != NULL)
			delete form;
	}

	{
		std::cout << BOLDBLUE << "test " << n << ": nothing returned by an Intern and executed\n" << RESET;

		Bureaucrat bureacrat("Bob", 20);
		Intern intern;
		AForm * form;
		form = intern.makeForm("", "form_target");

		std::cout << BOLDRED << "form is " << form << " \n" << RESET;
		n++;
		if (form != NULL)
			delete form;
	}
}
