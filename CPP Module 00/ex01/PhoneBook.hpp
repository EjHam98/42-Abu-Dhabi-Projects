#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

typedef std::string str;

class PhoneBook
{
	private:
		int		cnt;
		int		curr;
		Contact	list[8];
	public:
		PhoneBook();
		PhoneBook(Contact list[8]);
		PhoneBook(const PhoneBook &copy);
		~PhoneBook();

		int		&getCount();
		void	Print(void);
		void	Add(Contact c);
		Contact	&getContact(int ind);

		PhoneBook &operator =(const PhoneBook &copy);
		friend std::ostream &operator <<(std::ostream &os,
			const PhoneBook &c);
};

#endif