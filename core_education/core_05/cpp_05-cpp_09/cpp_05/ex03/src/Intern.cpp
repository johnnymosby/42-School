#include "Intern.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern() {}

Intern::Intern(const Intern &copy) {
	(void)copy;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &Intern::operator=(const Intern &assign) {
	(void)assign;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AForm* Intern::makeForm(const std::string& form_name, const std::string& form_target) {
	static const char *form_names[] = {"shrubbery request", "robotomy request", "pardon request"};

	char first_letter = form_name[0];
	switch (first_letter) {
		case 's':
			if (form_name == form_names[0]) {
				std::cout << BOLDGREEN << "new ShrubberyCreationForm was returned\n" << RESET;
			}
			return new ShrubberyCreationForm(form_target);
		case 'r':
			if (form_name == form_names[1]) {
				std::cout << BOLDMAGENTA << "new RobotomyRequestForm was returned\n" << RESET;
			}
			return new RobotomyRequestForm(form_target);
		case 'p':
			if (form_name == form_names[2]) {
				std::cout << BOLDCYAN << "new PresidentialPardonForm form was returned\n" << RESET;
			}
			return new PresidentialPardonForm(form_target);
		default:
			std::cout << BOLDRED << "no form was returned\n" << RESET;
			return NULL;
	}
}

/*
** --------------------------------- EXCEPTION --------------------------------
*/



/*
** --------------------------------- ACCESSOR ---------------------------------
*/



/* ************************************************************************** */