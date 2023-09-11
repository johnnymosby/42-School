#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(std::string const & type);
		Cat(Cat const & src);
		~Cat();

		Cat & operator=(Cat const & other);

		void		makeSound();
		std::string	getType();
};


#endif /* ******************************************************** CAT_HPP */