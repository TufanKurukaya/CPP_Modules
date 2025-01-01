#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_name = "FragTrap";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << CYAN << "FragTrap default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << CYAN << "FragTrap name constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << YELLOW << "FragTrap copy constructor called" << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	std::cout << YELLOW << "FragTrap assignation operator called" << RESET << std::endl;
	ClapTrap::operator=(copy);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << ORANGE << "FragTrap destructor called" << RESET << std::endl;
}

void FragTrap::highFivesGuys()
{
	if (_energyPoints == 0 || _hitPoints == 0)
	{
		std::cout << PURPLE << "FragTrap " << _name << " is not ready to high five!" << RESET << std::endl;
		return;
	}
	std::cout << PURPLE << "FragTrap " << _name << " requests a high five!" << RESET << std::endl;
}
