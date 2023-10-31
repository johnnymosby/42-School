#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Data.h"
# include <stdint.h> //for uintptr_t
class Serializer
{
	public:
		Serializer(void);
		~Serializer();
		Serializer(const Serializer &copy);
		Serializer & operator=(const Serializer &other);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
};

#endif