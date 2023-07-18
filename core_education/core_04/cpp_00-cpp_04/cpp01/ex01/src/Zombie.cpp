# include "../inc/Zombie.hpp"

void  Zombie::announce(void)
{
  std::cout << this->name <<  ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(void): name("") {}

Zombie::Zombie(std::string name): name(name) {}

void  Zombie::setName(std::string name) {
  this->name = name;
}
