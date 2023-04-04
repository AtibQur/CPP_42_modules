#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

enum eError {
    WRONG_VALUE = 1,
    NEGATIVE_VALUE = 2,
    TOO_BIG_VALUE = 3,
    INVALID_DATE = 4,
    INVALID_DATE_FORMAT = 5,
    INVALID_YEAR = 6,
    INVALID_MONTH = 7,
    INVALID_DAY = 8
};

class BitcoinExchange {
    private:
        std::string _filename;
        std::map<std::string, float> _database;

    public:
        BitcoinExchange();
        BitcoinExchange(std::string filename);
        BitcoinExchange(const BitcoinExchange &other);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &other);
    
        class DatabaseException : public std::exception {
            public:
                const char *what() const throw() { return "Couldn't open database"; }
        };
        class FileNotOpenException : public std::exception {
            public:
                const char *what() const throw() { return "Couldn't open file"; }
        };

        bool initDatabase();
        bool loadFile();
        int checkDate(std::string output, std::string line);
        int checkValue(std::string value);
        bool contains_only_alpha(const std::string& str);
        void printOutput(std::string line);
        float findExchangeRate(std::string date);
        std::string checkSpecificDate(std::string date);
        std::string errorMessage(std::string date);
        bool onlyNumbers(const std::string& str);

        void readDatabase();
};




#endif
