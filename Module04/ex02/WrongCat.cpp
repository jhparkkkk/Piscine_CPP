/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:53:30 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/23 11:26:11 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/

WrongCat::WrongCat( void )
{
    std::cout << "WrongCat created" << std::endl;
    this->_type = "cat";
    return;
}

WrongCat::WrongCat( WrongCat const & src)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    *this = src;
    return ;
}

WrongCat & WrongCat::operator=(WrongCat const & rhs)
{
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    this->_type = rhs._type;
    return  *this;
}

WrongCat::~WrongCat( void )
{
    std::cout << "WrongCat destroyed" << std::endl;
    return ;
}

/*********************** PUBLIC MEMBER FUNCTION *****************************/

void    WrongCat::makeSound() const
{
    std::cout << "MEOWWWW" << std::endl;
    return;
}
