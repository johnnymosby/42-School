#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "definitions.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class	ShrubberyCreationForm: public AForm {
	
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();

		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & other);

		void			setTarget(std::string);
		std::string		getTarget(void) const;

		void virtual	_execute(void) const;

	private:
		std::string		target;
};

std::ostream	&operator<<(std::ostream &os, const AForm & other);

#endif