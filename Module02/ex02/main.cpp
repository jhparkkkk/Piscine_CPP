/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:14:13 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/16 18:33:17 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed  const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;

    Fixed c(-10);
    Fixed d(2);

    std::cout << (c<d) << std::endl;




    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
    
    // Fixed a;
    // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    // /* increment */
    // std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    // std::cout << std::endl;
    
    // /* decrement */
    // std::cout << a << std::endl;
    // std::cout << --a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a-- << std::endl;
    // std::cout << a << std::endl;

    // /* arithmetic */

    // std::cout << b << std::endl;
    // // std::cout << Fixed::max( a, b ) << std::endl;
    // return 0;
}