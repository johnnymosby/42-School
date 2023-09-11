#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog(std::string const & type);
		Dog(Dog const & src);
		virtual ~Dog();

		Dog & operator=(Dog const & other);

		void		makeSound() const;
		std::string	getType() const;
};


#endif /* ******************************************************** DOG_HPP */