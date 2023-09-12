#ifndef DOG_HPP
# define DOG_HPP

#include "AbstractAnimal.hpp"
#include "Brain.hpp"

class Dog: public AbstractAnimal
{
	public:
		Dog();
		Dog(std::string const & type);
		Dog(Dog const & src);
		virtual ~Dog();

		Dog & operator=(Dog const & other);

		void		makeSound() const;
		std::string	getType() const;
		Brain *		getBrain();

	private:
		Brain		*brain;
};


#endif /* ******************************************************** DOG_HPP */