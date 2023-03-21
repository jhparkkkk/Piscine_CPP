#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

#define MAX_VALUE 1000 

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string const & file)
{
    getDatabase();
    try
    {
        parseInputFile(file);
    }
    catch (FileException & e) {
        std:: cout << e.what() << "\n";
        exit(1); }
   
}

BitcoinExchange::~BitcoinExchange() {}

/************************** PUBLIC MEMBER FUNCTION ****************************/

void    BitcoinExchange::getDatabase()
{
    std::string dbname = "data.csv";
    std::string line;
    std::string date;
    std::string key;
    
    std::ifstream f(dbname.c_str());
    if (!f.good())
        throw(FileException());
    
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

float    BitcoinExchange::findValue(std::string key)
{
    std::map<std::string, float>::iterator it;
    
    it = _data.find(key);
    if (it != _data.end())
        return it->second;
    it = _data.lower_bound(key);
    if (it != _data.end())
    {
        --it;
        return it->second;
    }
    return -1;  
}

bool   BitcoinExchange::parseKey(std::string & key)
{
    char buffer [80];
    const char *str = key.c_str();
    struct tm tm;
    char *end = strptime(str, "%Y-%m-%d", &tm);

    if (end == NULL || *end != '\0' || strftime (buffer,80,"%Y-%m-%d",&tm) == 0)
    {
        std::cout << "Error: bad input => [" << key << "]\n";
        return false;
    }
    return true;
}
bool BitcoinExchange::parseValue(std::stringstream  & value)
{
    std::string test = value.str();
    if (test.find_first_not_of("0123456789.") != std::string::npos)
    {
        int test;
        value >> test;
        if (test == 0)
            return true;
        if (test < 0)
        {
            std::cout << "Error: not a positive number.\n";
            return false;
        }
        std::cout << "Error: only digit character permitted.\n";
        return false;
    }
    
    int converted_value;
    value >> converted_value;
    if (converted_value> MAX_VALUE)
    {
        std::cout << "Error: too large a number.\n";
            return false;
    }
    return true;
}


void    BitcoinExchange::parseInputFile(std::string const & file)
{
    // checks if file exists and readable
    std::ifstream f(file.c_str());
    if (!f.good())
        throw(FileException());
    std::string line;
    std::string date;
    std::string key;
    std::string value;

    // skip first line
    std::getline(f, line);

    while(!f.eof())
    {
        std::getline(f,line);
        std::size_t first = line.find(" | ");
        if (first != std::string::npos)
        {
            key = line.substr(0, first);
            if (parseKey(key))
            {
                value = line.substr(first + 3, line.find('\n'));
                std::stringstream ss(value);
                if (parseValue(ss))
                {
                    std::stringstream s(value);
                    float res;
                    s >> res;
                    if (res == -0 ) res *= -1;
                    std::cout << key << " => " << res << " = " << res * findValue(key) <<  "\n";
                }
                
            }
        }
        else
            std::cout << "Error: invalid format => " << line << "\n";
    }
}

/************************** EXCEPTIONS ****************************************/
const char * BitcoinExchange::FileException::what() const throw() { return "Error: could not open file"; }
const char * BitcoinExchange::KeyException::what() const throw() { return "Error: invalid date"; }
const char * BitcoinExchange::BadInputException::what() const throw() { return "Error: bad input"; }
