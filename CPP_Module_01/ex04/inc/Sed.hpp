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
        void    SearchString(char **argv);

    private:
};
    void    ReplaceString(char **argv);
    void    SearchString(char **argv);

#endif