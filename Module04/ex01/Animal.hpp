/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:31:20 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/23 11:07:38 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#pragma once 

class   Animal{
    public:
        Animal( void );
        Animal( Animal const & src);
        Animal & operator=(Animal const & rhs);
        virtual ~Animal( void );

        std::string getType() const;
        
        virtual void makeSound() const;
    protected:
        std::string _type;
};