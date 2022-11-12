/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:49:52 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/12 17:07:54 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#ifndef HUMAN_A_H
# define HUMAN_A_H

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {
    public:
        HumanA( std::string name, Weapon& _weapon );
        ~HumanA( void );
        
        void    attack( void );

    private:
        std::string _name;
        Weapon& _Weapon;
    
};


#endif 