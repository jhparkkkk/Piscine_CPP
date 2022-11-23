/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:37:03 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/23 11:23:15 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/

WrongAnimal::WrongAnimal( void ) : _type("unknown")
{
    std::cout << "Wrong Animal created" << std::endl;
    return;
}

WrongAnimal::WrongAnimal( WrongAnimal const & src)
{
    std::cout << "Wrong Animal Copy constructor called" << std::endl;
    *this = src;
    return ;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs)
{
    std::cout << "Wrong Animal Copy assignment operator called" << std::endl;
    this->_type = rhs._type;
    return  *this;
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << "Wrong Animal destroyed" << std::endl;
    return ;
}

std::string WrongAnimal::getType() const
{
    return this->_type;
}


/*********************** PUBLIC MEMBER FUNCTION *****************************/

void    WrongAnimal::makeSound() const
{
    std::cout << "Sad Wrong animal sound." << std::endl;
    return;
}

