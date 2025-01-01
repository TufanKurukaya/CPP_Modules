#include "Bureaucrat.hpp"
#include "Form.hpp"
Form::Form() :	_name("Unnamed"),
				_signed(false),
				_signGrade(150),
				_execGrade(150)
{
}

Form::Form(const string &name, const int &signGrade, const int &execGrade) :	_name(name),
																				_signed(0)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	_signGrade = signGrade;
	_execGrade = execGrade;
}

Form::Form(const Form &oder) :	_name(oder._name),
								_signed(oder._signed),
								_signGrade(oder._signGrade),
								_execGrade(oder._execGrade)
{
}

Form::~Form()
{
}

const string &Form::GetName() const
{
	return _name;
}

bool Form::GetSigned() const
{
	return _signed;
}

const int &Form::GetSignGrade() const
{
	return _signGrade;
}

const int &Form::GetExecGrade() const
{
	return _execGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	if (_signed == true)
		throw FormAlreadySignedException();
	_signed = true;
}

const Form &Form::operator=(const Form &oder)
{
	if (this != &oder)
	{
		_signed = oder._signed;
		_signGrade = oder._signGrade;
		_execGrade = oder._execGrade;
	}
	return *this;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char *Form::FormAlreadySignedException::what() const throw()
{
	return "Form is already signed!";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Name		: " << form.GetName() << endl;
	out << "Signed		: " << (form.GetSigned() ? "Yes" : "No") << endl;
	out << "SignGrade	: " << form.GetSignGrade() << endl;
	out << "ExecGrade	: " << form.GetExecGrade();
	return out;
}
