/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:53:30 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/26 23:32:26 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/

Cat::Cat( void )
{
    std::cout << "Cat created" << std::endl;
    this->_type = "cat";
    this->_brain = new Brain();
    this->_brain->setIdeas("eat sleep ");
    return;
}

Cat::Cat( Cat const & src)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Cat & Cat::operator=(Cat const & rhs)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    this->_type = rhs._type;
    this->_brain = new Brain(*rhs._brain);
    return  *this;
}

Cat::~Cat( void )
{
    std::cout << "Cat destroyed" << std::endl;
    delete _brain;
    return ;
}

/*********************** PUBLIC MEMBER FUNCTION *****************************/

void    Cat::makeSound() const
{
    std::cout << "MEOWWWW" << std::endl;
    return;
}

void Cat::displayIdeas() const
{
    this->_brain->displayIdeas();
}

void	Cat::setType(std::string type)
{
    this->_type = type;
}

void    Cat::setIdeas(std::string idea)
{
    this->_brain->setIdeas(idea);
}
