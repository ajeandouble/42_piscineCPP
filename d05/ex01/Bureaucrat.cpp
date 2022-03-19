#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Exceptions.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
{
	if (grade > 150)
		throw GradeTooHighException();
	else if (grade < 1)
		throw GradeTooLowException();
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

void	Bureaucrat::signForm(Form &form)
{
	form.beSigned(this);
}

GradeTooLowException::GradeTooLowException() { }

GradeTooLowException::GradeTooLowException(GradeTooLowException const &src)
{
	*this = src;
}

GradeTooLowException::~GradeTooLowException(void) throw() { }

GradeTooLowException &GradeTooLowException::operator=(GradeTooLowException const &src)
{
	(void)src;
		return	(*this);
}

GradeTooHighException::GradeTooHighException() { }

const char* GradeTooLowException::what() const throw()
{
	return "Grade is too low";	
}

const char* GradeTooHighException::what() const throw()
{
	return "Grade is too high";	
}

GradeTooHighException::GradeTooHighException(GradeTooHighException const &src)
{
	*this = src;
}

GradeTooHighException& GradeTooHighException::operator=(GradeTooHighException const &src)
{
		(void)src;
		return (*this);
}

GradeTooHighException::~GradeTooHighException() throw()	{ }

void Bureaucrat::incGrade()
{
	throw	GradeTooHighException();
	this->_grade++;
}

void Bureaucrat::decGrade()
{
	if (this->_grade == 1)
		throw	GradeTooLowException();
	this->_grade++;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}
