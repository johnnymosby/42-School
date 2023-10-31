#include "Serializer.hpp"

Serializer::Serializer(void) {};
Serializer::~Serializer() {};
Serializer::Serializer(const Serializer &copy) {*this = copy; };
Serializer & Serializer::operator=(const Serializer &other)
{
	if (&other != this) {
		*this = other;
	}
	return *this;
};
uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
};
Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
};