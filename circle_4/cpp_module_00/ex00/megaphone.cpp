#include <iostream>

static	void	print_char(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		ch = ch - 'a' + 'A';
	std::cout << ch;
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for(int i = 1; i<argc; i++)
		{
			int j = 0;
			while (argv[i][j])
			{
				print_char(argv[i][j]);
				j++;
			}
		}
	}
	std::cout << std::endl;
}
