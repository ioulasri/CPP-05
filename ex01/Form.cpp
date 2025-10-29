#include "Form.hpp"
#include "Bureaucrat.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
    return "GradeTooHighException";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "GradeTooLowException";
}

const char *Form::MissingNameException::what() const throw()
{
	return "MissingNameException";
}

Form::Form(const std::string name, const uint grade_to_exec, const uint grade_to_sign) : _name(name), _isSigned(false), _gradeToSign(grade_to_sign), _gradeToExec(grade_to_exec)
{
    if (name.empty())
        throw MissingNameException();
    if (grade_to_sign < 1 || grade_to_exec < 1)
        throw GradeTooHighException();
    if (grade_to_sign > 150 || grade_to_exec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
}

Form &Form::operator=(const Form& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

Form::~Form()
{
}

uint Form::getGradeToExec() const
{
    return (_gradeToExec);
}

uint Form::getGradeToSign() const
{
    return (_gradeToSign);
}

bool Form::getSignStatus() const
{
    return (_isSigned);
}

const std::string Form::getName() const
{
    return (_name);
}

void       Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
    std::cout << "bureaucrat " << bureaucrat.getName() << " has succesfully signed the Form " << this->getName() << "\n"; 
}

std::ostream &operator<<(std::ostream &os, const Form &Form)
{
    return (os << Form.getName() << " Form, signed: " << Form.getSignStatus() << ", sign grade: " << Form.getGradeToSign() << ", exec grade: " << Form.getGradeToExec() << "\n");
}