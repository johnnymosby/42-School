#ifndef HUMANB_HPP
# define HUMANB_HPP

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