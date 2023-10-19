#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <cstdlib>
#include "definitions.hpp"
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm {
	
	public:
		AForm();
		AForm(std::string name);
		AForm(std::string name, unsigned int grade_to_sign, unsigned int grade_to_execute);
		AForm(const AForm &copy);
		virtual ~AForm();

		AForm &operator=(const AForm &assign);

		std::string		getName (void) const;
		unsigned int	getGradeToSign (void) const;
		unsigned int	getGradeToExecute (void) const;
		bool			getIfSigned(void) const;

		void			setGradeToSign (unsigned int);
		void			setGradeToExecute (unsigned int);
		void			setIfSigned (bool);

		void			beSigned(const Bureaucrat &signer);
		void			execute(Bureaucrat const & executor) const;
		void virtual	_execute(void) const = 0;

	private:
		const std::string			name;
		bool						if_signed;
		unsigned int				grade_to_sign;
		unsigned int				grade_to_execute;
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

	class ExecuteGradeTooLowException: public std::exception {
		public:
			const char *what() const throw();
	};

	class SignGradeTooLowException: public std::exception {
		public:
			const char *what() const throw();
	};

	class NotSignedException: public std::exception {
		public:
			const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, const AForm & other);

#endif