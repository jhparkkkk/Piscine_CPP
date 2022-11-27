/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:14:22 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/26 19:05:14 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/

MateriaSource::MateriaSource() : _nbMateria(0)
{
    std::cout << "MateriaSource created" << std::endl;
    for (int i = 0; i < 4; i++)
        _materia[i] = NULL;
    return;
}

MateriaSource::MateriaSource( MateriaSource const & src)
{
    std::cout << "MateriaSource Copy constructor called" << std::endl;
    *this = src;
    return ;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
    std::cout << "MateriaSource Copy assignment operator called" << std::endl;
    if (rhs._materia[0])
        this->_materia[0] = rhs._materia[0]->clone();
    return  *this;
}

MateriaSource::~MateriaSource( void )
{
    std::cout << "MateriaSource destroyed" << std::endl;
    for(int i = 0; i < _nbMateria; i++)
        if (_materia[i])
            delete _materia[i];
    return ;
}

/*********************** PUBLIC MEMBER FUNCTION *****************************/

/*
    Copies the Materia passed as a parameter into _materia[4] and stores it
    so it can be cloned later.
*/
void		MateriaSource::learnMateria(AMateria* materia)
{
    for(int i = 0; i < 4; i++)
    {
        if (!_materia[i])
        {
            _materia[i] = materia;
            _nbMateria++;
            return;
        }
    }
    std::cout << materia->getType() << std::endl;
    return;   
}

/*
    Returns a new Materia. The latter is a copy of the Materia previously
    learned by the MateriaSource whose type equals the one passed as parameter.
    Returns 0 if the type is unknown.
*/
AMateria*	MateriaSource::createMateria(std::string const & type)
{
    AMateria* new_materia = NULL;
    for(int i = 0; i < _nbMateria; i++)
    {
        if (_materia[i]->getType() == type)
        {
            new_materia = _materia[i];
            return new_materia;
        }
    }
    return NULL;
        
}

