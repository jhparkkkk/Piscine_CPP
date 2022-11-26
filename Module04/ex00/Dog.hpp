/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:54:50 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/26 23:21:10 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#ifndef DOG_HPP
 #define DOG_HPP
#include "Animal.hpp"

/*
    Class Dog inherits from class Animal. Therefore class Animal is first constructed
    and then, class Dog. 
*/
class Dog : public Animal
{
    public:
        Dog();
        Dog(Dog const &);
        Dog& operator=(Dog const &);
        ~Dog();

        void makeSound() const;
};

#endif