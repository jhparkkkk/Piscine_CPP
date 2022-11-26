/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:37:03 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/26 23:17:46 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/

Animal::Animal() : _type("default")
{
    std::cout << "Animal created" << std::endl;
    return;
}

Animal::Animal( Animal const & src)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Animal & Animal::operator=(Animal const & rhs)
{
    std::cout << "Animal Copy assignment operator called" << std::endl;
    this->_type = rhs._type;
    return  *this;
}

Animal::~Animal()
{
    std::cout << "Animal destroyed" << std::endl;
    return ;
}

std::string Animal::getType() const { return this->_type; }

/*********************** PUBLIC MEMBER FUNCTION *****************************/

void    Animal::makeSound() const
{
    std::cout << "Sad animal sound." << std::endl;
    return;
}

