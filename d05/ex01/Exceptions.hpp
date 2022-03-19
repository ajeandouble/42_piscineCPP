# ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

#include <exception>

class	GradeTooLowException : public std::exception
{
	public:
		GradeTooLowException();
		virtual ~GradeTooLowException() throw();
		GradeTooLowException(GradeTooLowException const &src);
		GradeTooLowException &operator=(GradeTooLowException const &src);
		virtual const char *what() const throw();
};

class	GradeTooHighException : public std::exception
{
	public:
		GradeTooHighException();
		virtual ~GradeTooHighException() throw();
		GradeTooHighException(GradeTooHighException const &src);
		GradeTooHighException &operator=(GradeTooHighException const &src);
		virtual const char *what() const throw();
};

# endif
