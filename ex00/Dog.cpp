#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	cout << "I thought I saw a Dog." << endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	cout << "I'm pretty sure I saw a Dog." << endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	Animal::operator=(copy);
	return *this;
}

void Dog::makeSound() const
{
	cout << "Woof!" << endl;
}

Dog::~Dog()
{
	cout << "Dog is Dead" << endl;
}
