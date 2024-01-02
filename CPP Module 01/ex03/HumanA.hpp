#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <iostream>
#include "Weapon.hpp"

typedef std::string str;

class HumanA
{
	private:
		str		name;
		Weapon	*weapon;
		HumanA();
	public:
		HumanA(str name, Weapon &wp);
		HumanA(const HumanA &copy);
		~HumanA();

		Weapon	&getWeapon() const;
		str		&getName() const;
		void	attack();
		void	setWeapon(Weapon &wp);

		HumanA &operator =(const HumanA &copy);
};

#endif