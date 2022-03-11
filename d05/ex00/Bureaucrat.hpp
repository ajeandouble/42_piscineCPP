# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <ostream>
#include <string>
#include <exception>

class Bureaucrat
{
	protected:
		std::string		_name;
		unsigned int	_grade;
	public:
		Bureaucrat(std::string name, unsigned int grade);
		~Bureaucrat();
		Bureaucrat (Bureaucrat const &src);
		Bureaucrat &operator=(Bureaucrat const &b);

		class	GradeTooLowException;
		class	GradeTooHighException;

		void			incGrade();
		void			decGrade();
		unsigned int	getGrade() const;
		std::string		getName() const;

};

class Bureaucrat::GradeTooLowException : public std::exception
{
	public:
		GradeTooLowException();
		virtual ~GradeTooLowException() throw();
		GradeTooLowException(GradeTooLowException const &src);
		GradeTooLowException &operator=(GradeTooLowException const &src);
		virtual const char* what() const throw();
};

class Bureaucrat::GradeTooHighException : public std::exception
{
	public:
		GradeTooHighException();
		virtual ~GradeTooHighException() throw();
		GradeTooHighException(GradeTooHighException const &src);
		GradeTooHighException &operator=(GradeTooHighException const &src);
		virtual const char* what() const throw();		
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);

# endif
