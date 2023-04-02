#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    if (!initDatabase())
        throw DatabaseException();
}

BitcoinExchange::BitcoinExchange(std::string filename) : _filename(filename) {
    if (!initDatabase())
        throw DatabaseException();
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this == &other)
        return *this;
    return *this;
}

// INIT DATABASE FROM CSV FILE
bool BitcoinExchange::initDatabase() {
    std::string      line;
    std::string      key;
    std::string      exchangeRate;
    float            value;

    std::ifstream file("data.csv");
    if (!file.is_open())
        throw DatabaseException();

    getline(file, line);
    while (std::getline(file, line)) {
        key = line.substr(0, 10);
        exchangeRate = line.substr(11, line.size() - 1);
        value = std::stof(exchangeRate);
        this->_database[key] = value;
    }
    file.close();
    return true;
}

// LOAD DATA FROM INPUT.TXT
bool BitcoinExchange::loadFile() {
    std::ifstream file(_filename);
    std::string   line;
    if (!file.is_open())
        throw FileNotOpenException();
    getline(file, line);
    while (std::getline(file, line)) {
        checkSyntax(line);
    //     // print output
    }
    file.close();
    return true;
}

// CHECK IF SYNTAX IS CORRECT FROM FILE AND COMPARE WITH DATABASE
void BitcoinExchange::checkSyntax(std::string line) {
    std::string         date;

    checkDate(line.substr(0, 10));
    checkValue(line.substr(11, line.size() - 1));
}

void BitcoinExchange::checkDate(std::string date) {
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

    if (year.size() != 4 || month.size() != 2 || day.size() != 2)
        throw std::invalid_argument("Invalid date");
    if (date[4] != '-' || date[7] != '-' || date[10] != '\0')
        throw std::invalid_argument("Invalid date");
    if (std::stoi(year) > 2022 || std::stoi(year) < 2009)
        throw std::invalid_argument("Invalid year");
    if (std::stoi(month) > 12 || std::stoi(month) < 1)
        throw std::invalid_argument("Invalid month");
    if (std::stoi(day) > 31 || std::stoi(day) < 1)
        throw std::invalid_argument("Invalid day");
}

void BitcoinExchange::checkValue(std::string value) {
    std::string svalue = value.substr(2, value.size() - 1);

    if (value[0] != '|' || value[1] != ' ')
        throw std::invalid_argument("Invalid value");
    if (std::stof(svalue) < 0)
        throw std::invalid_argument("Invalid value");
    if (std::stof(svalue) > 2147483647)
        throw std::invalid_argument("Invalid value");
}

/*===========================================UTILS=============================================*/
// PRINT DATABASE CONTENTS
void BitcoinExchange::readDatabase() {
    for (std::map<std::string, float>::iterator it = _database.begin(); it != _database.end(); ++it) {
        std::cout << it->first << " => " << it->second << '\n';
    }
}
