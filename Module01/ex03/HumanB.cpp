/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:55:37 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/12 18:32:48 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name) 
{
    _Weapon = NULL;
    std::cout << "Human B " << _name << " created" << std::endl;
    return ; 
}

HumanB::~HumanB( void )
{
    std::cout << "Human B " << _name << " destroyed" << std::endl;
    return ; 
}

void    HumanB::attack( void )
{
    if (this->_Weapon == NULL)
        std::cout << this->_name << " cannot attack: weapon is missing." << std::endl;
    else
        std::cout << this->_name << " attacks with their " << _Weapon->getType() << std::endl;
    return;
}

void    HumanB::setWeapon(Weapon& weapon)
{
    _Weapon = &weapon;
    return;
}