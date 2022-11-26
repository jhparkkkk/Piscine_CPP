/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:31:20 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/26 23:22:42 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#pragma once 
#ifndef WRONGANIMAL_HPP
 #define WRONGANIMAL_HPP
class   WrongAnimal{
    public:
        WrongAnimal();
        WrongAnimal( WrongAnimal const & src);
        WrongAnimal & operator=(WrongAnimal const & rhs);
        virtual ~WrongAnimal();

        std::string getType() const;
        
        void makeSound() const;
    protected:
        std::string _type;
};

#endif