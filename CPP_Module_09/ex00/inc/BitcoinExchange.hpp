#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

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
        void checkSyntax(std::string line);
        void checkDate(std::string output);
        void checkValue(std::string value);
        bool contains_only_alpha(const std::string& str);

        void readDatabase();
};




#endif
