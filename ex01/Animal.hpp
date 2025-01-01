#pragma once

#include <iostream>

using std::cout;
using std::endl;
using std::string;

#define ORANGE "\033[38;5;208m"
#define GREEN "\033[38;5;41m"
#define BLUE "\033[38;5;27m"
#define RED "\033[38;5;160m"
#define YELLOW "\033[38;5;226m"
#define PURPLE "\033[38;5;92m"
#define CYAN "\033[38;5;51m"
#define RESET "\033[0m"

class Animal
{
	protected:
		string _type;

	public:
		Animal();
		Animal(string type);
		Animal(const Animal &copy);
		Animal &operator=(const Animal &copy);
		virtual ~Animal();
		const string &getType() const;
		virtual void makeSound() const;
};
