#include "Weapon.hpp"

Weapon::Weapon(string type) : type(type) {}

Weapon::Weapon() : type("") {}

Weapon::~Weapon() {}

const string& Weapon::getType()
{
	return (type);
}

void Weapon::setType(string type)
{
	this->type = type;
}
