#include "Bureaucrat.hpp"
#include "AForm.hpp"
AForm::AForm() :	_name("Unnamed"),
				_signed(false),
				_signGrade(150),
				_execGrade(150)
{
}

AForm::AForm(const string &name, const int &signGrade, const int &execGrade) :	_name(name),
																				_signed(0)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	_signGrade = signGrade;
	_execGrade = execGrade;
}

AForm::AForm(const AForm &oder) :	_name(oder._name),
								_signed(oder._signed),
								_signGrade(oder._signGrade),
								_execGrade(oder._execGrade)
{
}

AForm::~AForm()
{
}

const string &AForm::GetName() const
{
	return _name;
}

bool AForm::GetSigned() const
{
	return _signed;
}

const int &AForm::GetSignGrade() const
{
	return _signGrade;
}

const int &AForm::GetExecGrade() const
{
	return _execGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	if (_signed == true)
		throw FormAlreadySignedException();
	_signed = true;
}

const AForm &AForm::operator=(const AForm &oder)
{
	if (this != &oder)
	{
		_signed = oder._signed;
		_signGrade = oder._signGrade;
		_execGrade = oder._execGrade;
	}
	return *this;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char *AForm::FormAlreadySignedException::what() const throw()
{
	return "Form is already signed!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &Aform)
{
	out << "Name		: " << Aform.GetName() << endl;
	out << "Signed		: " << (Aform.GetSigned() ? "Yes" : "No") << endl;
	out << "SignGrade	: " << Aform.GetSignGrade() << endl;
	out << "ExecGrade	: " << Aform.GetExecGrade();
	return out;
}

