#include "../inc/Sed.hpp"

int	checkWrongArgument(std::string const filename, std::string const arg1, std::string const arg2) {
	if (filename.empty() || arg1.empty() || arg2.empty()) {
		std::cerr << "Error: empty argument." << std::endl;
		return 0;
	}
	return (1);
}

int main(int argc, char **argv) {
	Sed replace;

	if (argc != 4) {
		std::cout << "Error, please try again with 3 arguments." << std::endl;
		std::cout << "Arguments should be: Text file, Search text, Replace text" << std::endl;
		return (1);
	}
	else
	{
		if (checkWrongArgument(argv[0], argv[1], argv[2]) == 1)
			replace.ReplaceString(argv);
		return (0);
	}
}