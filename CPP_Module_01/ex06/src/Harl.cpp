#include "../inc/Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void    Harl::complain(std::string level) {
    const int cLevel = 5;
    int SwitchLevel = 0;

    std::string ComplainLevel[cLevel] = {
        "DEBUG", "INFO", "WARNING", "ERROR"
    };

    //void (Harll::*func_ptr(cLevel))
    func_ptr ArrayOfLevels[cLevel] = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
        &Harl::insignificantProblem
    };

    for (int i = 0; i < cLevel; i++) {
        if (ComplainLevel[i].compare(level) == 0) {
            break ;
        }
        SwitchLevel++;
    }

    switch(SwitchLevel)
    {
        case 0:
            (this->*(ArrayOfLevels[0]))();
            break;
        case 1:
            (this->*(ArrayOfLevels[1]))();
            break;
        case 2:
            (this->*(ArrayOfLevels[2]))();
            break;
        case 3:
            (this->*(ArrayOfLevels[3]))();
            break;
        default:
            (this->*(ArrayOfLevels[4]))();
    }       
}

void Harl::debug(void) {
    std::cout << "\033[1;32m[ DEBUG ]\033[0m" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "\033[1;32m[ INFO ]\033[0m" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "\033[1;32m[ WARNING ]\033[0m" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "\033[1;32m[ ERROR ]\033[0m" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::insignificantProblem(void) {
    std::cout << "\033[1;32m[ INSIGNIFICANT PROBLEM ]\033[0m" << std::endl;
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}