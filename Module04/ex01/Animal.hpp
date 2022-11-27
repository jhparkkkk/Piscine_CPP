/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:31:20 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/25 15:37:11 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#pragma once 

class   Animal{
    public:
        Animal();
        Animal( Animal const & src);
        Animal & operator=(Animal const & rhs);
        virtual ~Animal();

        std::string getType() const;
        
        virtual void makeSound() const;
    protected:
        std::string _type;
};