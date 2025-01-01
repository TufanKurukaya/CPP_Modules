#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
}

Bureaucrat::Bureaucrat(const string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this == &copy)
		_grade = copy._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

string Bureaucrat::getName() const
{
	return _name;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char *Bureaucrat::FormAlreadySignedException::what() const throw()
{
	return "Form is already signed!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		cout << _name << " signed " << form.GetName() << endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn’t sign " << form.GetName() << " because " << e.what() << "." << endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		cout << _name << " executed " << form.GetName() << endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}
