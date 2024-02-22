#include "PhoneBook.hpp"

void leaks()
{
	system("leaks phonebook");
}

int main(void)
{
	atexit(leaks);
	PhoneBook pb;
	bool	b_isExit;
	std::string command;

	while (1)
	{
		std::cout << "input phonebook command >> ";
		std::getline(std::cin, command);
		MyIostream::ioError();
		b_isExit = pb.input_command(command);
		if (b_isExit == false)
			break ;
	}
	exit(1);
}