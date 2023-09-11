#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(std::string const & type);
		WrongCat(WrongCat const & src);
		~WrongCat();

		WrongCat & operator=(WrongCat const & other);

		void		makeSound() const;
		std::string	getType() const;
};


#endif /* ******************************************************** WRONGCAT_HPP */