/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:45:57 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/23 12:20:04 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat( void );
        Cat(Cat const &);
        Cat& operator=(Cat const &);
        ~Cat();

        void makeSound() const;
};
