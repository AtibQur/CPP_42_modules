#include "../inc/Sed.hpp"

std::string Sed::ChangeString(std::string line, std::string toFind, std::string replace) {
    std::string tmp;
    size_t i = 0;
    size_t end = 0;
    
    while (1) {
        end = line.find(toFind, i);             //Find index pos of toFind
        if (end == std::string::npos)           //Check with npos if Find has found
            break;                              

        tmp.append(line, i, end - i);           //Add everything before toFind to the string
        i = end + toFind.size();                //get new index size to change next toFind
        tmp.append(replace);                    //Add replace to the string
    }
        tmp.append(line, i);                    //Add the rest after of the string after toFind
    return (tmp);
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
            line = ChangeString(line, argv[2], argv[3]);
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