#ifndef _TEST
# define _TEST

# include <iostream>

class PhoneBook
{
	private: 
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

	public:
		void phonebook_add();
		void phonebook_search();
		void phonebook_exit();
};

#endif