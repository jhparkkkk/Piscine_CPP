/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:21:51 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/21 16:00:11 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/

ScavTrap::ScavTrap( void )
{
    std::cout << "ScavTrap " << this->_name << " created." << std::endl;
    this->_hitPoints += 90;
    this->_energyPoints += 40;
    this->_attackDamage += 20;
    return;
}

ScavTrap::ScavTrap( std::string name )
{
    this->_name = name;
    this->_hitPoints += 90;
    this->_energyPoints += 40;
    this->_attackDamage += 20;
    std::cout << "ScavTrap " << this->_name << " created." << std::endl;
    return;
}

ScavTrap::ScavTrap( ScavTrap const & src)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = src;
    return ;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    this->_name = rhs._name;
    this->_hitPoints = rhs._hitPoints; 
    this->_energyPoints = rhs._energyPoints;
    this->_attackDamage = rhs._attackDamage;
    
    return  *this;
}

ScavTrap::~ScavTrap( void )
{
    std::cout << "ScavTrap "  << this->_name << " destroyed" << std::endl;
    return ;
}
/*********************** PUBLIC MEMBER FUNCTION *****************************/

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << "  is now in Gate keeper mode." << std::endl;
    return ; 
}

void		ScavTrap::attack(const std::string& target)
{
    if (this->_energyPoints <= 0)
    {
        std::cout << "ScavTrap " << this->_name << " can't attack: ";
        std::cout << "no energy left." << std::endl;
    }
    else 
    {
        std::cout << "ScavTrap " << this->_name << " attacks " << target;
        std::cout << ": causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    }
    return;
}