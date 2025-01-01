#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat bob("Bob", 2);
		cout << bob << endl;
		bob.incrementGrade();
		cout << "After increment: " << bob << endl;
		bob.incrementGrade();
	}
	catch (const std::exception &e) {
		cout << "Caught an exception: " << e.what() << endl;
	}
	
	cout << endl;

	try
	{
		Bureaucrat jim("Jim", 151);
		cout << jim << endl;
	}
	catch (const std::exception &e) {
		cout << "Caught an exception while creating Jim: " << e.what() << endl;
	}

	cout << endl;

	try
	{
		Bureaucrat alice("Alice", 149);
		cout << alice << endl;
		alice.decrementGrade();
		cout << "After decrement: " << alice << endl;
		alice.decrementGrade();
	}
	catch (const std::exception &e)
	{
		cout << "Caught an exception: " << e.what() << endl;
	}

	return 0;
}
