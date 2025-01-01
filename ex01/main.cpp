#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap scavTrap("Tutmac");
	ClapTrap clapTrap("Brakmac");

	clapTrap.attack("target");
	clapTrap.takeDamage(10);
	clapTrap.beRepaired(5);
	std::cout << "Name          =: " << clapTrap.getName() << std::endl;
	std::cout << "Hit points    =: " << clapTrap.getHitPoints() << std::endl;
	std::cout << "Energy points =: " << clapTrap.getEnergyPoints() << std::endl;
	std::cout << "Attack damage =: " << clapTrap.getAttackDamage() << std::endl;
	scavTrap.attack("Big target");
	scavTrap.takeDamage(100);
	scavTrap.attack("");
	scavTrap.takeDamage(10);
	scavTrap.beRepaired(5);
	scavTrap.guardGate();
	std::cout << "Name          =: " << scavTrap.getName() << std::endl;
	std::cout << "Hit points    =: " << scavTrap.getHitPoints() << std::endl;
	std::cout << "Energy points =: " << scavTrap.getEnergyPoints() << std::endl;
	std::cout << "Attack damage =: " << scavTrap.getAttackDamage() << std::endl;
}
