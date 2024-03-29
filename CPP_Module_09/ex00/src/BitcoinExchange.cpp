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
        if (line.empty())
            continue;
        printOutput(line);
    }
    file.close();
    return true;
}

void BitcoinExchange::printOutput(std::string line) {
    std::string         date;
    std::string         value;
    float               output;
    float               fvalue = 0.0;
    float               fexchangeRate = 0.0;

    date = line.substr(0, 10);
    if (checkDate(date, line) != 0) {
        std::cout << errorMessage(line) << std::endl;
        return;
    }

    date = checkSpecificDate(date);
    value = line.substr(11, line.size() - 1);
    if (onlyNumbers(value.substr(2, value.size() - 1)) == true) {
        fvalue = std::stof(value.substr(2, value.size() - 1));
    } else {
        std::cout << errorMessage(line) << std::endl;
        return;
    }

    fexchangeRate = findExchangeRate(date);
    output = (fvalue * fexchangeRate);
    if (checkValue(line.substr(11, line.size() - 1)) != 0) {
        std::cout << errorMessage(line) << std::endl;
        return;
    } else if (checkDate(line.substr(0, 10), line) != 0) {
        std::cout << errorMessage(line) << " => " << date << std::endl;
        return;
    }

    std::cout << date << " => " << fvalue << " = " << output << std::endl;
}

bool BitcoinExchange::onlyNumbers(const std::string& str) {
    for (unsigned int i = 0; i < str.size(); i++) {
        if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-') {
            return false;
        }
    }
    return true;
}

int BitcoinExchange::checkValue(std::string value) {
    std::string svalue = value.substr(2, value.size() - 1);

    if (onlyNumbers(svalue) == false)
        return WRONG_VALUE;
    if (value[0] != '|' || value[1] != ' ')
        return WRONG_VALUE;
    if (std::stof(svalue) < 0)
        return NEGATIVE_VALUE;
    if (std::stof(svalue) > 1000)
        return TOO_BIG_VALUE;
    return 0;
}

int BitcoinExchange::checkDate(std::string date, std::string line) {
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

    if (line.size() < 12)
        return INVALID_DATE_FORMAT;
    if (year.size() != 4 || month.size() != 2 || day.size() != 2)
        return INVALID_DATE;
    if (date[4] != '-' || date[7] != '-' || date[10] != '\0')
        return INVALID_DATE_FORMAT;
    if (std::stoi(year) > 2022 || std::stoi(year) < 2009)
        return INVALID_YEAR;
    if (std::stoi(month) > 12 || std::stoi(month) < 1)
        return INVALID_MONTH;
    if (std::stoi(day) > 31 || std::stoi(day) < 1)
        return INVALID_DAY;
    if (std::stoi(year) % 4 != 0 && std::stoi(month) == 02 && std::stoi(day) == 29)
        return INVALID_DAY;
    return 0;
}

std::string BitcoinExchange::errorMessage(std::string line) {
    if (checkDate(line.substr(0, 10), line) == INVALID_DATE)
        return "Error: Invalid date.";
    if (checkDate(line.substr(0, 10), line) == INVALID_DATE_FORMAT)
        return "Error: Invalid date.";
    if (checkDate(line.substr(0, 10), line) == INVALID_YEAR)
        return "Error: Invalid year.";
    if (checkDate(line.substr(0, 10), line) == INVALID_MONTH)
        return "Error: Invalid month.";
    if (checkDate(line.substr(0, 10), line) == INVALID_DAY)
        return "Error: Invalid day.";
    if (checkValue(line.substr(11, line.size() - 1)) == WRONG_VALUE)
        return "Error: Invalid value.";
    if (checkValue(line.substr(11, line.size() - 1)) == NEGATIVE_VALUE)
        return "Error: Not a positive number.";
    if (checkValue(line.substr(11, line.size() - 1)) == TOO_BIG_VALUE)
        return "Error: Too large a number.";
    return line;
}
// FIND EXCHANGE RATE FROM DATABASE
float BitcoinExchange::findExchangeRate(std::string date) {
    std::map<std::string, float>::iterator it = _database.find(date);
    if (it == _database.end())
        throw std::invalid_argument("Invalid date");
    return it->second;
}

std::string BitcoinExchange::checkSpecificDate(std::string date) {
    std::map<std::string, float>::iterator it;

    it = _database.find(date);
    if (it == _database.end()) {
        it = _database.lower_bound(date);
        it--;
    }
    return it->first;
}

/*===========================================UTILS=============================================*/
// PRINT DATABASE CONTENTS
void BitcoinExchange::readDatabase() {
    for (std::map<std::string, float>::iterator it = _database.begin(); it != _database.end(); ++it) {
        std::cout << it->first << " => " << it->second << '\n';
    }
}
