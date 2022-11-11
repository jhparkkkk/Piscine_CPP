/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:39:55 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/11 17:47:00 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ()
{
    /* zombie allocated on the stack */
    Zombie zombie = Zombie("jee");
    zombie.announce();

    /* zombie allocated on the heap */ 
    Zombie* zombieP = newZombie("jo");
    zombieP->announce();

    /* zombie allocated on the stack locally 
        inside function */
    randomChump("kiki");
    
    /* free Jo from the heap */
    delete zombieP;
    return 0;
}