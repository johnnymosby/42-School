#include "Bureaucrat.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(): name("default_bureaucrat"), grade(150) {}
Bureaucrat::Bureaucrat(std::string name): name(name), grade(150) {}

Bureaucrat::Bureaucrat(unsigned int grade): name("default_bureaucrat") {
	if (grade < max_grade) {
		throw (Bureaucrat::GradeTooHighException());
	}
	else if (grade > min_grade) {
		throw (Bureaucrat::GradeTooLowException());
	}

	this->grade = grade;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade): name(name) {
	if (grade < max_grade) {
		throw (Bureaucrat::GradeTooHighException());
	}
	else if (grade > min_grade) {
		throw (Bureaucrat::GradeTooLowException());
	}

	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
	*this = copy;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream	&operator<<(std::ostream &os, const Bureaucrat & other) {
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << "\n";
	return os;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other ) {
		*this = other;
	}
	return *this;
};

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Bureaucrat::incrementGrade(void) {
	if (grade - 1 < max_grade) {
		throw (Bureaucrat::GradeTooHighException());
	}

	this->grade--;
}

void	Bureaucrat::decrementGrade(void) {
	if (grade + 1 > min_grade) {
		throw (Bureaucrat::GradeTooLowException());
	}

	this->grade++;
}

void	Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName();
	}
	catch (std::exception &e) {
		std::cout << this->name << " (" << this->grade << ") couldn't sign "
					<< form << " because " << e.what();
	}
}

void	Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << "\n";
	}
	catch (std::exception &e) {
		std::cout << this->name << " failed to execute " << form.getName() << " because " << e.what();
	}
}

/*
** --------------------------------- EXCEPTION --------------------------------
*/

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "The grade to set is too high\n";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "The grade to set is too low\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		Bureaucrat::getName(void) const {
	return name;
}

unsigned int	Bureaucrat::getGrade(void) const {
	return grade;
}

/* ************************************************************************** */