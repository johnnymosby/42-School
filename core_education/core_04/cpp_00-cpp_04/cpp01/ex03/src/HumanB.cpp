#include "../inc/HumanB.hpp"

void  HumanB::setWeapon(Weapon &weapon) 
{
  this->weapon = &weapon;
}

void  HumanB::attack() {
  if (weapon != NULL)
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
  else
    std::cout << name << " doesn't have a weapon and cannot attack" << std::endl;
}
