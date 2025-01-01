#include "ClapTrap.hpp"

int main()
{
	ClapTrap bob("BOB");
	ClapTrap non("NON");
	ClapTrap coc(non);

	bob.attack("NON");
	non.takeDamage(5);
	non.beRepaired(3);

	return 0;
}
