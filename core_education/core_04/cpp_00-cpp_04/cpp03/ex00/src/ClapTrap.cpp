#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap() name("Bob") {
}

ClapTrap::ClapTrap(const ClapTrap & src)
{
  *this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &        ClapTrap::operator=(ClapTrap const & rhs)
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &      operator<<(std::ostream & os, ClapTrap const & i)
{
  //os << "Value = " << i.getValue();
  return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */