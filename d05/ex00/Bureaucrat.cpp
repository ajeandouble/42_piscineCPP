#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Exceptions.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
{
	if (grade > 150)
		throw	GradeTooHighException();
	else if (grade < 1)
		throw	GradeTooLowException();
	this->_name = name;
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	this->_name = src.getName();
	this->_grade = src.getGrade();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &b)
{
	this->_name = b.getName();
	this->_grade = b.getGrade();
	return (*this);
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}	


Bureaucrat::GradeTooLowException::GradeTooLowException() {}

Bureaucrat::GradeTooLowException::GradeTooLowException(Bureaucrat::GradeTooLowException const &src)
{
	*this = src;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw()
{
}

Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException::operator=(Bureaucrat::GradeTooLowException const &src)
{
	(void)src;
		return *this;
}


Bureaucrat::GradeTooHighException::GradeTooHighException() {}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";	
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";	
}

Bureaucrat::GradeTooHighException::GradeTooHighException(Bureaucrat::GradeTooHighException const &src)
{
	*this = src;
}

Bureaucrat::GradeTooHighException& Bureaucrat::GradeTooHighException::operator=(Bureaucrat::GradeTooHighException const &src)
{
		(void)src;
		return (*this);
}


Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

void Bureaucrat::decGrade()
{
	if (this->_grade == 1)
		throw	Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::incGrade()
{
	throw	Bureaucrat::GradeTooHighException();
	this->_grade++;
}


std::ostream &operator<<(std::ostream &os, Bureaucrat const &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}
