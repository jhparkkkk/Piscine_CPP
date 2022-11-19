/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:53:27 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/19 16:00:27 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#ifndef HUMAN_B_H
# define HUMAN_B_H

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {
    public:
        HumanB( std::string name );
        ~HumanB( void );
        
        void    attack( void );
        void    setWeapon(Weapon& weapon);

    private:
        std::string _name;
        Weapon* _Weapon;
};



#endif 