#ifndef CAT_HPP
# define CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat
{
	public:
		WrongCat();
		WrongCat(std::string const & type);
		WrongCat(WrongCat const & src);
		~WrongCat();

		WrongCat & operator=(WrongCat const & other);

		void		makeSound();
		std::string	getType();
};


#endif /* ******************************************************** CAT_HPP */