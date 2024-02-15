#ifndef _PHONEBOOK
# define _PHONEBOOK

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contact[8];
		int index;
		void	increase_index();
	public:
		PhoneBook();
		void	phonebook_add();
		void	phonebook_search();
		void 	phonebook_exit();
};

#endif