#include "../inc/Sed.hpp"

// void    ChangeString()

// int	Sed::CheckString(std::string line, std::string toFind) {


	
// 	return (0);
// }

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
        // if (CheckString(line, argv[2]) == true)
		// {
		// 	std::cout << "gang\n";
        //     line = argv[3];
		// }
		if (line == argv[2])
            line = argv[3];
        fileReplaced << line;
        if (file.eof() == false)
            fileReplaced << '\n';
    }
    file.close();
    fileReplaced.close();
}

Sed::~Sed() {}

Sed::Sed() {}