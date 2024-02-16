#include "Contact.hpp"

void	Contact::setFirstName()
{
	std::cout << "input first name >> ";
	std::cin >> first_name;
}

void	Contact::setLastName()
{
	std::cout << "input last name >> ";
	std::cin >> last_name;
}

void	Contact::setNickName()
{
	std::cout << "input nick name >> ";
	std::cin >> nickname;
}

void	Contact::setPhoneNumber()
{
	std::cout << "input phone number >> ";
	std::cin >> phone_number;
}

void 	Contact::setDarkestSecret()
{
	std::cout << "input darkest secret >> ";
	std::cin >> darkest_secret;
}

std::string		Contact::getFirstName()
{
	return first_name;
}

std::string		Contact::getLastName()
{
	return last_name;
}

std::string		Contact::getNickName()
{
	return nickname;
}

std::string		Contact::getPhoneNumber()
{
	return phone_number;
}

std::string		Contact::getDarkestSecret()
{
	return darkest_secret;
}