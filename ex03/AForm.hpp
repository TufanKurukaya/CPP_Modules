#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Bureaucrat;

class AForm
{
	private:
		const string _name;
		bool _signed;
		int _signGrade;
		int _execGrade;
	public:
		AForm();
		AForm(const string &,const int &,const int &);
		AForm(const AForm &);
		const AForm &operator=(const AForm &);
		virtual ~AForm();
		const string &GetName() const;
		virtual bool GetSigned() const;
		const int &GetSignGrade() const;
		const int &GetExecGrade() const;
		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
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
		class FormNotSignedException : public std::exception
		{
			const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &Aform);


#endif
