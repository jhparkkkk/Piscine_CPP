/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:44:37 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/12 18:28:16 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
    setType(name);
    std::cout << "Weapon " << _type << " created." << std::endl;
    return ; 
}

Weapon::~Weapon( void )
{
    std::cout << "Weapon " << _type << " destroyed." << std::endl;
    return ; 
}

void    Weapon::setType(std::string type)
{
    _type = type;

}

std::string const& Weapon::getType() const
{
    return ( _type );
}
