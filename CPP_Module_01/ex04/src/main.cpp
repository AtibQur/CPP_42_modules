#include "../inc/Sed.hpp"

int main(int argc, char **argv) {
	Sed replace;

	if (argc != 4) {
		std::cout << "Error, please try again with 3 arguments." << std::endl;
		std::cout << "Arguments should be: Text file, Search text, Replace text" << std::endl;
		return (1);
	}
	else
	{
		replace.ReplaceString(argv);
		return (0);
	}
}