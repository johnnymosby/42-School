#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
  public:
    Weapon(std::string type): type(type) {};
    std::string const & getType();
    void  setType(std::string type);

  private:
    std::string type;
};

#endif