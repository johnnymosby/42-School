#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "definitions.hpp"
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form {
	
	public:
		Form();
		Form(std::string name);
		Form(Form &copy);
		~Form();

		Form &operator=(const Form &assign);

		std::string		getName (void) const;
		unsigned int	getGradeToSign (void) const;
		unsigned int	getGradeToExecute (void) const;
		bool			getIfSigned(void) const;

		void			beSigned(const Bureaucrat &signer);

	private:
		const std::string			name;
		bool						if_signed;
		const unsigned int			grade_to_sign;
		const unsigned int			grade_to_execute;
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

std::ostream	&operator<<(std::ostream &os, const Form & other);

#endif