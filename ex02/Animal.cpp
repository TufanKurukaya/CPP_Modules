#include "Animal.hpp"

Animal::Animal() : _type("Unknown")
{
	cout << "Animal constructor called" << endl;
}

Animal::Animal(string type) : _type(type)
{
	cout << "Animal " << type << " is born" << endl;
}

Animal::Animal(const Animal &copy)
{
	cout << "Animal copy constructor called" << endl;
	_type = copy._type;
}

Animal &Animal::operator=(const Animal &copy)
{
	if (this == &copy)
		return *this;
	_type = copy._type;
	return *this;
}

Animal::~Animal()
{
	cout << "Animal " << _type << " is Dead!" << endl;
}

void Animal::makeSound() const
{
	std::cout << "Some generic animal sound!" << std::endl;
}
