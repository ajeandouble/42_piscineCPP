#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"
#include "Exceptions.hpp"

class Bureaucrat;

class Form
{
	private:
		bool _signed;
		int _grade;
		std::string _name;

	public:
		Form(std::string name, int grade) : _signed(false), _name(name), _grade(grade){};
		~Form();
		Form &operator=(Form const &form);

		std::string getName() const;
		bool getSigned() const;
		int getGrade() const;

		void	beSigned(Bureaucrat *b);
};

#endif
