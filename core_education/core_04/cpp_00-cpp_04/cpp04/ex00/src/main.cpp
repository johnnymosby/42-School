#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
// int main(void) {
// 	// create correct animals
// 	Animal *Animals[3];

// 	Animals[0] = new Animal();
// 	Animals[1] = new Dog();
// 	Animals[2] = new Cat();

// 	std::cout << std::endl << std::endl;
// 	// print the type of the animal and the sound it makes
// 	for (size_t type = 0; type < 3; type++) Animals[type]->getType(), Animals[type]->makeSound();

// 	std::cout << std::endl << std::endl;

// 	// create wrong animals
// 	WrongAnimal *WrongAnimals[3];

// 	WrongAnimals[0] = new WrongAnimal();
// 	WrongAnimals[1] = new WrongCat();

// 	std::cout << std::endl << std::endl;

// 	for (size_t type = 0; type < 2; type++)
// 		WrongAnimals[type]->getType(), WrongAnimals[type]->makeSound();

// 	std::cout << std::endl << std::endl;

// 	// free
// 	for (size_t i = 0; i < 3; i++) delete Animals[i];

// 	std::cout << std::endl << std::endl;

// 	for (size_t i = 0; i < 2; i++) delete WrongAnimals[i];

// 	return 0;
// }
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

	std::cout << i->getType() << " " << std::endl;

	i_wrong->makeSound(); //will output the cat sound!
	meta_wrong->makeSound();

	delete meta_wrong;
	delete i_wrong;

	return 0;
}

