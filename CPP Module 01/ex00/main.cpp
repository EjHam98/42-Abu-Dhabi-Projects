#include "Zombie.hpp"

int	main()
{
	Zombie	ej = Zombie("Ej");
	Zombie	*ham;

	ej.announce();
	ej.randomChump("Pierce");
	ham = ej.newZombie("Ham");
	ham->announce();
	delete ham;
}