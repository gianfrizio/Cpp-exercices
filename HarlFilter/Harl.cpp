#include "Harl.hpp"
#include <iostream>

void Harl::debug(void) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    if (level == "DEBUG") debug();
    else if (level == "INFO") info();
    else if (level == "WARNING") warning();
    else if (level == "ERROR") error();
    else
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::filter(std::string level) {
    enum Level { DEBUG, INFO, WARNING, ERROR, UNKNOWN };
    Level lvl;

    if (level == "DEBUG") lvl = DEBUG;
    else if (level == "INFO") lvl = INFO;
    else if (level == "WARNING") lvl = WARNING;
    else if (level == "ERROR") lvl = ERROR;
    else lvl = UNKNOWN;

    switch (lvl) {
        case DEBUG:
            std::cout << "[ DEBUG ]" << std::endl;
            debug();
            [[fallthrough]];
        case INFO:
            std::cout << "[ INFO ]" << std::endl;
            info();
            [[fallthrough]];
        case WARNING:
            std::cout << "[ WARNING ]" << std::endl;
            warning();
            [[fallthrough]];
        case ERROR:
            std::cout << "[ ERROR ]" << std::endl;
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
