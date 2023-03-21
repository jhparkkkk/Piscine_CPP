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
        bool    parseValue(std::stringstream & value);
        
        float   findValue(std::string key);
        void    parseInputFile(std::string const &);

    private:
        std::map<std::string, float> _data;

        BitcoinExchange();
};



#endif