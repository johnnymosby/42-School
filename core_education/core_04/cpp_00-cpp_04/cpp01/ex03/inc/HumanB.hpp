#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
  public:
    HumanB(std::string name): name(name), weapon(NULL) {};
    void  attack();
    void  setWeapon(Weapon &weapon);

  private:
    std::string type;
    std::string name;
    Weapon  *weapon;
};

#endif