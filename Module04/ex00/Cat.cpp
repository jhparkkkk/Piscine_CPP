/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:53:30 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/23 10:56:32 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/

Cat::Cat( void )
{
    std::cout << "Cat created" << std::endl;
    this->_type = "cat";
    return;
}

Cat::Cat( Cat const & src)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Cat & Cat::operator=(Cat const & rhs)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    this->_type = rhs._type;
    return  *this;
}

Cat::~Cat( void )
{
    std::cout << "Cat destroyed" << std::endl;
    return ;
}

/*********************** PUBLIC MEMBER FUNCTION *****************************/

void    Cat::makeSound() const
{
    std::cout << "MEOWWWW" << std::endl;
    return;
}
