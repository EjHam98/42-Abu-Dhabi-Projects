#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <iostream>
#include "Weapon.hpp"

typedef std::string str;

class HumanB
{
	private:
		str		name;
		Weapon	*weapon;
		HumanB();
	public:
		HumanB(str name);
		HumanB(const HumanB &copy);
		~HumanB();

		Weapon	&getWeapon() const;
		str		&getName() const;
		void	attack();
		void	setWeapon(Weapon &wp);

		HumanB &operator =(const HumanB &copy);
};

#endif