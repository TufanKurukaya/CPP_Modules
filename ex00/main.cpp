#include "Zombie.hpp"

int main()
{
	{
		Zombie zom("CLARC");
		randomChump("Karen");
		zom.announce();
	}
	{
		std::cout << "---------------------------------" << std::endl;
		Zombie zom;
		zom.announce();
		zom.setName("Nancy");
		zom.announce();
	}
	{
		std::cout << "---------------------------------" << std::endl;
		Zombie *zom = newZombie("kent");
		zom->announce();
		delete zom;
		randomChump("Karen");
	}
	{
		std::cout << "---------------------------------" << std::endl;
		Zombie("Melina").announce();
		Zombie zom("Dead");
		zom.announce();
	}
}
