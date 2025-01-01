#include "PhoneBook.hpp"
#include <stdexcept>

void safe_getline(string &str)
{
	getline(cin, str);
	if (cin.eof() || cin.fail())
	{
		cout << endl;
		throw std::invalid_argument("Cin EOF or fail");
	}
}

void commad_add(PhoneBook &ref)
{
	Contact new_contact;
	string	tmp;

	while (true)
	{
		cout << "\033[1;32mEnter a first name: \033[0m";
		safe_getline(tmp);
		new_contact.set_first_name(tmp);
		cout << "\033[1;32mEnter a last name: \033[0m";
		safe_getline(tmp);
		new_contact.set_last_name(tmp);
		cout << "\033[1;32mEnter a nickname: \033[0m";
		safe_getline(tmp);
		new_contact.set_nickname(tmp);
		cout << "\033[1;32mEnter a phone number: \033[0m";
		safe_getline(tmp);
		new_contact.set_phone_number(tmp);
		cout << "\033[1;32mEnter a darkest secret: \033[0m";
		safe_getline(tmp);
		new_contact.set_darkest_secret(tmp);
		if (new_contact.get_first_name() == "" || new_contact.get_last_name() == "" || new_contact.get_nickname() == ""
			|| new_contact.get_phone_number() == "" || new_contact.get_darkest_secret() == "")
		{
			cout << "\033[1;31mInvalid input, please enter a valid input.\033[0m" << endl;
			continue;
		}
		else
		{
			ref.add_contact(new_contact);
			break;
		}
	}
}

int main()
{
	PhoneBook phone_book;
	string command;
	try
	{
		cout << "\033[2J\033[H" << endl;
		while (true)
		{
			cout << "\033[1;36mEnter a command: \033[0m";

			safe_getline(command);
			if (command == "EXIT")
				break;
			else if (command == "ADD")
			{
				commad_add(phone_book);
			}
			else if (command == "SEARCH")
			{
				phone_book.search_contact();
			}
			else
				cout << "\033[1;31mInvalid command, please enter a valid command.\033[0m" << endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(...)
	{
		std::cerr << "Unknown exception" << '\n';
	}
}
