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
        // print output
    }
    file.close();
    return true;
}

// CHECK IF SYNTAX IS CORRECT FROM FILE AND COMPARE WITH DATABASE
void BitcoinExchange::checkSyntax(std::string line) {
    std::string         date;
    std::string         value;

    date = line.substr(0, 10);
    value = line.substr(11, line.size() - 1);

    checkDate(date);
    checkValue(value);
}

/*===========================================UTILS=============================================*/
// PRINT DATABASE CONTENTS
void BitcoinExchange::readDatabase() {

    for (std::map<std::string, float>::iterator it = _database.begin(); it != _database.end(); ++it) {
        std::cout << it->first << " => " << it->second << '\n';
    }
}
