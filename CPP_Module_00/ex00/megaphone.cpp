#include <iostream>

void	megaphone(int argc, char **argv)
{
	int	i = 1;
	int	j;

	while (argv[i] && argc > 0)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				argv[i][j] = toupper(argv[i][j]);
			std::cout << argv[i][j];
			j++;
		}
		i++;
		argc--;
	}
	std::cout << std::endl;
}

int	main(int argc, char **argv) {

	if (argc == 1)
		std:: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		megaphone(argc, argv);
	return (0);
}
