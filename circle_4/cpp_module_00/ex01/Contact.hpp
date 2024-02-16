#ifndef _CONTACT
# define _CONTACT

# include <iostream>
# include <string>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

	public:
		void	setFirstName();
		void	setLastName();
		void	setNickName();
		void	setPhoneNumber();
		void	setDarkestSecret();
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickName();
		std::string	getPhoneNumber();
		std::string	getDarkestSecret();
};

#endif