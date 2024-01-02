#include "utils.h"

int	alpha_str(str s)
{
	unsigned long	i;

	for (i = 0; i < s.length(); i++)
		if (!isalpha(s[i]) && s[i] != ' ' && s[i] != '\'' && s[i] != ',' && s[i] != '.')
			return (0);
	return (1);
}

str	strread(str msg = "", int proper = 0)
{
	unsigned long	i;
	str				ret;

	if (msg != "")
		std::cout	<< msg << "\n";
	std::cout	<< ">> ";
	std::getline(std::cin, ret);
	while(std::cin.fail() || !alpha_str(ret))
	{
		std::cout	<< "Error: Invalid input, please retry.\n";
		std::cout	<< ">> ";
		std::getline(std::cin, ret);
	}
	if (proper)
	{
		ret[0] = std::toupper(ret[0]);
		for (i = 1; i < ret.length(); i++)
			ret[i] = std::tolower(ret[i]);
	}
	return (ret);
}

long	ulread(str msg = "")
{
	long	ret;

	if (msg != "")
		std::cout	<< msg << "\n";
	std::cout	<< ">> ";
	std::cin	>> ret;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	while(std::cin.fail())
	{
		std::cout	<< ">> Error: Invalid input, please retry.\n";
		std::cout	<< ">> ";
		std::cin	>> ret;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	}
	return (ret);
}

str	read_input(void)
{
	unsigned long	i;
	str				ret	= "";

	std::cout	<< ">> Choose one of the following actions:\n";
	ret = strread(">> ADD, SEARCH, EXIT");
	for (i = 0; i < ret.length(); i++)
		ret[i] = std::toupper(ret[i]);
	while(ret != "ADD" && ret != "SEARCH" && ret != "EXIT")
	{
		std::cout	<< "Error: Invalid action, available actions:\n";
		ret = strread(">> ADD, SEARCH, EXIT");
		for (i = 0; i < ret.length(); i++)
			ret[i] = std::toupper(ret[i]);
	}
	return (ret);
}

void	read_contact(Contact &c)
{
	str		strret;
	long	ulret;

	strret = strread(">> Enter contact's First Name:", 1);
	while(strret.length() < 2)
		strret = strread("Error: First name can't be less than 2 characters.", 1);
	c.setFirstName(strret);
	strret = strread(">> Enter contact's Last Name:", 1);
	while(strret.length() < 2)
		strret = strread("Error: Last name can't be less than 2 characters.", 1);
	c.setLastName(strret);
	strret = strread(">> Enter contact's Nickname:", 1);
	while(strret.length() < 2)
		strret = strread("Error: Nickname can't be less than 2 characters.", 1);
	c.setNickname(strret);
	ulret = ulread(">> Enter contact's Phone Number:");
	while(ulret < 1)
		ulret = ulread("Error: Phone number can't be negative or zero.");
	c.setPhoneNumber(ulret);
	strret = strread(">> Enter contact's Deep Secret:", 1);
	while(strret.length() < 2)
		strret = strread("Error: Secret can't be less than 2 characters.", 1);
	c.setSecret(strret);
}
