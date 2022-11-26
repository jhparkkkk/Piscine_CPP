/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:45:57 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/26 23:38:28 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#ifndef WRONGCAT_HPP
 #define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat( void );
        WrongCat(WrongCat const &);
        WrongCat& operator=(WrongCat const &);
        ~WrongCat();

        void makeSound() const;
};

#endif