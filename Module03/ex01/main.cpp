/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:29:04 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/20 18:15:49 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main ()
{
    ClapTrap parent = ClapTrap("parent");
    ScavTrap child = ScavTrap();
    
    child.setName("child");
    child.guardGate();
    
    std::cout << "Energy points: " << child.getEnergyPoints() << std::endl;
    child.attack("another robot");
    std::cout << "Energy points: " << child.getEnergyPoints() << std::endl;
    
    std::cout << "Hit points: " << child.getHitPoints() << std::endl;
    child.takeDamage(60);
    std::cout << "Hit points: " << child.getHitPoints() << std::endl;    
    child.beRepaired(20);
    std::cout << "Hit points: " << child.getHitPoints() << std::endl;
    std::cout << "Energy points: " << child.getEnergyPoints() << std::endl;
    
    child.takeDamage(1000);
    
    return 0;
}