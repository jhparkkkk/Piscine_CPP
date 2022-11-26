/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:45:57 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/26 23:20:53 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#ifndef CAT_HPP
 #define CAT_HPP
#include "Animal.hpp"

/*
    Class Dog inherits from class Animal. Therefore class Animal is first constructed
    and then, class Dog. 
*/
class Cat : public Animal
{
    public:
        Cat();
        Cat(Cat const &);
        Cat& operator=(Cat const &);
        ~Cat();

        void makeSound() const;
};

#endif