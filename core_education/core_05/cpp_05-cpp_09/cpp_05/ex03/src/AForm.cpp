#include "AForm.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm(): name("default_AForm"), if_signed(false), grade_to_sign(GRADE_TO_SIGN), grade_to_execute(GRADE_TO_EXECUTE) {};

AForm::AForm(std::string name): name(name), if_signed(false), grade_to_sign(GRADE_TO_SIGN), grade_to_execute(GRADE_TO_EXECUTE) {};


AForm::AForm(std::string name, unsigned int grade_to_sign, unsigned int grade_to_execute): name(name) {
	if (grade_to_sign < max_grade || grade_to_execute < max_grade) {
		throw (AForm::GradeTooHighException());
	}
	else if (grade_to_sign > min_grade || grade_to_execute > min_grade) {
		throw (AForm::GradeTooLowException());
	}
	this->if_signed = false;
	this->grade_to_sign = grade_to_sign;
	this->grade_to_execute = grade_to_execute;
};

AForm::AForm(const AForm &copy) {
	setGradeToSign(copy.getGradeToSign());
	setGradeToExecute(copy.getGradeToExecute());
	setIfSigned(copy.getIfSigned());
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm() {};

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream	&operator<<(std::ostream &os, const AForm & other) {
	os << other.getName();
	os << " (grade to sign " << other.getGradeToSign() << ", ";
	os << "grade to execute " << other.getGradeToExecute() << ", ";
	os << "if_signed: " << other.getIfSigned() << ") ";
	return os;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	AForm::beSigned(const Bureaucrat &signer) {
	unsigned int grade = signer.getGrade();
	if (grade > grade_to_sign) {
		throw (AForm::GradeTooLowException());
	}
	if_signed = true;
}

void AForm::execute(Bureaucrat const & executor) const {
	unsigned int	grade = executor.getGrade();

	if (grade > grade_to_execute) {
		throw (AForm::GradeTooLowException());
	}
	else if (if_signed == false) {
		throw (AForm::NotSignedException());
	}
	_execute();
}

/*
** --------------------------------- EXCEPTION --------------------------------
*/

const char *AForm::GradeTooHighException::what() const throw() {
	return "The grade to set is too high\n";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "The grade to set is too low\n";
}

const char *AForm::ExecuteGradeTooLowException::what() const throw() {
	return "The grade is too low for execution\n";
}

const char *AForm::SignGradeTooLowException::what() const throw() {
	return "The grade is too low for signing\n";
}

const char *AForm::NotSignedException::what() const throw() {
	return "The document is not signed\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		AForm::getName(void) const {
	return name;
}

unsigned int	AForm::getGradeToSign(void) const {
	return grade_to_sign;
}

unsigned int	AForm::getGradeToExecute(void) const {
	return grade_to_execute;
}

bool	AForm::getIfSigned(void) const {
	return if_signed;
}

void	AForm::setGradeToSign(unsigned int grade) {
	if (grade < max_grade) {
		throw (AForm::GradeTooHighException());
	}
	else if (grade > min_grade) {
		throw (AForm::GradeTooLowException());
	}

	this->grade_to_sign = grade;
}

void	AForm::setGradeToExecute(unsigned int grade) {
	if (grade < max_grade) {
		throw (AForm::GradeTooHighException());
	}
	else if (grade > min_grade) {
		throw (AForm::GradeTooLowException());
	}

	this->grade_to_execute = grade;
}

void	AForm::setIfSigned(bool if_signed) {
	this->if_signed = if_signed;
}

/* ************************************************************************** */