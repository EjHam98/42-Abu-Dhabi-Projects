#pragma once
#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

typedef std::string str;

class Contact
{
	private:
		str				first_name, last_name;
		str				nickname, secret;
		unsigned long	phone_number;
	public:
		Contact();
		Contact(str fn, str ln, str nick,
			unsigned long num, str secret);
		Contact(const Contact &copy);
		~Contact();

		void			setFirstName(str firstname);
		void			setLastName(str lastname);
		void			setNickname(str nickname);
		void			setSecret(str secret);
		void			setPhoneNumber(unsigned long num);
		void			Print(void);
		str				&getFirstName();
		str				&getLastName();
		str				&getNickname();
		str				&getSecret();
		unsigned long	&getPhoneNumber();

		Contact &operator =(const Contact &copy);
		friend std::ostream &operator <<(std::ostream &os,
			const Contact &c);
};

#endif