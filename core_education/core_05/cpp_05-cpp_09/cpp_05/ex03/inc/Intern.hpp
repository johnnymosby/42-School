#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class	Intern {
	
	public:
		Intern();
		Intern(const Intern &copy);
		virtual ~Intern();

		Intern &operator=(const Intern &assign);

		AForm* makeForm(const std::string &form_name, const std::string &form_target);

	private:
};

#endif