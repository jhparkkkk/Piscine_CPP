/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:38:30 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/14 15:40:13 by jeepark          ###   ########.fr       */
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
