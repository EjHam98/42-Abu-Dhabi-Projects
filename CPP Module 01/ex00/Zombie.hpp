#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

typedef std::string str;

class Zombie
{
	private:
		str	name;
		Zombie();
	public:
		Zombie(str name);
		Zombie(const Zombie &copy);
		~Zombie();

		str		getName( void ) const;
		void	announce( void );
		void	randomChump( str name );
		Zombie	*newZombie( str name );

		Zombie &operator =(const Zombie &copy);
};

#endif