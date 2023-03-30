#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <vector>
#include<cstdio>
#define MAX_VALUE 1000 

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string const & file)
{
    try
    {
        getDatabase();
        parseInputFile(file);
    }
    catch (FileException & e) {
        std:: cout << e.what() << "\n";
        exit(1); }
   
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src ) { *this = src; }

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & o) {
    this->_data = o._data;
    return *this; 
}

BitcoinExchange::~BitcoinExchange() {}

/************************** PUBLIC MEMBER FUNCTION ****************************/

/* If file data.csv is valid, copy its contents to _data */
void    BitcoinExchange::getDatabase()
{
    std::string dbname = "data.csv";
    std::string line, date, key;
    
    //check if file is valid
    std::ifstream f(dbname.c_str());
    if (!f.good())
        throw(FileException());
    
    //parse each line from data.csv 
    //and stores it in container _data<std::string, float>
    std::getline(f, line);
    while (std::getline(f, line, ','))
    {
        key = line;
        getline(f,line);
        std::stringstream ss(line);
        float value;
        ss >> value;
        _data.insert(std::pair<std::string, float>(key, value));
    }
}

/*
    first, searches for a date match. If not found, searches for the 
    closest lower bound. 
*/
float    BitcoinExchange::findValue(std::string key)
{
    std::map<std::string, float>::iterator it;   
    
    it = _data.find(key);
    if (it != _data.end())
        return it->second;
    
    it = _data.lower_bound(key);
    if (it != _data.end()) {
        --it;
        return it->second;
    }
    return -1;  
}

bool    BitcoinExchange::verifyDateValue(std::string key)
{
    std::vector<int> data;
    std::istringstream f(key);
    std::string s;
    int num;
    int i = 0;
    while (getline(f, s, '-')) {
        if (i != 0 && s.size() != 2)
            return false;
        std::stringstream ss; 
        ss << s;
        ss >> num;
        data.push_back(num);
        i++;
    }
    std::time_t t = std::time(NULL);
    std::tm *const pTInfo = std::localtime(&t);
    int current_year = 1900 + pTInfo->tm_year;
    if (data[0] < 2009 || data[0] > current_year)
        return false;
    if (data[1] < 1 || data[1] > 12)
        return false;
    if (data[2] < 0 || data[2] > 31)
        return false;
    return true;
}

/* checks if date is in valid format yyyy-mm-dd */
bool   BitcoinExchange::parseKey(std::string & key)
{
    if (verifyDateValue(key)==false)
    {
        std::cerr << "Error: bad input => " << key << "\n";
        return false;
    }    
    char buffer [80];
    const char *str = key.c_str();
    struct tm tm;
    char *end = strptime(str, "%Y-%m-%d", &tm);

    if (end == NULL || *end != '\0' || !strftime(buffer,80,"%Y-%m-%d",&tm))
    {
        std::cerr << "Error: bad input => " << key << "\n";
        return false;
    }
    return true;
}

bool BitcoinExchange::parseValue(std::string const value) const
{
    std::stringstream ss(value);
    if (value.find_first_not_of("0123456789.") != std::string::npos)
    {
        int value;
        ss >> value;
        if (value == 0)
            return true;
        if (value < 0)
        {
            std::cerr << "Error: not a positive number.\n";
            return false;
        }
        std::cerr << "Error: only digit characters permitted.\n";
        return false;
    }
    int converted_value;
    ss >> converted_value;
    if (converted_value> MAX_VALUE)
    {
        std::cerr << "Error: too large a number.\n";
            return false;
    }
    return true;
}

void    BitcoinExchange::calculatePrice(std::string key, std::string value)
{
    std::stringstream s(value);
    float res;
    s >> res;
    if (res == -0 ) res *= -1;
    std::cout << key << " => " << res << " = " << res * findValue(key) << "\n";
}


void    BitcoinExchange::parseInputFile(std::string const & file)
{
    // checks if file exists and readable
    std::ifstream f(file.c_str());
    if (!f.good())
        throw(FileException());
    std::string line, date, key, value;

    // skips first line
    std::getline(f, line);
    // parses each line + calculates
    while(!f.eof())
    {
        std::getline(f,line);
        std::size_t delim = line.find(" | ");
        if (delim != std::string::npos)
        {
            // gets the date to look up in _data
            key = line.substr(0, delim);
            // if the date is valid
            if (parseKey(key))
            {
                // then gets the value to calculate
                value = line.substr(delim + 3, line.find('\n'));
                // if the value is valid then calculates it with
                // the corresponding date.
                if (parseValue(value))
                    calculatePrice(key, value);
            }
        }
        else
            std::cerr << "Error: invalid format => " << line << "\n";
    }
}

/************************** EXCEPTIONS ****************************************/
const char * BitcoinExchange::FileException::what() const throw() { return "Error: could not open file"; }
const char * BitcoinExchange::KeyException::what() const throw() { return "Error: invalid date"; }
const char * BitcoinExchange::BadInputException::what() const throw() { return "Error: bad input"; }
