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
	
ClapTrap::ClapTrap(std::string name, int hp, int ep, int ad): name(name), hp(hp), ep(ep), ad(ad) {
	std::cout << "Constructor with no default arguments is called ["
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
	if (this->ep > 0) {
		std::cout << ORANGE << "ClapTrap " << this->name << " attacks "
					<< target << ", causing " << this->ad << " points of damage!\n"
					<< RESET;
		this->ep -= 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	int	damage = int(amount);

	if (damage < 0) {
		std::cout << RED << "ClapTrap " << this->name << " receives "
					<< damage << "no damage! [" << this->hp << " HP]\n" << RESET;
	} else if (this->hp <= 0) {
		std::cout << RED << "ClapTrap " << this->name << " is already dead!\n" << RESET;
	} else if (this->hp > damage) {
		this->hp -= damage;
		std::cout << RED << "ClapTrap " << this->name << " receives "
					<< damage << " points of damage! [" << this->hp << " HP]\n" << RESET;
	} else {
		this->hp = 0;
		std::cout << RED << "ClapTrap " << this->name << " receives "
					<< damage << " points of damage! [" << this->hp << " HP]\n" << RESET;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	int	heal = int(amount);

	if (this->hp <= 0) {
		std::cout << "ClapTrap " << this->name << RED << " is already dead!\n" << RESET
					<< "ClapTrap " << this->name << " repairs no health\n";
	} else if (heal < 0) {
		std::cout << GREEN << "ClapTrap " << this->name << " repairs "
					<< heal << "no health! [" << this->hp << " HP, " << this->ep
					<< " EP]\n" << RESET;
	} else if (this->ep > 0) {
		this->hp += heal;
		this->ep -= 1;
		std::cout << GREEN << "ClapTrap " << this->name << " repairs "
					<< heal << " points of health! [" << this->hp << " HP, " << this->ep
					<< " EP]\n" << RESET;
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