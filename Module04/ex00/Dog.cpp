/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:55:07 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/23 11:02:15 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/

Dog::Dog( void )
{
    std::cout << "Dog created" << std::endl;
    this->_type = "dog";
    return;
}

Dog::Dog( Dog const & src)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Dog & Dog::operator=(Dog const & rhs)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    this->_type = rhs._type;
    return  *this;
}

Dog::~Dog( void )
{
    std::cout << "Dog destroyed" << std::endl;
    return ;
}

/*********************** PUBLIC MEMBER FUNCTION *****************************/

void    Dog::makeSound() const
{
    std::cout << "WOOOOOF" << std::endl;
    return;
}