/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:20:19 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/21 16:03:48 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/

FragTrap::FragTrap( void )
{
    std::cout << "FragTrap " << this->_name << " created." << std::endl;
    this->_hitPoints += 90;
    this->_energyPoints += 90;
    this->_attackDamage += 30;
    return;
}

FragTrap::FragTrap( std::string name )
{
    this->_name = name;
    this->_hitPoints += 90;
    this->_energyPoints += 90;
    this->_attackDamage += 30;
    std::cout << "FragTrap " << this->_name << " created." << std::endl;
    return;
}


FragTrap::FragTrap( FragTrap const & src)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = src;
    return ;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    this->_name = rhs._name;
    this->_hitPoints = rhs._hitPoints; 
    this->_energyPoints = rhs._energyPoints;
    this->_attackDamage = rhs._attackDamage;
    
    return  *this;
}

FragTrap::~FragTrap( void )
{
    std::cout << "FragTrap " << this->_name << " destroyed." << std::endl;
    return ;
}

/*********************** PUBLIC MEMBER FUNCTION *****************************/

void FragTrap::highFivesGuys( void )
{
    std::cout << "FragTrap " << this->_name << " requests high fives!" << std::endl;
    return;
    
}
