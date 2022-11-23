/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:31:20 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/23 11:37:22 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#pragma once 

class   WrongAnimal{
    public:
        WrongAnimal( void );
        WrongAnimal( WrongAnimal const & src);
        WrongAnimal & operator=(WrongAnimal const & rhs);
        virtual ~WrongAnimal( void );

        std::string getType() const;
        
        void makeSound() const;
    protected:
        std::string _type;
};