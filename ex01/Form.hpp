#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Bureaucrat;

class Form
{
	private:
		const string _name;
		bool _signed;
		int _signGrade;
		int _execGrade;
	public:
		Form();
		Form(const string &,const int &,const int &);
		Form(const Form &);
		const Form &operator=(const Form &);
		~Form();
		const string &GetName() const;
		bool GetSigned() const;
		const int &GetSignGrade() const;
		const int &GetExecGrade() const;
		void beSigned(const Bureaucrat &bureaucrat);
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

std::ostream &operator<<(std::ostream &out, const Form &form);


#endif
