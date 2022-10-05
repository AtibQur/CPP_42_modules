#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>

class Sed
{
    public:
        Sed();
        ~Sed();

        void    SearchString(char **argv);
        void    ReplaceString(char **argv);

    private:
        std::string FileName;
        std::string SearchName;
        std::string ReplaceName;
};

    void    SearchString(char **argv);

#endif