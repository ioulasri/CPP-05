#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Bureaucrat bob("Bob", 20);
		Form FormA("Form A", 45, 30);
		
		std::cout << bob << std::endl;
		std::cout << FormA << std::endl;

		bob.signForm(FormA);
		std::cout << FormA << std::endl;

		Bureaucrat alice("Alice", 60);
		alice.signForm(FormA);
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}