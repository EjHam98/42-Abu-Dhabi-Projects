#include "Weapon.hpp"

Weapon::Weapon()
{
	return ;
}

Weapon::Weapon(str type)
{
	this->type = type;
}

Weapon::Weapon(const Weapon &copy)
{
	type = copy.getType();
	return (*this);
}

Weapon::~Weapon()
{
	return ;
}

str	&Weapon::getType() const
{
	return (type);
}

void	Weapon::setType(Weapon &wp)
{
	weapon = wp;
}

Weapon &Weapon::operator =(const Weapon &copy)
{
	type = copy.getType();
	return (*this);
}
