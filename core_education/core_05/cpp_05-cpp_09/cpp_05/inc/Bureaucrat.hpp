#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class	Bureaucrat {
	
	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		~Bureaucrat();

		std::string		getName(void);
		unsigned int	getGrade(void);

	private:
		const std::string	name;
		unsigned int		grade;

};

std::ostream	operator<<(std::ostream &os, const Bureaucrat & other);

#endif