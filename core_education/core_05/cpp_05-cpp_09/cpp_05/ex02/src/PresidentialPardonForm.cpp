#include "PresidentialPardonForm.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm(): AForm("Pardon", 145, 137), target("default_criminal") {};
PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Pardon", 145, 137), target(target) {};
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) {
		*this = copy;
};


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm() {};

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & other) {
	if (this != &other ) {
		this->setGradeToExecute(other.getGradeToExecute());
		this->setGradeToSign(other.getGradeToSign());
		this->setIfSigned(other.getIfSigned());
		this->target = other.target;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	PresidentialPardonForm::_execute(void) const {
	std::cout << this->target << "has been pardoned by Zaphod Beeblebrox!\n";
}

/*
** --------------------------------- EXCEPTION --------------------------------
*/



/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	PresidentialPardonForm::setTarget(std::string target) {
	this->target = target;
}

std::string	PresidentialPardonForm::getTarget(void) const {
	return target;
}

/* ************************************************************************** */