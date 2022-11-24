/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:36:47 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/24 17:45:46 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
 #define CHARACTER_HPP

#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"

class   Character: public ICharacter
{
    public:
        Character( void );
		Character(std::string const & name);
        Character(Character const &);
        Character& operator=(Character const &);
        ~Character();

        std::string	const &	getName() const;
        void				equip(AMateria* m);
        void				unequip(int idx);
        void				use(int idx, ICharacter& target);
        // void                emptyTrash(void);
    private:
        std::string	_name;
		AMateria*   _slot[4];
		AMateria**	_trash;
		int			_nbSlot;
		int         _nbTrash;
};

#endif
