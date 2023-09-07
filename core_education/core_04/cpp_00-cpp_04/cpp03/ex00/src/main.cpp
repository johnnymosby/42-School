#include "ClapTrap.hpp"

int main(void) {
	ClavTrap	bob();
	ClavTrap	jim("Jim");
	ClavTrap	chad("Chad", 100, 100, 100);

	bob.attack("Jim");
	jim.takeDamage(10);
	jim.beRepaired(10);

	jim.takeDamage(-5);
	jim.beRepaired(15);

	chad.takeDamage(100);
	chad.beRepaired(100);

	chad.takeDamage(150);
	chad.beRepaired(100);
}
