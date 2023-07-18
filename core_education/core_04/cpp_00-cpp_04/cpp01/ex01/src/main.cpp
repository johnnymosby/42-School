# include "../inc/Zombie.hpp"

void  testZombieHorde(Zombie* zombies, int N) {
  for (int i = 0; i < N; i++) {
    zombies[i].announce();
  }
}

int main(void)
{
  int         N = 10;
  std::string name  = "Johnny";
  Zombie*     zombies = zombieHorde(N, name);

  testZombieHorde(zombies, N);

  std::cout << std::endl;

  delete [] zombies;
  return 0;
}
