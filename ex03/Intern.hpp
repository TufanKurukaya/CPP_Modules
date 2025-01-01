#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include "AForm.hpp"

using std::endl;
using std::string;
using std::cout;

class Intern
{
	public:
		Intern();
		Intern(const Intern &);
		Intern &operator=(const Intern &);
		AForm *makeForm(string formName, string target);
		~Intern();
};


#endif
