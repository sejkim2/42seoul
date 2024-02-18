#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 1;
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

	std::cout << "COMMAND : ADD" << '\n';
	new_contact.setFirstName();
	new_contact.setLastName();
	new_contact.setNickName();
	new_contact.setPhoneNumber();
	new_contact.setDarkestSecret();
	
	contact[index] = new_contact;
	index = (index + 1) % 8;

	return (true);
}

void	PhoneBook::print_property(std::string string)
{
	std::string print_string;

	print_string = string.substr(0, 10);
	if (string.length() > 10)
		print_string += ".";
	std::cout << std::setw(10) << print_string << '\n';
}

bool	PhoneBook::phonebook_search()
{
	int index;
	std::cout << "COMMAND : SEARCH" << '\n';
	while (1)
	{
		std::cout << "input phonebook index >> ";
		std::cin >> index;
		if (std::cin.eof())
			return (false);
		if (std::cin.fail() || index < 1 || index > 8)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (std::cin.eof())
				return (false);
			std::cout << "invalid index" << '\n';
			return (true);
		}
		std::cout << "index : " << index << '\n';
		std::cout << '|' << '\n';
		std::cout << "first name : ";
		print_property(contact[index].getFirstName());
		std::cout << '|' << '\n';
		std::cout << "last name : ";
		print_property(contact[index].getLastName());
		std::cout << '|' << '\n';
		std::cout << "nick name : ";
		print_property(contact[index].getNickName());
	}
}
		
bool 	PhoneBook::phonebook_exit()
{
	std::cout << "COMMAND : EXIT" << '\n';
	std::cout << "The program quits" << '\n';
	return (false);
}

bool	PhoneBook::wrong_command()
{
	std::cout << "Allow command list" << '\n';
	std::cout << "1. ADD" << '\n';
	std::cout << "2. SEARCH" << '\n';
	std::cout << "3. EXIT" << '\n';
	return (true);
}
