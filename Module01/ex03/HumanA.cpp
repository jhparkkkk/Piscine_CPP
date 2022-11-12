/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:31:26 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/12 17:08:03 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon) : _name(name), _Weapon(weapon)
{
    std::cout << "Human A " << _name << " created" << std::endl;
    std::cout << "Their weapon is : " << weapon.getType() << std::endl;
    return ; 
}

HumanA::~HumanA( void )
{
    std::cout << "Human A " << _name << " destroyed" << std::endl;
    return ; 
}

void    HumanA::attack( void )
{
    std::cout << this->_name << " attacks with their " << _Weapon.getType() << std::endl;
}