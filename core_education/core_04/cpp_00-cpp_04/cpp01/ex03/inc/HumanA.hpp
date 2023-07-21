#ifndef HUMANA_HPP
# define HUMANA_HPP

# ifndef WEAPON
# include "Weapon.hpp"

class Weapon
{
  public:
    Weapon(std::string type): type(type) {};
    std::string const & getType();
    void  setType(std::string type);

  private:
    std::string type;
};

# endif

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