#ifndef _PHONEBOOK
# define _PHONEBOOK

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contact[8];
		int index;
		bool	phonebook_add();
		bool	phonebook_search();
		bool 	phonebook_exit();
		bool	wrong_command();
	public:
		PhoneBook();
		bool	input_command(std::string command);
};

#endif