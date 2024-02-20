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

	std::cout << "COMMAND : ADD" << '\n';
	new_contact.setFirstName();
	new_contact.setLastName();
	new_contact.setNickName();
	new_contact.setPhoneNumber();
	new_contact.setDarkestSecret();
	
	if (new_contact.getFirstName().length() == 0 || \
		new_contact.getLastName().length() == 0 || \
		new_contact.getLastName().length() == 0 || \
		new_contact.getPhoneNumber().length() == 0 || \
		new_contact.getDarkestSecret().length() == 0)
	{
		std::cout << "A saved contact can't have empty fields" << '\n';
		return (false);
	}
	contact[index] = new_contact;
	index = (index + 1) % 8;

	return (true);
}

void	PhoneBook::print_property(std::string string)
{
	std::string print_string;

	print_string = string.substr(0, 9);
	if (string.length() > 9)
		print_string += ".";
	std::cout << std::setw(10) << print_string;
}

bool	PhoneBook::phonebook_search()
{
	std::cout << "COMMAND : SEARCH" << '\n';
	std::cout << "Display the saved contacts as a list of 4 columns" << '\n';
	for(int i = 0; i < 8; i++)
	{
		std::cout << i;
		std::cout << "|";
		print_property(contact[i].getFirstName());
		std::cout << "|";
		print_property(contact[i].getLastName());
		std::cout << "|";
		print_property(contact[i].getNickName());
		std::cout << "\n";
	}

	while (1)
	{
		std::string string_index;
		std::stringstream ss_index;
		int int_index;

		std::cout << "input phonebook index >> ";
		std::getline(std::cin, string_index);
		if (string_index.length() != 1)
		{
			std::cout << "invalid index" << '\n';
			return (true);
		}
		ss_index << string_index;
		ss_index >> int_index;
		if (int_index < 0 || int_index > 7)
		{
			std::cout << "invalid index" << '\n';
			return (true);
		}
		std::cout << "|";
		std::cout << int_index;
		std::cout << "|";
		print_property(contact[int_index].getFirstName());
		std::cout << "|";
		print_property(contact[int_index].getLastName());
		std::cout << "|";
		print_property(contact[int_index].getNickName());
		std::cout << "|";
		print_property(contact[int_index].getPhoneNumber());
		std::cout << "|";
		print_property(contact[int_index].getDarkestSecret());
		std::cout << "|";
		std::cout << "\n";
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
