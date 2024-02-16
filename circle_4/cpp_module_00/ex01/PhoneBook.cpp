#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
}

bool	PhoneBook::input_command(std::string command)
{
	if (command == "ADD")
		return (phonebook_add());
	else if (command == "SEARCH")
		return (phonebook_search());
	else if (command == "EXIT")
		return (phonebook_exit());
	else
		return (wrong_command());
}

bool	PhoneBook::phonebook_add()
{
	Contact new_contact;

	std::cout << "COMMAND : ADD" << std::endl;
	new_contact.setFirstName();
	new_contact.setLastName();
	new_contact.setNickName();
	new_contact.setPhoneNumber();
	new_contact.setDarkestSecret();
	
	contact[index] = new_contact;
	index = (index + 1) % 8;

	return (true);
}

bool	PhoneBook::phonebook_search()
{
	int index;
	std::cout << "COMMAND : SEARCH" << std::endl;
	while (1)
	{
		std::cout << "input phonebook index >> ";
		std::cin >> index;
		if (index < 0 || index > 7)
		{
			std::cout << "invalid index" << std::endl;
			break ;
		}
		std::cout << "index : " << index << std::endl;
		std::cout << '|' << std::endl;
		std::cout << "first name : " << contact[index].getFirstName() << std::endl;
		std::cout << '|' << std::endl;
		std::cout << "last name : " << contact[index].getLastName() << std::endl;
		std::cout << '|' << std::endl;
		std::cout << "nick name : " << contact[index].getNickName() << std::endl;
	}
	return (true);
}
		
bool 	PhoneBook::phonebook_exit()
{
	std::cout << "COMMAND : EXIT" << std::endl;
	std::cout << "The program quits" << std::endl;
	return (false);
}

bool	PhoneBook::wrong_command()
{
	std::cout << "Allow command list" << std::endl;
	std::cout << "1. ADD" << std::endl;
	std::cout << "2. SEARCH" << std::endl;
	std::cout << "3. EXIT" << std::endl;
	return (true);
}
