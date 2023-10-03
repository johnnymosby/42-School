#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int n = 0;
	{
		std::cout << BOLDBLUE << "test " << n << ": Signing with a low grade\n" << RESET;
		
		std::string form_name = "Special Document";
		std::string signer_name = "Bob";
		unsigned int grade = 43;

		AForm Document(form_name);
		Bureaucrat Bob(signer_name, grade);

		Bob.signForm(Document);
		std::cout << "\n";
		n++;
	}

		{
		std::cout << BOLDBLUE << "test " << n << ": Signing with a correct grade\n" << RESET;
		
		std::string form_name = "Special Document";
		std::string signer_name = "Bob";
		unsigned int grade = GRADE_TO_SIGN;

		AForm Document(form_name);
		Bureaucrat Bob(signer_name, grade);

		Bob.signForm(Document);
		std::cout << "\n";
		n++;
	}
}

