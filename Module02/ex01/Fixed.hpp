/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:15:04 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/16 13:03:45 by jeepark          ###   ########.fr       */
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
    
    private:
        int					_rawBits;
        static const int	_bits;

};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs);

#endif 