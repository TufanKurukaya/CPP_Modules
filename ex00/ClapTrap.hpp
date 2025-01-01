#pragma once

#include <iostream>

#define ORANGE "\033[38;5;208m"
#define GREEN "\033[38;5;41m"
#define BLUE "\033[38;5;27m"
#define RED "\033[38;5;160m"
#define YELLOW "\033[38;5;226m"
#define PURPLE "\033[38;5;92m"
#define CYAN "\033[38;5;51m"
#define RESET "\033[0m"

class ClapTrap
{
	protected:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
	public:
		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator=(const ClapTrap& copy);
		void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName() const;
		int getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;
		~ClapTrap();
};

