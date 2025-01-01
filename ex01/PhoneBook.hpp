#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"



void safe_getline(string &str);

class PhoneBook
{
private:
	Contact contacts[8];
	int contact_count;
public:
	PhoneBook();
	void add_contact(Contact contact);
	void search_contact();
};




#endif

