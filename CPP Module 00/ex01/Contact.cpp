#include "Contact.hpp"

Contact::Contact()
{
	this->first_name	= "John";
	this->last_name		= "Doe";
	this->nickname		= "Nobody";
	this->secret		= "Nothing";
	this->phone_number	= 123456789;
}

Contact::Contact(str fn, str ln, str nick, unsigned long num, str secret)
{
	this->first_name	= fn;
	this->last_name		= ln;
	this->nickname		= nick;
	this->secret		= secret;
	this->phone_number	= num;
}

Contact::Contact(const Contact &copy)
{
	*this = copy;
}

void	Contact::setFirstName(str firstname)
{
	first_name = firstname;
}

void	Contact::setLastName(str lastname)
{
	last_name = lastname;
}

void	Contact::setNickname(str nickname)
{
	this->nickname = nickname;
}

void	Contact::setPhoneNumber(unsigned long num)
{
	phone_number = num;
}

void	Contact::setSecret(str secret)
{
	this->secret = secret;
}

str	&Contact::getFirstName()
{
	return (first_name);
}

str	&Contact::getLastName()
{
	return (last_name);
}

str	&Contact::getNickname()
{
	return (nickname);
}

str	&Contact::getSecret()
{
	return (secret);
}

unsigned long	&Contact::getPhoneNumber()
{
	return (phone_number);
}

void	Contact::Print(void)
{
	std::cout << "---------------------------------------\n";
	std::cout << "First Name:\t" << first_name << "\n";
	std::cout << "Last Name:\t" << last_name << "\n";
	std::cout << "Nickame:\t" << nickname << "\n";
	std::cout << "Secret:\t\t" << secret << "\n";
	std::cout << "Phone Number:\t" << std::setw(10)
		<< std::setfill('0') << phone_number << "\n";
	std::cout << std::setfill(' ');
	std::cout << "---------------------------------------\n";
}

Contact &Contact::operator =(const Contact &copy)
{
	this->first_name	= copy.first_name;
	this->last_name		= copy.last_name;
	this->nickname		= copy.nickname;
	this->secret		= copy.secret;
	this->phone_number	= copy.phone_number;
	return *this;
}

std::ostream &operator <<(std::ostream &os, const Contact &c)
{
	if (c.first_name.length() > 10)
		os << "|" << c.first_name.substr(0, 9) << ".";
	else
		os << "|" << std::setw(10) << c.first_name;
	if (c.last_name.length() > 10)
		os << "|" << c.last_name.substr(0, 9) << ".";
	else
		os << "|" << std::setw(10) << c.last_name;
	if (c.nickname.length() > 10)
		os << "|" << c.nickname.substr(0, 9) << ".";
	else
		os << "|" << std::setw(10) << c.nickname;
	os << "|" << std::setw(10) << std::setfill('0') << c.phone_number;
	os << std::setfill(' ');
	if (c.secret.length() > 10)
		os << "|" << c.secret.substr(0, 9) << ".";
	else
		os << "|" << std::setw(10) << std::setfill(' ') << c.secret;
	os << "|\n";
	return (os);
}

Contact::~Contact()
{
	return ;
}
