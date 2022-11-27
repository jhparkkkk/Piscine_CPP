/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:53:30 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/26 23:40:06 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/

WrongCat::WrongCat( void )
{
    std::cout << "WrongCat created" << std::endl;
    this->_type = "cat";
    this->_brain = new Brain();
    this->_brain->setIdeas("eat sleep ");

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
    this->_brain = rhs._brain;
    return  *this;
}

WrongCat::~WrongCat( void )
{
    std::cout << "WrongCat destroyed" << std::endl;
    delete _brain;
    return ;
}

/*********************** PUBLIC MEMBER FUNCTION *****************************/

void    WrongCat::makeSound() const
{
    std::cout << "MEOWWWW" << std::endl;
    return;
}
