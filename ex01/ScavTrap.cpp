#include "ScavTrap.hpp"

void ScavTrap::guardGate()
{
	std::cout << PURPLE << "ScavTrap " << getName() << " has entered in Gate keeper mode." << RESET << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	_name = "ScavTrap";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << CYAN << "ScavTrap default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << CYAN << "ScavTrap name constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	std::cout << YELLOW << "ScavTrap copy constructor called" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << YELLOW << "ScavTrap assignation operator called" << RESET << std::endl;
	ClapTrap::operator=(copy);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << ORANGE << "ScavTrap destructor called" << RESET << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_energyPoints == 0 || _hitPoints == 0)
		std::cout << RED << "ScavTrap " << _name << " is not ready to attack!" << RESET << std::endl;
	else
	{
		std::cout << PURPLE << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
		_energyPoints--;
	}
}
