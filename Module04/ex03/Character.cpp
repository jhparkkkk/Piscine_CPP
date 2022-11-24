/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:36:43 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/24 16:03:16 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/

Character::Character() : _name("default"), _nbSlot(0)
{
    std::cout << "Character named " << this->_name << " created" << std::endl;
    for (int i = 0; i < 4; i++)
        _slot[i] = NULL;
    return;
}

Character::Character(std::string const & name) : _name(name), _nbSlot(0)
{
    std::cout << "Character named " << this->_name << " created" << std::endl;
    return; 
}

Character::Character( Character const & src)
{
    std::cout << "Character Copy constructor called" << std::endl;
    *this = src;
    return ;
}

/*
    Character copy must be deep. Therefore materias must be deleted before copy
*/
Character & Character::operator=(Character const & rhs)
{
    std::cout << "Character Copy assignment operator called" << std::endl;
    _name = rhs._name;
    
    for (int i = 0; i < 4; i++)
    {
        if (_slot[i])
            _slot[i] = rhs._slot[i]->clone();
        else
            _slot[i] = NULL;
    }
    delete this;
    return  *this;
}

Character::~Character( void )
{
    std::cout << "Character " << _name << " destroyed" << std::endl;
    for (int i = 0; i < _nbSlot; i++)
        if (_slot[i])
            delete _slot[i];
    return ;
}

/*********************** PUBLIC MEMBER FUNCTION *****************************/

std::string	const &	Character::getName() const
{
    return _name;
}

/*
    Copies materia in the first empty slot.
    If the inventory is full : return; 
*/
void    Character::equip(AMateria* m)
{
    std::cout << "********* equip *********" << std::endl;
    if (_nbSlot == 4)
        return;
    _slot[_nbSlot] = m;
    _nbSlot++;
    std::cout << _nbSlot << m->getType() << std::endl;
    return;
}

void    Character::unequip(int idx)
{
    (void)idx;
    std::cout << "unequip" << std::endl;
    return;
}

/*
    Use the Materia at the slot[idx], and pass the target parameter
    to the AMateria::use() function
*/
void    Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "invalid inventory index: try [0 - 3]" << std::endl;
        return;
    }
    _slot[idx]->use(target);
}
