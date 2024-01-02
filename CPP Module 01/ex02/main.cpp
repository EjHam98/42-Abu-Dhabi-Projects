#include <iostream>

int	main()
{
	std::string	daOgString = "HI THIS IS BRAIN";
	std::string &stringREF = daOgString;
	std::string *stringPTR = &daOgString;

	std::cout	<< &daOgString << std::endl;
	std::cout	<< &stringREF  << std::endl;
	std::cout	<< stringPTR   << std::endl;

	std::cout	<< daOgString  << std::endl;
	std::cout	<< stringREF   << std::endl;
	std::cout	<< *stringPTR  << std::endl;
}