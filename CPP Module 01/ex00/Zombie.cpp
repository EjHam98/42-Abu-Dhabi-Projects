#include "Zombie.hpp"

Zombie::Zombie()
{
	return ;
}

Zombie::Zombie(str name)
{
	this->name = name;
}

Zombie::Zombie(const Zombie &copy)
{
	this->name = copy.getName();
}

Zombie::~Zombie()
{
	std::cout	<< name << " died!\n";
}

str	Zombie::getName( void ) const
{
	return (this->name);
}

void	Zombie::announce( void )
{
	std::cout	<< name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie &Zombie::operator =(const Zombie &copy)
{
	this->name = copy.getName();
	return *this;
}
