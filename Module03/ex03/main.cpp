/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:29:04 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/21 17:20:09 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main ()
{
    std::cout << "**** Construction ****" << std::endl;
    ClapTrap clap = ClapTrap("Clap");
    ScavTrap scav = ScavTrap("Scav");
    FragTrap frag = FragTrap("Frag");
    
    std::cout << std::endl;
    
    frag.highFivesGuys();
    scav.guardGate();
    frag.attack("Scav");
    scav.takeDamage(frag.getAttackDamage());
    scav.attack("Frag");
    frag.takeDamage(scav.getAttackDamage());
    scav.attack("Frag");
    frag.takeDamage(scav.getAttackDamage());
    scav.attack("Frag");
    frag.takeDamage(scav.getAttackDamage());
    std::cout << "Hit points: " << frag.getHitPoints() << std::endl;
    frag.beRepaired(20);
    std::cout << "Hit points: " << frag.getHitPoints() << std::endl;
    scav.attack("Frag");
    frag.takeDamage(scav.getAttackDamage());
    scav.attack("Frag");
    frag.takeDamage(scav.getAttackDamage());
    clap.attack("Frag");




    return 0;
}