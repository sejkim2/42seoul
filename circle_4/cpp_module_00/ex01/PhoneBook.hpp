#ifndef _PHONEBOOK
# define _PHONEBOOK

# include "Contact.hpp"
# include <iomanip>

class PhoneBook
{
	private:
		Contact contact[8];
		int index;
		bool	phonebook_add();
		bool	phonebook_search();
		bool 	phonebook_exit();
		bool	wrong_command();
		void	print_property(std::string string);
	public:
		PhoneBook();
		bool	input_command(std::string command);
};

#endif