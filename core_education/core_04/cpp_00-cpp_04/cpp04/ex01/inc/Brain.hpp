#ifndef BRAIN_HPP
# define BRAIN_HPP


# include <string>
# include <iostream>

class Brain
{
	public:
		Brain();
		Brain(Brain const & src);
		~Brain();

		Brain & operator=(Brain const & other);

		std::string	*getIdeas() const;
		size_t		getSize();

	private:
		std::string	*ideas;
		size_t		size_;
};


#endif /* ******************************************************** BRAIN_HPP */