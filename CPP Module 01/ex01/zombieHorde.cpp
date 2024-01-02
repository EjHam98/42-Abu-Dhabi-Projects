#include "Zombie.hpp"

Zombie	*Zombie::zombieHorde( int N, str name )
{
	int		i;
	Zombie	*ret = new Zombie[N]();

	for (i = 0; i < N; i++)
		ret[i] = Zombie(name);
	return (ret);
}