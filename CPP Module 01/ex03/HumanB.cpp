#include "HumanB.hpp"

HumanB::HumanB()
{
	return ;
}

HumanB::HumanB(str name)
{
	this->name = name;
	weapon = NULL;
}

HumanB::HumanB(const HumanB &copy)
{
	name = copy.getName();
	weapon = &(copy.getWeapon());
	return (*this);
}

HumanB::~HumanB()
{
	return ;
}

str	&HumanB::getName() const
{
	return (name);
}

Weapon	&HumanB::getWeapon() const
{
	return (*weapon);
}

void	HumanB::setWeapon(Weapon &wp)
{
	weapon = &wp;
}

void	HumanB::attack()
{
	std::cout	<< name << " attacks with their ";
	if (!weapon)
		std::cout	<< "hands\n";
	else
		std::cout	<< weapon << "\n"
}

HumanB &HumanB::operator =(const HumanB &copy)
{
	name = copy.getName();
	weapon = copy.getWeapon();
	return (*this);
}