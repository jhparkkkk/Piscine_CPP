/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:15:04 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/15 17:29:11 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#ifndef FIXED_HPP
 #define FIXED_HPP

#include <iostream> 

class Fixed {
    public:
        Fixed( void );
        Fixed( Fixed const & raw);
        ~Fixed( void );

        Fixed & operator=(Fixed const & rhs);

        int getRawBits( void ) const;
        void setRawBits( int const raw);
    
    private:
        int _rawBits;
        static const int _bits;

};

#endif 