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

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);

# endif
