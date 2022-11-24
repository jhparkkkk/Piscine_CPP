/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:36:43 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/24 18:35:58 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/

Character::Character() : _name("default"), _nbSlot(0), _nbTrash(0)
{
    std::cout << "Character named " << this->_name << " created" << std::endl;
    for (int i = 0; i < 4; i++)
        _slot[i] = NULL;
    _trash = NULL;
    return;
}

Character::Character(std::string const & name) : _name(name), _nbSlot(0), _nbTrash(0)
{
    std::cout << "Character named " << this->_name << " created" << std::endl;
    for (int i = 0; i < 4; i++)
        _slot[i] = NULL;
    _trash = NULL;
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
    // delete this;
    return  *this;
}

Character::~Character( void )
{
    std::cout << "Character " << _name << " destroyed" << std::endl;
    for (int i = 0; i < _nbSlot; i++)
        if (_slot[i])
            delete _slot[i];
    for (int i = 0; i < _nbTrash; i++)
    {
        if (_trash[i])
        {
            delete _trash[i];
        }
    }
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
    if (_nbSlot == 4)
        return;
    _slot[_nbSlot] = m;
    _nbSlot++;
    return;
}

void    Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
        return;
    ++_nbTrash;
    AMateria **tmp = _trash;
    _trash = new AMateria*[_nbTrash];
    for (int i = 0; i < _nbTrash - 1; i++)
    {
        if (tmp[i])
            _trash[i] = tmp[i];
    }
    _trash[_nbTrash - 1] = _slot[idx];
    _slot[idx] = NULL;
    delete tmp;
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
    if (_slot[idx] == NULL)
        return;
    _slot[idx]->use(target);
}
