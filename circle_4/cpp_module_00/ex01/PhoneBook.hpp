#ifndef _PHONEBOOK
# define _PHONEBOOK

# include "Contact.hpp"
# include <iostream>

class PhoneBook
{
	private:
		Contact contact[8];
		int index;
	public:
		PhoneBook();
		void	phonebook_add();
		void	phonebook_search();
		void 	phonebook_exit();
};

#endif