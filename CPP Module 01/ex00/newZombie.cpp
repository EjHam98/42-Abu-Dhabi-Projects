#include "Zombie.hpp"

Zombie	*Zombie::newZombie( str name )
{
	Zombie *z = new Zombie(name);
	return (z);
}