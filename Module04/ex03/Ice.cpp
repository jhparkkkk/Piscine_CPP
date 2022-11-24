/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:36:56 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/24 14:48:32 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/

Ice::Ice()
{
    std::cout << "Ice created" << std::endl;
    setType("ice");
    return;
}

Ice::Ice( Ice const & src)
{
    std::cout << "Ice Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Ice & Ice::operator=(Ice const & rhs)
{
    std::cout << "Ice Copy assignment operator called" << std::endl;
    this->_type = rhs._type;
    return  *this;
}

Ice::~Ice( void )
{
    std::cout << "Ice destroyed" << std::endl;
    return ;
}
/**************************** SETTERS & GETTERS *****************************/

void	Ice::setType(std::string type) { this->_type = type; }

/*********************** PUBLIC MEMBER FUNCTION *****************************/

AMateria* Ice::clone()const
{
    AMateria *new_ice = new Ice(*this);
    return new_ice;
}

void Ice::use(ICharacter & target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    return;
}

