/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:17:48 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/18 14:56:25 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <math.h>

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/

Fixed::Fixed( void )
{
    std::cout << "Default constructor called" << std::endl;
    _n = 0;
    return ;
}

Fixed::Fixed( int const n ) 
{
    this->_n = n << _bits;
    return ;
}

Fixed::Fixed( float const n )
{
    std::cout << "Float constructor called" << std::endl;
    this->_n = roundf(n * (1 << _bits));
    return ;
}

Fixed::~Fixed( void )
{
    // std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed::Fixed( Fixed const & src)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    this->_n = rhs.getRawBits();
    return  *this;
}

const int Fixed::_bits = 8;


int    Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return _n;
}

void    Fixed::setRawBits( int const raw)
{
    this->_n = raw;
    return;
}

int     Fixed::toInt( void ) const
{
    return this->_n >> _bits;
}

float     Fixed::toFloat( void ) const
{
    return static_cast<float>(this->_n) / static_cast<float>(1 << _bits);
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return o;
}

/************************** INCREMENT & DECREMENT *****************************/

Fixed &  Fixed::operator++(  )
{
    this->_n++;  
    return *this;
}

Fixed Fixed::operator++( int)
{
    Fixed old(*this);
    operator++();
    return(old);
}

Fixed &  Fixed::operator--(  )
{
    this->_n--;  
    return *this;
}

Fixed Fixed::operator--( int)
{
    Fixed old(*this);
    operator--();
    return(old);
}

/************************** ARITHMETIC OPERATORS *****************************/

Fixed Fixed::operator+(Fixed const & rhs) const
{
    return Fixed(this->_n + rhs.getRawBits());
}

Fixed Fixed::operator-(Fixed const & rhs) const
{
    return Fixed(this->_n - rhs.getRawBits());
}

Fixed Fixed::operator*(Fixed const & rhs) const
{
    return (Fixed(Fixed::toFloat() * rhs.toFloat() ));
}

Fixed Fixed::operator/(Fixed const & rhs) const
{
    if (rhs.toFloat() == 0)
        std::cout << "division by zero is undefined" << std::endl;
    return (Fixed(Fixed::toFloat() / rhs.toFloat() ));
}

/************************** COMPARISON OPERATORS *****************************/

bool Fixed::operator<(Fixed const & rhs) const
{
    return (Fixed::toFloat() < rhs.toFloat());
}

bool Fixed::operator>(Fixed const & rhs) const
{
    return (Fixed::toFloat() > rhs.toFloat());
}

bool Fixed::operator<=(Fixed const & rhs) const
{
    return (Fixed::toFloat() <= rhs.toFloat());
}

bool Fixed::operator>=(Fixed const & rhs) const
{
    return (Fixed::toFloat() >= rhs.toFloat());
}

bool Fixed::operator==(Fixed const & rhs) const
{
    return (Fixed::toFloat() == rhs.toFloat());
}

bool Fixed::operator!=(Fixed const & rhs) const
{
    return (Fixed::toFloat() != rhs.toFloat());
}

/************************ NON MEMBERS FUNCTIONS **************************/

const Fixed & Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed & Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed & Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a < b)
        return a;
    return b;
}


const Fixed & Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a > b)
        return a;
    return b;
}

