#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Unknown")
{
	cout << "WrongAnimal constructor called" << endl;
}

WrongAnimal::WrongAnimal(string type) : _type(type)
{
	cout << "WrongAnimal " << type << " is born" << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	cout << "WrongAnimal copy constructor called" << endl;
	_type = copy._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	if (this == &copy)
		return *this;
	_type = copy._type;
	return *this;
}

const string &WrongAnimal::getType(void) const
{
	return _type;
}

WrongAnimal::~WrongAnimal()
{
	cout << "WrongAnimal " << _type << " is Dead!" << endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Some generic Wronganimal sound!" << std::endl;
}
