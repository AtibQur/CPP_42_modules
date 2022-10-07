#include "../inc/Harl.hpp"

int	main(int argc, char **argv) {
	Harl *harl = new Harl;

	if (argc == 2)
		for (int i = 1; i < argc; i++) {
		if (argc > 1)
			harl->complain(argv[i]);
	}

	delete harl;
	return (0);
}