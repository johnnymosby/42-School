#include "ShrubberyCreationForm.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrub", 145, 137) {};
ShrubberyCreationForm::ShrubberyCreationForm(std::string name):  AForm(name, 145, 137) {};
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) {};
		

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm() {};

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & other) {
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



/*
** --------------------------------- EXCEPTION --------------------------------
*/



/*
** --------------------------------- ACCESSOR ---------------------------------
*/



/* ************************************************************************** */