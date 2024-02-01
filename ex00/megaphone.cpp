#include <iostream>
#include <cstring>

void	put_upper_str(char *av)
{
	std::string str = av;
	for (size_t i = 0; i < str.length(); i++)
		putchar(toupper(str[i]));
}

void	print_args(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		if (i > 1)
			std::cout << " " ;
		put_upper_str(argv[i]);
	}
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		print_args(argc, argv);
	return (0);
}
