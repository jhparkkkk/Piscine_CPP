/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:33:41 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/19 15:55:23 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class   Zombie {
    public:
        Zombie( void );
        ~Zombie( void );
        
        void        setName(std::string name);
        std::string getName() const;
        void        announce( void ) const;
    
    private:
        std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif