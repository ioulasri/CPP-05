#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat bureaucrat("Alice", 149);
		std::cout << bureaucrat << std::endl;

		bureaucrat.incrementGrade();
		std::cout << "After increment: " << bureaucrat << std::endl;

		bureaucrat.decrementGrade();
		std::cout << "After decrement: " << bureaucrat << std::endl;

		Bureaucrat invalidBureaucrat("imad", 151);
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Bureaucrat::MissingNameException& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}