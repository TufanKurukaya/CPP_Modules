#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << ORANGE << "ClapTrap default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << ORANGE << "ClapTrap name constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << GREEN << "ClapTrap copy constructor called" << RESET << std::endl;
	_name = copy._name;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << GREEN <<"ClapTrap assignation operator called" << RESET << std::endl;
	_name = copy._name;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
	return *this;
}

void ClapTrap::attack(std::string const &target)
{
	if (_energyPoints == 0 || _hitPoints == 0)
	{
		std::cout << RED << "ClapTrap " << _name << " is not ready to attack!" << RESET << std::endl;
		return;
	}
	std::cout << RED << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << RED << _name << " is already dead!" << RESET << std::endl;
		return;
	}
	else if (amount >= _hitPoints)
	{
		std::cout << RED << _name << " is dead!" << RESET << std::endl;
		_hitPoints = 0;
		return;
	}
	else if (amount == 0)
	{
		std::cout << RED << _name << " takes no damage!" << RESET << std::endl;
		return;
	}
	std::cout << RED << _name << " takes " << amount << " points of damage!" << RESET << std::endl;
	_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints == 0 || _hitPoints == 0)
	{
		std::cout << RED << _name << " is not ready to be repaired!" << RESET << std::endl;
		return;
	}
	else if (amount == 0)
	{
		std::cout << RED << _name << " takes no repair!" << RESET << std::endl;
		return;
	}
	std::cout << RED << _name << " is repaired for " << amount << " points!" << RESET << std::endl;
	_energyPoints--;
	_hitPoints += amount;
}

ClapTrap::~ClapTrap()
{
	std::cout << BLUE << "ClapTrap destructor called" << RESET << std::endl;
}

std::string ClapTrap::getName() const
{
	return _name;
}

int ClapTrap::getHitPoints() const
{
	return _hitPoints;
}

int ClapTrap::getEnergyPoints() const
{
	return _energyPoints;
}

int ClapTrap::getAttackDamage() const
{
	return _attackDamage;
}
