#include <iostream>
#include "Form.hpp"

Form::~Form() {}

std::string Form::getName() const { return (this->_name); }

bool Form::getSigned() const { return (this->_signed); }

int Form::getGrade() const { return (this->_grade); }

Form &Form::operator=(Form const &form)
{
	this->_signed = form.getSigned();
	this->_name = form.getName();
	this->_grade = form.getGrade();
	return (*this);
}

void	Form::beSigned(Bureaucrat *b)
{
	if (b->getGrade() <= this->getGrade())
	{
		this->_signed = true;
		std::cout << b->getName() << " signs form " << this->getName() << std::endl;
	}
	else
		throw	GradeTooLowException();
}
