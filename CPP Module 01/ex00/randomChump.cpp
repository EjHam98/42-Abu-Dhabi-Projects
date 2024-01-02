#include "Zombie.hpp"

void	Zombie::randomChump( str name )
{
	Zombie z = Zombie(name);
	z.announce();
}