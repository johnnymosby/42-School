#include "ShrubberyCreationForm.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrub", 145, 137) {};
ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrub", 145, 137), target(target) {};
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) {
	*this = copy;
};


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

void	ShrubberyCreationForm::_execute(void) const {
	std::ifstream	infile("./data/ascii_tree.txt");
	std::ofstream	outfile((this->target + "_shrubbery").c_str());


	std::string line;

	while (getline(infile, line))
		outfile << line << "\n";
	outfile.close();
	infile.close();
}

/*
** --------------------------------- EXCEPTION --------------------------------
*/



/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	ShrubberyCreationForm::setTarget(std::string target) {
	this->target = target;
}

std::string	ShrubberyCreationForm::getTarget(void) const {
	return target;
}

/* ************************************************************************** */