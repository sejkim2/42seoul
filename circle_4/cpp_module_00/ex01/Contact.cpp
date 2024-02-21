#include "Contact.hpp"

void	Contact::setFirstName()
{
	std::cout << "input first name >> ";
	std::getline(std::cin, first_name);
	MyIostream::ioError();
}

void	Contact::setLastName()
{
	std::cout << "input last name >> ";
	std::getline(std::cin, last_name);
	MyIostream::ioError();
}

void	Contact::setNickName()
{
	std::cout << "input nick name >> ";
	std::getline(std::cin, nickname);
	MyIostream::ioError();
}

void	Contact::setPhoneNumber()
{
	std::cout << "input phone number >> ";
	std::getline(std::cin, phone_number);
	MyIostream::ioError();
}

void 	Contact::setDarkestSecret()
{
	std::cout << "input darkest secret >> ";
	std::getline(std::cin, darkest_secret);
	MyIostream::ioError();
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