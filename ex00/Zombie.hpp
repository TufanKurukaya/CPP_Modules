#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string Name;
public:
	Zombie( std::string name );
	Zombie();
	~Zombie();
	void setName( std::string name );
	void announce( void );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
