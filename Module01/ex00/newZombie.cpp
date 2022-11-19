/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:31:25 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/19 15:50:58 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    return new Zombie(name);
}

/*
    Zombie allocated on the stack and announce itself.
    Destroyed at the end of the function.
*/
void    randomChump( std::string name)
{
    Zombie *zombie = new Zombie(name);
    zombie->announce();
    delete zombie;
    return;
}