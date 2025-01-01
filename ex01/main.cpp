#include "Zombie.hpp"

int main()
{
	Zombie *zom = zombieHorde(5, "kent");
	for (int i = 0; i < 5; i++)
		zom[i].announce();
	delete[] zom;
}
