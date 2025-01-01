#include "Contact.hpp"

string Contact::get_first_name() const
{
	return first_name;
}

string Contact::get_last_name() const
{
	return last_name;
}

string Contact::get_nickname() const
{
	return nickname;
}

string Contact::get_phone_number() const
{
	return phone_number;
}

string Contact::get_darkest_secret() const
{
	return darkest_secret;
}

string Contact::resize_string(string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str += ".";
	}
	return str;
}

void Contact::set_first_name(string first_name)
{
	this->first_name = first_name;
}


void Contact::set_last_name(string last_name)
{
	this->last_name = last_name;
}

void Contact::set_nickname(string nickname)
{
	this->nickname = nickname;
}

void Contact::set_phone_number(string phone_number)
{
	this->phone_number = phone_number;
}

void Contact::set_darkest_secret(string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

