#pragma once
#ifndef UTILS_H
#define UTILS_H

# include "PhoneBook.hpp"
# include <limits>

str		read_input(void);
long	ulread(str msg);
str		strread(str msg, int proper);
void	read_contact(Contact &c);

#endif