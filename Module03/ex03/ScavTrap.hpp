/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:21:41 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/23 10:46:34 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#ifndef SCAVTRAP_HPP
 #define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap( void );
        ScavTrap( std::string name);
        ScavTrap(ScavTrap const &);
        ScavTrap& operator=(ScavTrap const &);
        ~ScavTrap();
        
        void    guardGate();
		void    attack(const std::string & target);
};

#endif