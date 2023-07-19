#include "../inc/Weapon.hpp"

void  Weapon::setType(std::string type)
{
  this->type = type;
}

std::string const & Weapon::getType()
{
  return this->type;
}
