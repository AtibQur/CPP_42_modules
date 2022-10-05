#include "../inc/Sed.hpp"

int main(int argc, char **argv) {

	std::fstream file;

	if (argc != 4) {
		std::cout << "Error, please try again with 3 arguments." << std::endl;
		std::cout << "Arguments should be: Text file, Search text, Replace text" << std::endl;
		return (1);
	}
	else
	{
		file.open(argv[1]);
		return (0);
	}
}