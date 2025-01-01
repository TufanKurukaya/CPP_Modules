#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap clapTrap("Grandpa");
	FragTrap fragTrap("Fraggy");

	clapTrap.attack("target");
	clapTrap.takeDamage(10);
	clapTrap.beRepaired(5);
	std::cout << clapTrap.getName() << std::endl;
	std::cout << clapTrap.getHitPoints() << std::endl;
	std::cout << clapTrap.getEnergyPoints() << std::endl;
	std::cout << clapTrap.getAttackDamage() << std::endl;

	fragTrap.attack("Big target");
	fragTrap.takeDamage(10);
	fragTrap.beRepaired(5);
	std::cout << fragTrap.getName() << std::endl;
	std::cout << fragTrap.getHitPoints() << std::endl;
	std::cout << fragTrap.getEnergyPoints() << std::endl;
	std::cout << fragTrap.getAttackDamage() << std::endl;
	fragTrap.highFivesGuys();
	fragTrap.takeDamage(100);
	clapTrap.takeDamage(100);
	return 0;
}
