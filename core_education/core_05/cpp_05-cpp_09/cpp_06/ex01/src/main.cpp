#include "Serializer.hpp"

int	main() {
	Data data;

	data.s = "HELLO!\n";
	uintptr_t raw_value = Serializer::serialize(&data);
	Data * second_ptr = Serializer::deserialize(raw_value);
	std::cout << second_ptr->s << "\nvalue transformations:\n"
				<< "original struct ptr:		" << &data << '\n'
				<< "raw value of ptr:		" << raw_value << '\n'
				<< "raw value of ptr in hex:	" << std::hex << raw_value << '\n'
				<< "deserialized ptr:		" << second_ptr << "\n\n";
}
