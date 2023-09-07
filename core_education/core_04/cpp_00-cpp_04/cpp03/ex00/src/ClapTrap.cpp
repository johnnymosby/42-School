#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap(): name("Bob"), hp(10), ep(10), ad(0) {}

ClapTrap::ClapTrap(std::string name): name(name), hp(10), ep(10), ad(0) {}

ClapTrap::ClapTrap(const ClapTrap & src)
{
	std::cout
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &        ClapTrap::operator=(ClapTrap const & rhs) {}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	ClapTrap::attack(const std::string& target) {
	if (this->ep > 0) {
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->ad << "points of damage!\n";
		this->ep -= 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	this->hp -= amount;
	std::cout << "ClapTrap " << this->name << " receives " << amount << "points of damage!\n";
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->ep > 0) {
		std::cout << "ClapTrap " << this->name << " repairs " << amount << "points of health!\n";
		this->ep -= 1;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		ClapTrap::getName(void) const {
	return this->name;
}

/* ************************************************************************** */