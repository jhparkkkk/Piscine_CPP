/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:17:48 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/16 13:07:25 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <math.h>

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/

Fixed::Fixed( void )
{
    std::cout << "Default constructor called" << std::endl;
    _rawBits = 0;
    return ;
}

Fixed::Fixed( int const n ) 
{
    std::cout << "Int constructor called" << std::endl;
    this->_rawBits = n << _bits;
    return ;
}

Fixed::Fixed( float const n )
{
    std::cout << "Float constructor called" << std::endl;
    this->_rawBits = roundf(n * (1 << _bits));
    return ;
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed::Fixed( Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_rawBits = rhs.getRawBits();
    return  *this;
}

const int Fixed::_bits = 8;


int    Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

void    Fixed::setRawBits( int const raw)
{
    this->_rawBits = raw;
    return;
}

int     Fixed::toInt( void ) const
{
    return this->_rawBits >> _bits;
}

float     Fixed::toFloat( void ) const
{
    return (float)this->_rawBits / (float)(1 << _bits);
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return o;
}