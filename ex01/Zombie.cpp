#include "Zombie.hpp"

Zombie::Zombie(std::string name) : Name(name)
{
	std::cout << Name << " Zombie constructor called" << std::endl;
}

Zombie::Zombie()
{
	std::cout << "Zombie constructor called" << std::endl;
}

Zombie::~Zombie()
{
	if (Name.empty())
		std::cout << "Zombie destructor called" << std::endl;
	else
		std::cout << Name << " Zombie destructor called" << std::endl;
}

void Zombie::setName(std::string name)
{
	Name = name;
}

void Zombie::announce()
{
	if (Name.empty())
		std::cout << "Unknown zombie: BraiiiiiiinnnzzzZ..." << std::endl;
	else
		std::cout << Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
