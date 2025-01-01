#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	cout << "I thought I saw a Wrongcat." << endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	cout << "I'm pretty sure I saw a Wrongcat." << endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	WrongAnimal::operator=(copy);
	return *this;
}

void WrongCat::makeSound() const
{
	cout << "Meow!" << endl;
}

WrongCat::~WrongCat()
{
	cout << "WrongCat is Dead" << endl;
}
