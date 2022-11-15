/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:17:48 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/15 17:29:05 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/

Fixed::Fixed( void )
{
    std::cout << "Default constructor called" << std::endl;
    _rawBits = 0;
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