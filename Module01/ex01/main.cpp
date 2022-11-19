/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:39:55 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/11 18:25:54 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ()
{
    /* zombie allocated on the stack */
    Zombie zombie = Zombie();
    zombie.announce();

    /* zombie allocated on the heap */
    int nb_zombie = 5;
    Zombie* horde = zombieHorde(nb_zombie, "minions");
    
    for (int i = 0; i < nb_zombie; i++)
        horde[i].announce();
        
    delete [] horde;
    
    return 0;
}