#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
}

void	PhoneBook::increase_index()
{
	index = (index + 1) % 8;
}

void	PhoneBook::phonebook_add()
{
	Contact new_contact;

	new_contact.setFirstName();
	new_contact.setLastName();
	new_contact.setNickName();
	new_contact.setPhoneNumber();
	new_contact.setDarkestSecret();
	
	contact[index] = new_contact;
	increase_index();
}

void	PhoneBook::phonebook_search()
{

}
		
void 	PhoneBook::phonebook_exit()
{

}
