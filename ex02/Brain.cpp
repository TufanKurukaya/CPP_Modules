#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain created!" << std::endl;
	for (size_t i = 0; i < 100; i++)
		_ideas[i] = "I have no idea!";
}

Brain &Brain::operator=(const Brain &copy)
{
	std::cout << "Brain assigned!" << std::endl;
	if (this == &copy)
		return *this;
	for (size_t i = 0; i < 100; i++)
			_ideas[i] = copy._ideas[i];
	return *this;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copied!" << std::endl;
	*this = copy;
}


Brain::~Brain()
{
	std::cout << "Brain destroyed!" << std::endl;
}

void Brain::setIdeas(string idea)
{
	for (size_t i = 0; i < 100; i++)
		_ideas[i] = idea;
}

string Brain::getIdea(size_t index) const
{
	if ( index >= 100)
		return "Index out of bounds!";
	return _ideas[index];
}

void Brain::setIdea(size_t index, string idea)
{
	if (index >= 100)
		return;
	_ideas[index] = idea;
}
