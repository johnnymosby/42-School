#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(std::string const & type);
		Cat(Cat const & src);
		virtual ~Cat();

		Cat & operator=(Cat const & other);

		void		makeSound() const;
		std::string	getType() const;
};


#endif /* ******************************************************** CAT_HPP */