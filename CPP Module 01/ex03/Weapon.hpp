#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

typedef std::string str;

class Weapon
{
	private:
		str	type;
		Weapon();
	public:
		Weapon(str name);
		Weapon(const Weapon &copy);
		~Weapon();

		str		&getType() const;
		void	setType(str type);

		Weapon &operator =(const Weapon &copy);
};

#endif