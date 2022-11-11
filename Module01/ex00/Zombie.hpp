/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:33:41 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/11 17:41:29 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class   Zombie {
    public:
        Zombie( std::string name );
        ~Zombie( void );

        void    announce( void ) const;
    
    private:
        std::string _name;
};

Zombie* newZombie( std::string name );
void    randomChump( std::string name );

#endif