#include "RobotomyRequestForm.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robo", 145, 137), target("default_robo") {};
RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robo", 145, 137), target(target) {};
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy) {
	*this = copy;
};
		

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm() {};

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & other) {
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

void	RobotomyRequestForm::_execute(void) const {
	std::cout << BOLDRED << "Krrrrrrrrrrrrrrrrrr... ";
	srand((unsigned) time(NULL));
	unsigned int is_robotimized = rand() % 2;
	if (is_robotimized) {
		std::cout << RESET << BOLDGREEN << this->target << " was successfuly robotimized!\n" << RESET;
	} else {
		std::cout << BOLDRED << this->target << " failed to be robotimized!\n" << RESET;
	}
}

/*
** --------------------------------- EXCEPTION --------------------------------
*/



/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	RobotomyRequestForm::setTarget(std::string target) {
	this->target = target;
}

std::string	RobotomyRequestForm::getTarget(void) const {
	return target;
}

/* ************************************************************************** */