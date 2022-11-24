/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:36:26 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/24 14:57:48 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) : _type("default")
{
    std::cout << "AMateria created" << std::endl;
    return;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
    std::cout << "AMateria " << _type << "created" << std::endl;
    return;
}

AMateria::AMateria( AMateria const & src)
{
    std::cout << "AMateria Copy constructor called" << std::endl;
    *this = src;
    return ;
}

AMateria & AMateria::operator=(AMateria const & rhs)
{
    std::cout << "AMateria Copy assignment operator called" << std::endl;
    this->_type = rhs._type;
    return  *this;
}

AMateria::~AMateria( void )
{
    std::cout << "AMateria destroyed" << std::endl;
    return ;
}

/*********************** PUBLIC MEMBER FUNCTION *****************************/

std::string const & AMateria::getType() const //Returns the materia type
{
    return _type;
}

void AMateria::use(ICharacter& target)
{   
    std::cout << "AMateria use() default" << target.getName() << std::endl;
    return; 
}
