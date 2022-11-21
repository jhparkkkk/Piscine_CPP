/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:29:09 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/20 17:45:30 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#ifndef CLAPTRAP_HPP
 #define CLAPTRAP_HPP

#include <iostream> 



class ClapTrap {
    public:
        ClapTrap( void );
        ClapTrap( std::string name );
        ClapTrap( ClapTrap const & raw);
        ~ClapTrap( void );

        ClapTrap & operator=(ClapTrap const & rhs);
		
		void		setName( std::string name );
		
		// ClapTrap(std::string, int, int, int);
		
		std::string	getName( void ) const;
		int			getHitPoints( void ) const;
		int			getEnergyPoints( void ) const;
		int			getAttackDamage( void ) const;

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
    
    protected:
		std::string	_name; 
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
		
};

#endif 