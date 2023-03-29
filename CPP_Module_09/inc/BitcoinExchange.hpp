#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

template <typename T>
void splitString(const std::string &s, char delim, std::vector<T> &vec) {
    std::string       item;
    std::stringstream ss(s);

    while (getline(ss, item, delim)) {
        T value;
        std::istringstream iss(item);
        iss >> value;
        vec.push_back(value);
    }
}

class BitcoinExchange {
    private:
        std::string _filename;
        std::map<std::vector<int>, float> _database;

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
        class InvalidInputFile : public std::exception {
            public:
                const char *what() const throw() { return "Invalid input.txt file"; }
        };
        class InvalidDate : public std::exception {
            public:
                const char *what() const throw() { return "Invalid date in input.txt file"; }
        };
        class InvalidValue : public std::exception {
            public:
                const char *what() const throw() { return "Invalid value in input.txt file"; }
        };

        bool initDatabase();
        bool loadfile();
        void checkFile(std::string line);
        void checkDate(std::string date);
        void checkValue(std::string value);
        void calculateValues(std::string line);
        int  getPrice(std::string line);

        void readDatabase();
};




#endif
