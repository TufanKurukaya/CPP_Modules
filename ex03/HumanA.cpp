#include "HumanA.hpp"

HumanA::HumanA(string name, Weapon &weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack()
{
	if (name.empty())
	{
		cout << "HumanA has no name" << endl;
		return;
	}
	cout << name << " attacks with his " << weapon.getType() << endl;
}
