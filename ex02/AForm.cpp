#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
    return "GradeTooHighException";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "GradeTooLowException";
}

const char *AForm::MissingNameException::what() const throw()
{
	return "MissingNameException";
}

AForm::AForm(const std::string name, const uint grade_to_exec, const uint grade_to_sign) : _name(name), _isSigned(false), _gradeToSign(grade_to_sign), _gradeToExec(grade_to_exec)
{
    if (name.empty())
        throw MissingNameException();
    if (grade_to_sign < 1 || grade_to_exec < 1)
        throw GradeTooHighException();
    if (grade_to_sign > 150 || grade_to_exec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
}

AForm &AForm::operator=(const AForm& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm()
{
}

uint AForm::getGradeToExec() const
{
    return (_gradeToExec);
}

uint AForm::getGradeToSign() const
{
    return (_gradeToSign);
}

bool AForm::getSignStatus() const
{
    return (_isSigned);
}

const std::string AForm::getName() const
{
    return (_name);
}

void       AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
    std::cout << "bureaucrat " << bureaucrat.getName() << " has succesfully signed the AForm " << this->getName() << "\n"; 
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!_isSigned)
        throw GradeTooLowException();
    if (executor.getGrade() > _gradeToExec)
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
    return (os << AForm.getName() << " AForm, signed: " << AForm.getSignStatus() << ", sign grade: " << AForm.getGradeToSign() << ", exec grade: " << AForm.getGradeToExec() << "\n");
}