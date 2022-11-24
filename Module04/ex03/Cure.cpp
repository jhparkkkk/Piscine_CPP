/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:36:50 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/24 11:00:45 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
Cure::Cure()
{
    std::cout << "Cure created" << std::endl;
    setType("cure");
    return;
}

Cure::Cure( Cure const & src)
{
    std::cout << "Cure Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Cure & Cure::operator=(Cure const & rhs)
{
    std::cout << "Cure Copy assignment operator called" << std::endl;
    this->_type = rhs._type;
    return  *this;
}

Cure::~Cure( void )
{
    std::cout << "Cure destroyed" << std::endl;
    return ;
}

/**************************** SETTERS & GETTERS *****************************/

void	Cure::setType(std::string type) { this->_type = type; }

/*********************** PUBLIC MEMBER FUNCTION *****************************/

AMateria* Cure::clone() const
{
    AMateria *new_cure = new Cure(*this);
    return new_cure;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
    return; 
}

