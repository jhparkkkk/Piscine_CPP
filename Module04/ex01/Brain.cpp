/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:55:07 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/23 14:36:20 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/

Brain::Brain( void )
{
    std::cout << "Brain created" << std::endl;
    return;
}

Brain::Brain( Brain const & src)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Brain & Brain::operator=(Brain const & rhs)
{
    std::cout << "Brain Copy assignment operator called" << std::endl;
    for(int i = 0; i < 100; i++)
        this->_ideas[i] = rhs._ideas[i];

    return  *this;
}

Brain::~Brain( void )
{
    std::cout << "Brain destroyed" << std::endl;
    return ;
}

/*********************** PUBLIC MEMBER FUNCTION *****************************/

void    Brain::setIdeas(std::string idea)
{
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = idea;
}

void Brain::displayIdeas() const
{
    for (int i = 0; i < 100; i++)
        std::cout << this->_ideas[i];
    return;
}

