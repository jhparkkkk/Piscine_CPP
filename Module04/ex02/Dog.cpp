/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:55:07 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/23 13:39:12 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/

Dog::Dog( void )
{
    std::cout << "Dog created" << std::endl;
    this->_type = "dog";
    this->_brain = new Brain();
    this->_brain->setIdeas("eat play ");

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
    this->_brain = new Brain(*rhs._brain);
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

void Dog::displayIdeas() const
{
    this->_brain->displayIdeas();
}
