#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap(): name("Bob"), hp(10), ep(10), ad(0) {
	std::cout << "Default constructor is called [ClapTrap]\n";
}

ClapTrap::ClapTrap(std::string name): name(name), hp(10), ep(10), ad(0) {
	std::cout << "Constructor with 'string name' is called ["
				<< name << ", " << hp << " HP, " << ep << " EP, " << ad << " AD; ClapTrap]\n";
}

ClapTrap::ClapTrap(const ClapTrap & src)
{
	std::cout << "Copy constructor is called [ClapTrap]\n";
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor is called [ClapTrap]\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &		ClapTrap::operator=(ClapTrap const & other) {
	std::cout << "Copy assignment operator is called [ClapTrap]\n";
	if (this != &other ) {
		*this = other;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	ClapTrap::attack(const std::string& target) {
	if (this->hp <= 0) {
		std::cout << "ClapTrap "
					<< BOLDMAGENTA << this->name << RESET
					<< BLACK << " is already dead!\n" << RESET;
	} else if (this->ep > 0) {
		std::cout << "ClapTrap "
					<< BOLDMAGENTA << this->name << RESET
					<< RED << " attacks " << RESET
					<< target << ", causing " << this->ad << " points of damage!\n";
		this->ep -= 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	int	damage = int(amount);

	if (damage < 0) {
		std::cout << "ClapTrap "
					<< BOLDMAGENTA << this->name << RESET
					<< RED << " receives " << RESET
					<< "no damage! [" << this->hp << " HP]\n";
	} else if (this->hp <= 0) {
		std::cout << "ClapTrap "
					<< BOLDMAGENTA << this->name << RESET
					<< BLACK << " is already dead!\n" << RESET;
	} else if (this->hp > damage) {
		this->hp -= damage;
		std::cout << "ClapTrap "
					<< BOLDMAGENTA << this->name << RESET
					<< RED << " receives " << RESET
					<< damage << " points of damage! [" << this->hp << " HP]\n";
	} else {
		this->hp = 0;
		std::cout << "ClapTrap "
					<< BOLDMAGENTA << this->name << RESET
					<< RED  << " receives " << RESET
					<< damage << " points of damage and "
					<< RED << "dies!" << RESET
					<< " [" << this->hp << " HP]\n";
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	int	heal = int(amount);

	if (this->hp <= 0) {
		std::cout << "ClapTrap " << BOLDMAGENTA << this->name << RESET
					<< BLACK << " is already dead!\n" << RESET
					<< "ClapTrap " << BOLDMAGENTA << this->name
					<< GREEN << " repairs" << RESET << " no health\n";
	} else if (heal < 0) {
		std::cout << "ClapTrap " << BOLDMAGENTA << this->name << RESET
					<< GREEN << " repairs " << RESET
					<< heal << "no health! [" << this->hp << " HP, "
					<< this->ep << " EP]\n";
	} else if (this->ep > 0) {
		this->hp += heal;
		this->ep -= 1;
		std::cout << "ClapTrap " << BOLDMAGENTA << this->name << RESET
					<< GREEN << " repairs " << RESET
					<< heal << " points of health! [" << this->hp << " HP, "
					<< this->ep << " EP]\n";
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string ClapTrap::getName(void) const {
	return this->name;
}

int	ClapTrap::getHP(void) const {
	return this->hp;
}

int	ClapTrap::getEP(void) const {
	return this->ep;
}

int	ClapTrap::getAD(void) const {
	return this->ad;
}

/* ************************************************************************** */