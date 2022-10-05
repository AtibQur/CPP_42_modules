#include "../inc/Sed.hpp"


void    Sed::ReplaceString(char **argv) {
    std::string     line;
    std::fstream    file;
    std::ofstream    fileReplaced("text.replace");

    file.open(argv[1], std::ios::in | std::ios::out);
    if (!file.is_open()) {
        std::cout << "Failed to open or use the file. Please check your file." << std::endl;
        return ;
    }
    while (getline(file, line)) {
        if (line == argv[2])
            line = argv[3];
        fileReplaced << line << std::endl;
    }
    file.close();
    fileReplaced.close();
}

void    Sed::SearchString(char **argv) {
    std::fstream    file;
    std::string     line;
    std::string     temp;

    file.open(argv[1], std::ios::in | std::ios::out);
    if (!file.is_open()) {
        std::cout << "Failed to open or use the file. Please check your file." << std::endl;
        exit(1);
    }
    while (getline(file, line)) {
        if (line == argv[2])
            ReplaceString(argv);
    }
    file.close();
}

Sed::~Sed() {
}

Sed::Sed() {
}