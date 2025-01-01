#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
int main()
{
	{
		HumanB T("Terorist");
		Weapon weap("M4A1");
		HumanA CT("Counter terorist", weap);
		CT.attack();
		weap.setType("AK-47");
		T.setWeapon(weap);
		T.attack();
	}
	return 0;
}
