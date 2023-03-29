#include "../inc/BitcoinExchange.hpp"

/*====================================OOCF==========================================================*/
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
/*================================================================================================*/

// INIT DATABASE FROM CSV FILE
bool BitcoinExchange::initDatabase() {
    std::ifstream file("data.csv");
    std::string   line;
    if (!file.is_open())
        return false;
    getline(file, line);
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string       token;
        std::vector<int>  keys;
        while (std::getline(ss, token, ',')) {
            keys.push_back(std::stoi(token));
        }
        float value;
        std::getline(ss, token, ',');
        value = std::stof(token);
        _database[keys] = value;
    }
    file.close();
    return true;
}
// LOAD DATA FROM INPUT.TXT
bool BitcoinExchange::loadfile() {
    std::ifstream file(_filename);
    std::string   line;
    if (!file.is_open())
        throw FileNotOpenException();
    getline(file, line);
    while (std::getline(file, line)) {
        checkFile(line);
        calculateValues(line);
    }
    file.close();
    return true;
}

// CHECK IF SYNTAX IS CORRECT FROM FILE AND COMPARE WITH DATABASE
void BitcoinExchange::checkFile(std::string line) {
    std::vector<int>         date;
    std::vector<std::string> output;

    splitString(line, '|', output);
    if (output.size() != 2)
        throw InvalidInputFile();

    splitString(output[0], '-', date);
    checkDate(output[0]);
    checkValue(output[1]);
}

void BitcoinExchange::checkDate(std::string date) {
    std::vector<int> dateVector;

    splitString(date, '-', dateVector);
    if (dateVector.size() != 3)
        throw InvalidDate();
    if (dateVector[0] < 2008 || dateVector[0] > 2023)
        throw InvalidDate();
    if (dateVector[1] < 1 || dateVector[1] > 12)
        throw InvalidDate();
    if (dateVector[2] < 1 || dateVector[2] > 31)
        throw InvalidDate();
}

void BitcoinExchange::checkValue(std::string value) {
    std::vector<int> valueVector;

    splitString(value, ' ', valueVector);
    if (valueVector.size() != 1)
        throw InvalidValue();
    if (valueVector[0] < 0)
        throw InvalidValue();
    if (valueVector[0] > 1000)
        throw InvalidValue();
}

// CALCULATE VALUES FROM INPUT.TXT
void BitcoinExchange::calculateValues(std::string line) {
    std::vector<std::string> date;

    splitString(line, '|', date);

    // std::cout << date[0] << " => " << date[1] << ' ' << getPrice(date) << std::endl;
}

// int BitcoinExchange::getPrice(std::vector<std::string> line) {

//     std::map<std::vector<int>, float>::iterator it = _database.find(line);

//     return 0;
// }

/*===========================================UTILS=============================================*/

// PRINT DATABASE CONTENTS
void BitcoinExchange::readDatabase() {
    for (std::map<std::vector<int>, float>::iterator it = _database.begin(); it != _database.end(); ++it) {
        const std::vector<int> &keys = it->first;
        float                  value = it->second;
        std::cout << "Keys: ";
        for (unsigned int i = 0; i < keys.size(); i++) {
            std::cout << keys[i] << " ";
        }
        std::cout << "Value: " << value << std::endl;
    }
}
