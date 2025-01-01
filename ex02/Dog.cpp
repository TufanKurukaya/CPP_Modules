#include "Dog.hpp"

Dog::Dog() : Animal("Dog") , _brain(new Brain())
{
	cout << "I thought I saw a Dog." << endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) , _brain(new Brain(*copy._brain))
{
	cout << "I'm pretty sure I saw a Dog." << endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	if (this != &copy)
	{
		delete _brain;
		_brain = new Brain(*copy._brain);
		Animal::operator=(copy);
	}
	return *this;
}

void Dog::makeSound() const
{
	cout << "Woof!" << endl;
}

Dog::~Dog()
{
	delete _brain;
	cout << "Dog is Dead" << endl;
}

void Dog::printIdeas() const
{
	if (_brain->getIdea(0) == "I have no idea!")
	{
		cout << "Cat has no idea!" << endl;
	}
	else
	{
		for (size_t i = 0; i < 100; i++)
		{
			if (_brain->getIdea(i) != "I have no idea!")
			{
				cout << _brain->getIdea(i) << endl;
			}
		}
	}
}

void Dog::setBrain(const Brain &brain)
{
	_brain->setIdeas(brain.getIdea(0));
}

