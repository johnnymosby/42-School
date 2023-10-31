#ifndef FOURCLASSES_HPP
# define FOURCLASSES_HPP

# include <cstdlib>
# include <iostream>
# include "definitions.h"

class Base
{
	public:
		virtual ~Base() {};
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

#endif