/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:13:47 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/30 23:45:23 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"
#include <ctype.h>
#include <stdio.h>
#include <limits>
#include <iomanip>
#include <cfloat>
#include <cmath>

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/

Convert::Convert()
{
    // std::cout << "Convert created" << std::endl;
    return;
}

Convert::Convert(std::string const & litteral) : _str(litteral)
{
	_is[0] = &Convert::isChar;
	_is[1] = &Convert::isInt;
	_is[2] = &Convert::isFloat;
	_is[3] = &Convert::isDouble;
	
	_cast[0] = &Convert::castChar;
	_cast[1] = &Convert::castInt;
	_cast[2] = &Convert::castFloat;
	_cast[3] = &Convert::castDouble;

	detectType();
	makeConversion();

    return;
}

Convert::Convert( Convert const & src)
{
    // std::cout << "Convert Copy constructor called" << std::endl;
    *this = src;
    return;
}

Convert & Convert::operator=(Convert const & rhs)
{
    // std::cout << "Convert Copy assignment operator called" << std::endl;
    _str = rhs._str;
    _char = rhs._char;
    _int = rhs._int;
    _double = rhs._double;
    _float = rhs._float;

    return  *this;
}

Convert::~Convert( void )
{
    // std::cout << "Convert destroyed" << std::endl;
    return;
}
/************************** SETTERS & GETTERS *********************************/

int Convert::getType() const { return _type; }
std::string Convert::getLitteral() const { return _str; }
char    Convert::getChar() const { return _char; }
int     Convert::getInt() const { return _int; }
float   Convert::getFloat() const { return _float; }
double  Convert::getDouble() const { return _double; }

/*
	TYPE 0 - CHAR
	TYPE 1 - INT
	TYPE 2 - FLOAT
	TYPE 3 - DOUBLE
*/

/************************** PRIVATE MEMBER FUNCTION ***************************/

/*
	First, detect which type is input string.
*/
void    Convert::detectType()
{
	int res = 0;
	for (int i = 0; i < NB_TYPE; i++)
		res += (this->*_is[i])();
    if ( !res )
        throw (InvalidInputException());
	if (_type == CHAR)
		_char = static_cast <char> (_str[0]);
	else
		_toConvert = std::stod(_str);
}

void	Convert::makeConversion()
{
	for (int i = 0; i < NB_TYPE ; i++)
		(this->*_cast[i])();
}

/*
	if '.' is found, return n characters after '.'
	else returns 1.
*/
int		Convert::findPrecision(std::string str) const
{
	int i = str.find('.');
	if (i == -1)
		return 1;
	return str.size() - i - 1;
}


void	Convert::castChar()
{
	if (_type == CHAR)
	{
		std::cout << "Char: " << _char << std::endl;
		return;
	}
	if (_toConvert != round(_toConvert) || _toConvert < 0 || _toConvert > 127)
	{
		std::cout << "Char: impossible " << std::endl;
		return;
	}
	_char = static_cast <char> (_toConvert);
	if (!std::isprint(_char))
		std::cout << "Char: non displayable " << std::endl;
	else
		std::cout << "Char: " << _char << std::endl; 
	return;
}

void	Convert::castInt()
{
	if (_str.size() == 1)
	{
		_int  = static_cast <int> (_char);
		std::cout << "Int: " << _int << std::endl;
		return;
	}
	try
	{
		_int = stoi(_str);
	}
	catch (const std::invalid_argument& ia)
    {
        std::cout << "int: impossible " << std::endl;
		_int = 0;
		return;
    }
    catch (const std::out_of_range& oor)
    {
        std::cout << "int: impossible" << std::endl;
		_int = 0;
		return;
    }
	_int = static_cast <int> (_toConvert);
	std::cout << "Int: " << _int << std::endl;
}

void	Convert::castFloat()
{
	if (_str == "-inff" || _str == "+inff" || _str == "-inf" || _str == "+inf")
	{
		_float = static_cast <float> (_toConvert);
		std::cout << "Float: " << _float << 'f' << std::endl;
		return;
	}
	if (_type == CHAR)
	{
		_float  = static_cast <int> (_char);
		std::cout << "Float: " << std::setprecision(findPrecision(_str)) << std::fixed<< _float <<std::endl;
		return;
	}
	if (_toConvert < -FLT_MAX || _toConvert > FLT_MAX)
	{
		std::cout << "Float: impossible" << '\n';
		return;
	}
	_float = static_cast <float> (_toConvert);
	std::cout << "Float: " << std::setprecision(findPrecision(_str)) << std::fixed << _float << 'f' << std::endl;
}

void	Convert::castDouble()
{
	if (_type == CHAR)
	{
		_double  = static_cast <int> (_char);
		std::cout << "Double: " << std::setprecision(findPrecision(_str)) << std::fixed<< _double <<std::endl;
		return;
	}
	_double = static_cast <double> (_toConvert);
	std::cout << "Double: " << std::setprecision(findPrecision(_str)) << std::fixed<< _double << std::endl;
}


/************************** NON MEMBER FUNCTION *******************************/
std::ostream & operator<<( std::ostream & o, Convert const & rhs)
{
    o << "Char: " << rhs.getChar() << std::endl;
    o << "Int: " << rhs.getInt() << std::endl;
    o << "Float: " << std::setprecision(rhs.findPrecision(rhs.getLitteral())) << std::fixed << rhs.getFloat() << 'f' <<std::endl; 
    o << "Double: " << rhs.getDouble() << std::endl; 
    return o;
}

/************************** NON MEMBER ATTRIBUTES *******************************/

int const Convert::_key[NB_TYPE] = {CHAR, INT, FLOAT, DOUBLE};

/************************** EXCEPTIONS ******************************************/

const char * Convert::InvalidInputException::what() const throw()
{
    return "Error: invalid input format";
}