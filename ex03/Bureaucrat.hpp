#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"
using std::cout;
using std::endl;
using std::string;

class Bureaucrat
{
	private:
		const string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat(const string name, int grade);
		Bureaucrat &operator=(const Bureaucrat &copy);
		string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		~Bureaucrat();
		void signForm(AForm &);
		void executeForm(AForm const &);
		class GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};
		class FormAlreadySignedException : public std::exception
		{
			const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
