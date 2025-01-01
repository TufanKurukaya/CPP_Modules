#include "Cat.hpp"

Cat::Cat() : Animal("Cat") , _brain(new Brain())
{
	cout << "I thought I saw a cat." << endl;
	for (size_t i = 0; i < 100; i++)
	{
		_brain->setIdea(i, "I have no idea!");
	}

}

Cat::Cat(const Cat &copy) : Animal(copy) , _brain(new Brain(*copy._brain))
{
	cout << "I'm pretty sure I saw a cat." << endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	if (this == &copy)
		return *this;
	delete _brain;
	_brain = new Brain(*copy._brain);
	Animal::operator=(copy);
	return *this;
}

void Cat::makeSound() const
{
	cout << "Meow!" << endl;
}

void Cat::setBrain(const Brain &brain)
{
	_brain->setIdeas(brain.getIdea(0));
}

void Cat::printIdeas() const
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

const string &Cat::getType(void) const
{
	return _type;
}

Cat::~Cat()
{
	delete _brain;
	cout << "Cat is Dead" << endl;
}
