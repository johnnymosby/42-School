#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>

# ifndef WEAPON
# define WEAPON

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