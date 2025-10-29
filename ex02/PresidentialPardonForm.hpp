#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"


class Bureaucrat;

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;

public:
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();
	
	void execute(Bureaucrat const & executor) const;
};

#endif /* PRESIDENTIALPARDONFORM_HPP */