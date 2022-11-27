/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:45:57 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/26 23:39:19 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat( void );
        Cat(Cat const &);
        Cat& operator=(Cat const &);
        ~Cat();

        void	makeSound() const;
        void	displayIdeas() const;
        void	setType(std::string);
		void	setIdeas(std::string idea);

    private:
        Brain* _brain;
};
