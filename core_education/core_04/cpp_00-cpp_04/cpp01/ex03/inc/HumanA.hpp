#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
  public:
    HumanA(std::string name, Weapon &weapon): name(name), weapon(weapon) {};
    void attack();

  private:
    std::string type;
    std::string name;
    Weapon  &weapon;
};

#endif