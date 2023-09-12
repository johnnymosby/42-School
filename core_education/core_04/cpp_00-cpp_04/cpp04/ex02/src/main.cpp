#include "AbstractAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	// abstractanimal_array array
	{
		int array_size = 10;
		AbstractAnimal *abstractanimal_array[array_size];

		for (int i = 0; i < array_size; i++) {
			if (i < array_size / 2) {
				abstractanimal_array[i] = new Dog();
			}
			else {
				abstractanimal_array[i] = new Cat();
			}
		}

		for (int i = 0; i < array_size; i++) {
			std::cout << i << std::endl;
			delete abstractanimal_array[i];
		}
	}

	//basic dog
	{
		Dog basic;
		std::cout << std::endl;
		{
			Dog tmp = basic;
			std::cout << std::endl;
		}
	}

	{
		Dog basic;

		std::string * ideas = basic.getBrain()->getIdeas();

		ideas[0] = "I am a dog";
		for (int i = 0; i < 100; i++) {
			std::cout << &ideas[i] << " " << ideas[i] << std::endl;
		}
	}

	{
		Dog basic;
		Dog not_basic;

		std::string * ideas = basic.getBrain()->getIdeas();

		ideas[0] = "I am a dog";
		not_basic = basic;
		std::string * ideas_not_basic = not_basic.getBrain()->getIdeas();
		std::cout << "IF IDEAS == IDEAS_NOT_BASIC: " << (ideas == ideas_not_basic) << std::endl;
		for (int i = 0; i < 100; i++) {
			std::cout << (&ideas[i] == &ideas_not_basic[i]) << " " << ideas[i] <<std::endl;
		}
	}

	// {
	// 	AbstractAnimal nothing;
	// }

	return 0;
}

