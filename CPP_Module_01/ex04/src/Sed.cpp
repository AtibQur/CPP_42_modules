#include "../inc/Sed.hpp"

std::string Sed::ChangeString(std::string line, std::string replace) {
	// int	i = 0;
	size_t	j = line.find(replace, 1);
	if (j != std::string::npos)
		std::cout << line <<j << std::endl;
	// int k = 0;
	// int l = 0;
	// std::string tmp;



	return (line);
}

int	Sed::CheckString(std::string line, std::string toFind) {
	bool found = line.find(toFind) != std::string::npos;
	if (found)
		return (1);
	else
		return (0);
}

void    Sed::ReplaceString(char **argv) {
    std::string     line;
    std::fstream    file;
    std::ofstream   fileReplaced("text.replace");

    file.open(argv[1], std::ios::in | std::ios::out);
    if (!file.is_open()) {
        std::cout << "Failed to open or use the file. Please check your file." << std::endl;
        return ;
    }
    while (getline(file, line)) {
        if (CheckString(line, argv[2]) == true)
		{
            line = ChangeString(line, argv[3]);
		}
        fileReplaced << line;
        if (file.eof() == false)
            fileReplaced << '\n';
    }
    file.close();
    fileReplaced.close();
}

Sed::~Sed() {}

Sed::Sed() {}