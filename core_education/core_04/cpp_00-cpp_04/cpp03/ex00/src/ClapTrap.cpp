#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap(): name("Bob"), hp(10), ep(10), ad(0) {
	std::cout << "Default constructor is called\n";
}

ClapTrap::ClapTrap(std::string name): name(name), hp(10), ep(10), ad(0) {
	std::cout << "Constructor with 'string name' is called\n";
}

ClapTrap::ClapTrap(std::string name, int hp, int ep, int ad): name(name), hp(hp), ep(ep), ad(ad) {
	std::cout << "Constructor with no default arguments is called\n";
}

ClapTrap::ClapTrap(const ClapTrap & src)
{
	std::cout << "Copy constructor is called\n";
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor is called\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &		ClapTrap::operator=(ClapTrap const & other) {
	std::cout << "Copy assignment operator is called\n";
	if (this != &other ) {
		*this = other;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	ClapTrap::attack(const std::string& target) {
	if (this->ep > 0) {
		std::cout << "ClapTrap " << this->name << " attacks "
					<< target << ", causing " << this->ad << " points of damage!\n";
		this->ep -= 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	int	damage = int(amount);

	if (this->hp <= 0) {
		std::cout << "ClapTrap " << this->name << " is already dead!\n";
	} else if (this->hp > damage) {
		std::cout << "ClapTrap " << this->name << " receives "
					<< amount << " points of damage!\n";
		this->hp -= damage;
	} else {
		std::cout << "ClapTrap " << this->name << " receives "
					<< damage << " points of damage!\n";
		this->hp = 0;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	int	heal = int(amount);

	if (this->ep > 0) {
		std::cout << "ClapTrap " << this->name << " repairs "
					<< heal << " points of health!\n";
		this->ep -= 1;
		this->hp += heal;
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