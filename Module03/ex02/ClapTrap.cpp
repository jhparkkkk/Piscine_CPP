/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:29:12 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/20 18:22:23 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/

ClapTrap::ClapTrap( void ) : _name("default")
{
    std::cout << "Claptrap " << this->_name << " created" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    return;
}

ClapTrap::ClapTrap( std::string name ) : _name(name)
{
    std::cout << "Claptrap " << this->_name << " created" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    return ;
}

ClapTrap::ClapTrap( ClapTrap const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_name = rhs._name;
    this->_hitPoints = rhs._hitPoints; 
    this->_energyPoints = rhs._energyPoints;
    this->_attackDamage = rhs._attackDamage;
    
    return  *this;
}

ClapTrap::~ClapTrap( void )
{
    std::cout << "Claptrap " << this->_name << " destroyed" << std::endl;
    return ;
}

/*************************** SETTERS & GETTERS ******************************/

void	ClapTrap::setName( std::string name )
{
    this->_name = name;
    return;
}

std::string	ClapTrap::getName( void ) const
{
    return this->_name;     
}

int		ClapTrap::getHitPoints( void ) const
{
    return this->_hitPoints;
}

int		ClapTrap::getEnergyPoints( void ) const
{
    return this->_energyPoints;
}

int ClapTrap::getAttackDamage( void ) const
{
    return this->_attackDamage; 
}

/*********************** PUBLIC MEMBER FUNCTION *****************************/

void	ClapTrap::attack(const std::string& target)
{
    if (this->_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " can't attack: ";
        std::cout << "no energy left." << std::endl;
    }
    else 
    {
        std::cout << "ClapTap " << this->_name << " attacks " << target;
        std::cout << ": causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    }
    return;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTap " << this->_name << " is attacked: ";
    std::cout << "loses " << amount << " hit points!" << std::endl;
    this->_hitPoints -= amount;
    if (this->_hitPoints <= 0)
    {
        std::cout << "ClapTap " << this->_name << " is K.O.: ";
        std::cout << " no hit points left." << std::endl;
    }
    return;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " can't heal: ";
        std::cout << "no energy left." << std::endl;
    }
    else   
    {
        std::cout << "ClapTap " << this->_name << " is healing: ";
        std::cout << "gains " << amount << " hit points!" << std::endl;
        this->_hitPoints += amount;
        this->_energyPoints--;
    }    
    return; 
}
