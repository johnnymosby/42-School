#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "definitions.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class	RobotomyRequestForm: public AForm {
	
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &copy);
		~RobotomyRequestForm();

		RobotomyRequestForm & operator=(RobotomyRequestForm const & other);

		void			setTarget(std::string);
		std::string		getTarget(void) const;

		void virtual	_execute(void) const;

	private:
		std::string		target;
};

std::ostream	&operator<<(std::ostream &os, const AForm & other);

#endif