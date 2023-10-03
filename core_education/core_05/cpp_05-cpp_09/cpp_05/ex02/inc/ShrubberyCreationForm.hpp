#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "definitions.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class	ShrubberyCreationForm: public AForm {
	
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();

		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & other);

		void virtual	_execute(Bureaucrat const & executor) const;

	private:
		std::string		target;
};

std::ostream	&operator<<(std::ostream &os, const AForm & other);

#endif