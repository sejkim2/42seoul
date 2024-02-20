#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook pb;
	bool	b_isExit;
	std::string command;

	while (1)
	{
		std::cout << "input phonebook command >> ";
		std::getline(std::cin, command);
		if (std::cin.fail())
		{
			if (std::cin.eof())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "input EOF!" << '\n';
				exit(1);
			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "cin error!" << '\n';
			exit(1);
		}
		b_isExit = pb.input_command(command);
		if (b_isExit == false)
			break ;
	}
}