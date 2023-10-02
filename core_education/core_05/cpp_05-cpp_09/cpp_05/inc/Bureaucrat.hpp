#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

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

	private:
		const std::string		name;
		unsigned int			grade;
		const unsigned int		max_grade = 1;
		const unsigned int		min_grade = 150;

	class GradeTooHighException: public std::exception {
		public:
			const char *what() const throw();
	};
	class GradeTooLowException: public std::exception {
		public:
			const char *what() const throw();
	};
};

std::ostream	operator<<(std::ostream &os, const Bureaucrat & other);

#endif