#include "Form.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(): name("default_form"), if_signed(false), grade_to_sign(GRADE_TO_SIGN), grade_to_execute(GRADE_TO_EXECUTE) {};

Form::Form(std::string name): name(name), if_signed(false), grade_to_sign(GRADE_TO_SIGN), grade_to_execute(GRADE_TO_EXECUTE) {};

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form() {};

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream	&operator<<(std::ostream &os, const Form & other) {
	os << other.getName();
	os << " (grade to sign " << other.getGradeToSign() << ", ";
	os << "grade to execute " << other.getGradeToExecute() << ", ";
	os << "if_signed: " << other.getIfSigned() << ") ";
	return os;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Form::beSigned(const Bureaucrat &signer) {
	unsigned int grade = signer.getGrade();
	if (grade > grade_to_sign) {
		throw (Form::GradeTooLowException());
	}
	if_signed = true;
}

/*
** --------------------------------- EXCEPTION --------------------------------
*/

const char *Form::GradeTooHighException::what() const throw() {
	return "The grade to set is too high\n";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "The grade to set is too low\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		Form::getName(void) const {
	return name;
}

unsigned int	Form::getGradeToSign(void) const {
	return grade_to_sign;
}

unsigned int	Form::getGradeToExecute(void) const {
	return grade_to_execute;
}

bool	Form::getIfSigned(void) const {
	return if_signed;
}

/* ************************************************************************** */