# include "../inc/Zombie.hpp"

int main(void)
{
  Zombie  *heap_0 = newZombie("zombie_on_heap_0");
  Zombie  *heap_1 = newZombie("zombie_on_heap_1");
  Zombie  *heap_2 = newZombie("zombie_on_heap_2");
  Zombie  *heap_3 = newZombie("zombie_on_heap_3");
  Zombie  *heap_4 = newZombie("zombie_on_heap_4");

  heap_0->announce();
  heap_1->announce();
  heap_2->announce();
  heap_3->announce();
  heap_4->announce();

  std::cout << std::endl;

  Zombie  stack_0("zombie_on_stack_0");
  Zombie  stack_1("zombie_on_stack_1");
  Zombie  stack_2("zombie_on_stack_2");
  Zombie  stack_3("zombie_on_stack_3");
  Zombie  stack_4("zombie_on_stack_4");

  stack_0.announce();
  stack_1.announce();
  stack_2.announce();
  stack_3.announce();
  stack_4.announce();

  std::cout << std::endl;

  delete heap_0;
  delete heap_1;
  delete heap_2;
  delete heap_3;
  delete heap_4;

  std::cout << std::endl;

  return 0;
}
