#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	cnt		= 0;
	curr	= 0;
}

PhoneBook::PhoneBook(Contact list[8])
{
	cnt = 8;
	for (curr = 0; curr < 8; curr++)
		this->list[curr] = list[curr];
	curr = 0;
}

PhoneBook::PhoneBook(const PhoneBook &copy)
{
	*this = copy;
}

int	&PhoneBook::getCount()
{
	return (cnt);
}

Contact	&PhoneBook::getContact(int ind)
{
	return (list[ind]);
}

void	PhoneBook::Add(Contact c)
{
	if (cnt < 8)
		cnt++;
	list[curr] = c;
	curr = (curr + 1) % 8;
}

void	PhoneBook::Print(void)
{
	std::cout << *this;
}

PhoneBook &PhoneBook::operator =(const PhoneBook &copy)
{
	cnt = copy.cnt;
	for (curr = 0; curr < cnt; curr++)
		list[curr] = copy.list[curr];
	curr %= 8;
	return *this;
}

std::ostream &operator <<(std::ostream &os, const PhoneBook &c)
{
	int	i;

	if (!c.cnt)
		os << "Phonebook is empty!\n";
	else
	{
		os << " |First Name";
		os << "| Last Name";
		os << "|  Nickname";
		os << "|     Phone";
		os << "|    Secret|\n";
		for (i = 0; i < c.cnt; i++)
			os << i + 1 << c.list[i];
	}
	return (os);
}

PhoneBook::~PhoneBook()
{
	return ;
}
