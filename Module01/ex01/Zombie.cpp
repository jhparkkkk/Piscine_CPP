/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:38:30 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/11 18:27:31 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void ) : _name("default")
{
    std::cout << "Zombie " << this->_name << " created" << std::endl;
    return ;
}

Zombie::~Zombie( void )
{
    std::cout << "Zombie " << this->_name << " destroyed" << std::endl;
    return ;
}

void    Zombie::setName(std::string name) { _name = name;}

std::string Zombie::getName() const
{
    return _name;
}

void    Zombie::announce( void ) const
{
    std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}



// Zombie* newZombie( std::string name )
// {
//     return new Zombie(name);
// }