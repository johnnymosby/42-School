#include "FourClasses.hpp"

Base *generate(void) {
	unsigned int rng_result = rand() % 3;

	switch (rng_result) {
		case 0:
			std::cout << "A was created!\n";
			return new A();
		case 1:
			std::cout << "B was created!\n";
			return new B();
		case 2:
			std::cout << "C was created!\n";
			return new C();
		default:
			return NULL;
	}
};

void identify(Base* p) {
	if (dynamic_cast<A *>(p) != NULL) {
		std::cout << "A class was identified\n";
	} else if (dynamic_cast<B *>(p) != NULL) {
		std::cout << "B class was identified\n";
	} else if (dynamic_cast<C *>(p) != NULL) {
		std::cout << "C class was identified\n";
	} else {
		std::cout << BOLDRED << "WRONG CLASS TO CAST FROM\n" << RESET;
	}
};

void identify(Base& p) {
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A class was identified\n";
		return ;
	} catch (std::exception &e) {}
	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "B class was identified\n";
		return ;
	} catch (std::exception &e) {}
	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "C class was identified\n";
		return ;
	} catch (std::exception &e) {}
	std::cout << BOLDRED << "WRONG CLASS TO CAST FROM\n" << RESET;
};

int main() {
	std::srand(time(NULL));

	Base *ptr = generate();
	identify(ptr);

	Base *temp = generate();
	Base &ref = *temp;
	identify(ref);

	Base wrong_cast;
	identify(wrong_cast);

	Base *null_ptr = NULL;
	identify(null_ptr);

	delete ptr;
	delete temp;
}
