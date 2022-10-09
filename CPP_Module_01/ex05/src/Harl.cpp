#include "../inc/Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void    Harl::complain(std::string level) {
    const int cLevel = 4;

    std::string ComplainLevel[cLevel] 
    = {"DEBUG", "INFO", "WARNING", "ERROR"};

    func_ptr ArrayOfLevels[cLevel]
    = {
        &Harl::debug,
    };

    for (int i = 0; i < cLevel; i++) {
        if (ComplainLevel[i].compare(level) == 0) {
           (this->*(ArrayOfLevels[i]))();
            return ;
        }
    }
    std::cerr << "Wrong input, try again." << std::endl;

}

void debug(void) {
    std::cout << "DEBUG LEVEL:" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}