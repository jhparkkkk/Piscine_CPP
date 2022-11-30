/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:46:29 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/30 23:44:10 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

bool isNumeric(std::string const &str)
{
	char* p;
	strtol(str.c_str(), &p, 10);
	return *p == 0;
}

/*
    Checks if before '.' character is only numeric
    Checks if after '.' to str.size - 2 is only numeric.
    Checks if last character is numeric or 'f'.

*/
bool    Convert::check_format(std::string str)
{
    int i = str.find('.');
    std::string left = str.substr(0, i);
    if (!isNumeric(left))
        return false;
    std::string right = str.substr(i + 1, str.size() - i - 2);
    if (!isNumeric(right))
        return false;
    char last;
    last = str[str.size() -1];
    if (last != 'f' && (last < '0' || last > '9'))
        return false;
    return true;
}

bool    Convert::isChar()
{
    if (_str.size() != 1)
        return false;
    if (_str[0] < 0 && _str[0] > 127)
        return false;
    _type = CHAR;
    return true; 
}

/*
    Checks if _str is only 1 character but is not digit, returns false.
    Checks if first character is not '-', then it must be digit.
    Checks if _str converted in int is out of range. 
*/
bool Convert::isInt()
{
    if (!isNumeric(_str))
        return false;
    try
    {
        int test = std::stoi(_str);
        if (test)
            _type = INT;
    }
    catch (const std::out_of_range& oor) { return false; }
    return true;
}


bool    Convert::isFloat()
{
    if (_str == "nanf" || _str == "+inff" || _str == "-inff")
    {
        _type = FLOAT;
        return true;
    }
    if (!check_format(_str))
        return false;
    try
    {
        float test = std::stof(_str);
        if (test)
            _type = FLOAT;
    }
    catch (const std::invalid_argument& ia) { return false; }
    catch (const std::out_of_range& oor) { return false; }
    return true;
}

bool    Convert::isDouble()
{
    if (_str == "nan" || _str == "+inf" || _str == "-inf")
    {
        _type = DOUBLE;
        return true;
    }
    if (check_format(_str) == false)
        return false;
    try
    {
        float test = std::stod(_str);
        if (test)
            _type = DOUBLE;
    }
    catch (const std::invalid_argument& ia) { return false; }
    catch (const std::out_of_range& oor) { return false; }
    return true;
}