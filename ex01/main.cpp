#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	{
		try
		{
			Form form("Form", 1, 1);
			Bureaucrat bob("Bob", 2);
			bob.signForm(form);
			bob.incrementGrade();
			cout << bob << endl;
			cout << form << endl;
		}
		catch(const std::exception& e)
		{
			cout << e.what() << '\n';
		}
	}
	cout << endl;
	{
		try
		{
			Form form("Form", 1, 1);
			Bureaucrat bob("Bob", 1);
			bob.signForm(form);
			cout << bob << endl;
			cout << form << endl;
		}
		catch(const std::exception& e)
		{
			cout << e.what() << '\n';
		}
	}
	cout << endl;
	{
		try
		{
			Form form("Form", 150, 1);
			Bureaucrat bob("Bob", 150);
			bob.signForm(form);
			cout << bob << endl;
			cout << form << endl;
			bob.signForm(form);
		}
		catch(const std::exception& e)
		{
			cout << e.what() << '\n';
		}
	}


}
