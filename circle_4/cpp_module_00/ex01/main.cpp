#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook pb;
	bool	b_isExit;
	std::string command;

	while (1)
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "input EOF!!" << '\n';
			exit(1);
		}
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
			break ;
		}
		std::cout << "________________________" << '\n';
		std::cout << command;
		b_isExit = pb.input_command(command);
		if (b_isExit == false)
			break ;
		else std::cout << "________________________" << '\n';
	}
}