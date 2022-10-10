#include "../inc/Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void    Harl::complain(std::string level) {
    const int cLevel = 4;

    std::string ComplainLevel[cLevel] = {
        "DEBUG", "INFO", "WARNING", "ERROR"
    };

    //void (Harll::*func_ptr(cLevel))
    func_ptr ArrayOfLevels[cLevel] = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    for (int i = 0; i < cLevel; i++) {
        if (ComplainLevel[i].compare(level) == 0) {
           (this->*(ArrayOfLevels[i]))();
            return ;
        }
    }
    std::cerr << "\033[1;31mWrong input.\033[0m\nTry: DEBUG, INFO, WARNING, ERROR" << std::endl;
}

void Harl::debug(void) {
    std::cout << "\033[1;32mDEBUG:\033[0m" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "\033[1;32mINFO:\033[0m" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "\033[1;32mWARNING:\033[0m" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "\033[1;32mERROR:\033[0m" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}