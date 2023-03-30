#ifndef BITCOINEXCHANGE_HPP
 #define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
class BitcoinExchange
{
    public:
        BitcoinExchange(std::string const &);
        BitcoinExchange(BitcoinExchange const &);
        BitcoinExchange& operator=(BitcoinExchange const &);
        ~BitcoinExchange();

        class FileException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class BadInputException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class KeyException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        
        void    getDatabase();
        void    parseLine(std::string const & line);
        bool    parseKey(std::string & key);
        bool    verifyDateValue(std::string key);
        bool    parseValue(std::string const value) const;        
        float   findValue(std::string key);
        void    calculatePrice(std::string key, std::string value);
        void    parseInputFile(std::string const &);

    private:
        std::map<std::string, float> _data;

        BitcoinExchange();
};



#endif