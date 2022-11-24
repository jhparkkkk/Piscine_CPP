/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:36:53 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/23 21:52:30 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CURE_HPP
 #define CURE_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"
class Cure : public AMateria
{
    public:
        Cure();
        Cure(Cure const &);
        Cure& operator=(Cure const &);
        ~Cure();

        void	setType(std::string);

        AMateria* clone() const;
    	void use(ICharacter& target);

};
#endif