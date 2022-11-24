/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:36:59 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/24 10:53:01 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICE_HPP
 #define ICE_HPP
#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(Ice const &);
        Ice& operator=(Ice const &);
        ~Ice();
        
        void	setType(std::string);
        
        AMateria*   clone() const;
        void        use(ICharacter & target);

};

#endif