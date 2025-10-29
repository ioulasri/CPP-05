#ifndef AForm_HPP
#define AForm_HPP

#include <string>
#include <iostream>


class Bureaucrat;

class AForm
{
protected:
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

	AForm(const std::string name, const uint gradeToExec, const uint gradeToSign);
	AForm(const AForm& other);
	AForm &operator=(const AForm& other);
	~AForm();

	const std::string getName( void ) const ;
    uint getGradeToExec( void ) const ;
    uint getGradeToSign( void ) const ;
	bool getSignStatus() const;

	void beSigned(const Bureaucrat &bureaucrat);

	virtual void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &os, const AForm &AForm);

#endif // AForm_HPP