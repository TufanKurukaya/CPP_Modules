#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &oder)
{
	*this = oder;
}

Intern &Intern::operator=(const Intern &oder)
{
	if (this != &oder)
		*this = oder;	
	return *this;
}

AForm *Intern::makeForm(string formName, string target)
{
	string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;
	while (i < 3 && formNames[i] != formName)
		++i;
	switch (i)
	{
		case 0:
			cout << "Intern creates " << formName << std::endl;
			return new ShrubberyCreationForm(target);
		case 1:
			cout << "Intern creates " << formName << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			cout << "Intern creates " << formName << std::endl;
			return new PresidentialPardonForm(target);
		default:
			cout << "Intern couldn't find the form: " << formName << std::endl;
			return NULL;
	}
	
}

Intern::~Intern()
{
}

