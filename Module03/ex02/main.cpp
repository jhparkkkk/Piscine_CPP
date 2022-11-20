/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:29:04 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/20 18:31:59 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main ()
{
    ClapTrap lap = ClapTrap();
    FragTrap frag = FragTrap();
    
    clap.setName("Parent");
    
    frag.setName("Child");
    frag.highFivesGuys();
    return 0;
}