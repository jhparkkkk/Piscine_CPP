/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:44:35 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/12 16:51:30 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>
#include <string>

class Weapon {
    public:
        Weapon(std::string name);
        ~Weapon( void );
        void                setType(std::string name);
        std::string const&  getType() const;


    private:
        std::string _type;
    
};



#endif 