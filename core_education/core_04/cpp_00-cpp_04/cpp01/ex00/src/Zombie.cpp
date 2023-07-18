# include "../inc/Zombie.hpp"

void  Zombie::announce(void)
{
  std::cout << this->name <<  ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string name): name(name) {}
