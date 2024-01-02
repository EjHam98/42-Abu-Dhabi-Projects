#include "PhoneBook.hpp"
#include "utils.h"

int main(void)
{
	unsigned long	ind;
	str				choice;
	Contact			tmp = Contact();
	PhoneBook		pb = PhoneBook();

	choice = read_input();
	while (choice != "EXIT")
	{
		if (choice == "ADD")
		{
			read_contact(tmp);
			pb.Add(tmp);
		}
		if (choice == "SEARCH")
		{
			pb.Print();
			if (pb.getCount())
			{
				ind = ulread(">> Enter an id for a contact:");
				while (ind < 1 || (int)ind > pb.getCount())
					ind = ulread("Error: Invalid index.");
				pb.getContact(ind - 1).Print();
			}
		}
		choice = read_input();
	}
}

/******** EXAMPLE OF 8 CONTACTS ********/
/*
ADD
Emad Aldeen
Hammoude
The maker of this app
98123756
Prefer cats to dogs and think mice aren't cute
ADD
Pierce
Polintan
The Chicken Butt
6942002496
Doesn't know how to at all
ADD
PIOLO
polintan
pipo
1111111111
he's a freaking support main yuck
ADD
Taha
Helmy
thelmy why
9876543210
sucks at foosball and pretty much anything else, just no skill at all lol
ADD
alexandru
godeanu
The romanian warrior
0909090909
a lex luthor irl
ADD
sungju
kim
the point stealer
6661666
went around stealing points like the grinch before leaving the institution
ADD
wafiq
yAhYa
no man wallahi
1234567899
he'll supplex you then apologize
ADD
aisha
hashem
mechanical engineer number four
9182736455
WHERE EVEN IS SHE

*/