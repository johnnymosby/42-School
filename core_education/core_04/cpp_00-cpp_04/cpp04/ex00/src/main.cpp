#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();


	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;

	const WrongAnimal* meta_wrong = new WrongAnimal();
	const WrongAnimal* i_wrong = new WrongCat();

	std::cout << i_wrong->getType() << " " << std::endl;

	i_wrong->makeSound(); //will not output the cat sound!
	meta_wrong->makeSound();

	delete meta_wrong;
	delete i_wrong;

	return 0;
}

