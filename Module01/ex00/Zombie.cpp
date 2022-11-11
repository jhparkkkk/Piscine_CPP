/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:38:30 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/11 17:35:52 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name)
{
    std::cout << "Zombie " << this->_name << " created" << std::endl;
    return ;
}

Zombie::~Zombie( void )
{
    std::cout << "Zombie " << this->_name << " destroyed" << std::endl;
    return ;
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