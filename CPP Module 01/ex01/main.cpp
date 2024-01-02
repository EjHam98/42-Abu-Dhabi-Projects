#include "Zombie.hpp"

int	main()
{
	Zombie	ej = Zombie("Ej");
	Zombie	*horde;

	ej.announce();
	horde = ej.zombieHorde(5, "Pierce");
	
	int	i;
	for (i = 0; i < 5; i++)
		horde[i].announce();
	delete[] horde;
}