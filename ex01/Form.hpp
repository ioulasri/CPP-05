#ifndef Form_HPP
#define Form_HPP

#include <string>
#include <iostream>


class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool 				_isSigned;
	const uint			_gradeToSign;
	const uint			_gradeToExec;

public:
    class GradeTooHighException : public std::exception
    {
        private:
        public:
            virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        private:
        public:
            virtual const char *what() const throw();
    };

		class MissingNameException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	Form(const std::string name, const uint gradeToExec, const uint gradeToSign);
	Form(const Form& other);
	Form &operator=(const Form& other);
	~Form();

	const std::string getName( void ) const ;
    uint getGradeToExec( void ) const ;
    uint getGradeToSign( void ) const ;
	bool getSignStatus() const;

	void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &os, const Form &Form);

#endif // Form_HPP