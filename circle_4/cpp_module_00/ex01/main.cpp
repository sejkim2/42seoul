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
		std::cout << "________________________" << std::endl;
		b_isExit = pb.input_command(command);
		if (b_isExit == false)
			break ;
		std::cout << "________________________" << std::endl;
	}
}