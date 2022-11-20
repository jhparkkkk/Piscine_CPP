/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:19:07 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/20 18:29:58 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#ifndef FRAGTRAP_HPP
 #define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap( void );
        FragTrap(FragTrap const &);
        FragTrap& operator=(FragTrap const &);
        ~FragTrap();
        
        void highFivesGuys(void);
};

#endif
