#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "definitions.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class	PresidentialPardonForm: public AForm {
	
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &copy);
		~PresidentialPardonForm();

		PresidentialPardonForm & operator=(PresidentialPardonForm const & other);

		void			setTarget(std::string);
		std::string		getTarget(void) const;

		void virtual	_execute(void) const;

	private:
		std::string		target;
};

std::ostream	&operator<<(std::ostream &os, const AForm & other);

#endif