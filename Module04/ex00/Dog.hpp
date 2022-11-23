/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:54:50 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/23 11:01:04 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog( void );
        Dog(Dog const &);
        Dog& operator=(Dog const &);
        ~Dog();

        void makeSound() const;
};
