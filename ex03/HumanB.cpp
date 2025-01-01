#include "HumanB.hpp"

HumanB::HumanB(string name) : name(name), weapon(0) {}

HumanB::HumanB() {}

HumanB::~HumanB() {}

void HumanB::attack()
{
	if (name.empty())
	{
		cout << "HumanB has no name" << endl;
		return;
	}
	if(weapon == 0)
		cout << name << " attacks with his " << "naked hand" << endl;
	else
		cout << name << " attacks with his " << weapon->getType() << endl;
}

void HumanB::setWeapon(Weapon weapon)
{
	this->weapon = &weapon;
}
