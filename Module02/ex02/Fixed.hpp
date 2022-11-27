/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:15:04 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/24 19:46:18 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#ifndef FIXED_HPP
 #define FIXED_HPP

#include <iostream> 

class Fixed {
    public:
        Fixed( void );
        Fixed( int const n);
        Fixed( float const n);
        Fixed( Fixed const & raw);
        ~Fixed( void );

        Fixed & operator=(Fixed const & rhs);

        int		getRawBits( void ) const;
        void	setRawBits( int const raw);
        int		toInt( void ) const;
        float	toFloat( void ) const;

        /* increment and decrement */
        Fixed &   operator++( );
        Fixed operator++( int );
        Fixed &   operator--( );
        Fixed operator--( int );

        /* arithmetic operators */
        Fixed operator+(Fixed const & rhs) const;
        Fixed operator-(Fixed const & rhs) const;
        Fixed operator*(Fixed const & rhs) const;
        Fixed operator/(Fixed const & rhs) const;
        
        /* comparison operators */
        bool operator<(Fixed const & rhs) const;
        bool operator>(Fixed const & rhs) const;
        bool operator<=(Fixed const & rhs) const;
        bool operator>=(Fixed const & rhs) const;
        bool operator==(Fixed const & rhs) const;
        bool operator!=(Fixed const & rhs) const;

        static const Fixed & min(Fixed &a, Fixed &b) ;
        static const Fixed & max(Fixed &a, Fixed &b) ;
        static const Fixed & min(Fixed const &a, Fixed const &b) ;
        static const Fixed & max(Fixed const &a, Fixed const &b) ;
        


    
    private:
        int					_n;
        static const int	_bits;

};

#endif 









