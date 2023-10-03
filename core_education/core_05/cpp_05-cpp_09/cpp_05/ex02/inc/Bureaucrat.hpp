#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

#include "definitions.hpp"
#include "AForm.hpp"

class	AForm;

class	Bureaucrat {
	
	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(unsigned int grade);
		Bureaucrat(std::string name, unsigned int grade);
		~Bureaucrat();

		std::string		getName (void) const;
		unsigned int	getGrade (void) const;

		void			incrementGrade(void);
		void			decrementGrade(void);

		void			signForm(AForm &document);

	private:
		const std::string			name;
		unsigned int				grade;
		const static unsigned int	max_grade = MAX_GRADE;
		const static unsigned int	min_grade = MIN_GRADE;

	class GradeTooHighException: public std::exception {
		public:
			const char *what() const throw();
	};
	class GradeTooLowException: public std::exception {
		public:
			const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat & other);

#endif