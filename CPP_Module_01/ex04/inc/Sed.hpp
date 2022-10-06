#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>

class Sed
{
    public:
        Sed();
        ~Sed();

        void    ReplaceString(char **argv);
        int     CheckString(std::string line, std::string toFind);
        std::string ChangeString(std::string line, std::string toFind, std::string replace);

    private:
};
    void        ReplaceString(char **argv);
    void        SearchString(char **argv);
    int         CheckString(std::string line, std::string toFind);
    std::string ChangeString(std::string line, std::string toFind, std::string replace);

#endif