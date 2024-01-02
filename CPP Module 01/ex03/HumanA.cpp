#include "HumanA.hpp"

HumanA::HumanA()
{
	return ;
}

HumanA::HumanA(str name, Weapon &wp)
{
	this->name = name;
	weapon = &wp;
}

HumanA::HumanA(const HumanA &copy)
{
	name = copy.getName();
	weapon = &(copy.getWeapon());
	return (*this);
}

HumanA::~HumanA()
{
	return ;
}

str	&HumanA::getName() const
{
	return (name);
}

Weapon	&HumanA::getWeapon() const
{
	return (*weapon);
}

void	HumanA::setWeapon(Weapon &wp)
{
	weapon = wp;
}

void	HumanA::attack()
{
	std::cout	<< name << " attacks with their " << weapon << "\n";
}

HumanA &HumanA::operator =(const HumanA &copy)
{
	name = copy.getName();
	weapon = &(copy.getWeapon());
	return (*this);
}
