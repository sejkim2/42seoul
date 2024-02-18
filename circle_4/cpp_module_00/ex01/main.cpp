#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook pb;
	bool	b_isExit;
	std::string command;

	while (1)
	{
		std::cout << "input phonebook command >> ";
		std::cin >> command;
		if (std::cin.eof())
			break ;
		std::cout << "________________________" << '\n';
		b_isExit = pb.input_command(command);
		if (b_isExit == false)
			break ;
		else std::cout << "________________________" << '\n';
	}
}