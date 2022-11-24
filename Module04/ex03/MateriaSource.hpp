/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:14:25 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/24 10:11:54 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIASOURCE_HPP
 #define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"

class   MateriaSource: public IMateriaSource
{
    public:
        MateriaSource( void );
        MateriaSource(MateriaSource const &);
        MateriaSource& operator=(MateriaSource const &);
        ~MateriaSource();

    	void		learnMateria(AMateria*);
    	AMateria*	createMateria(std::string const & type);

    private:
        AMateria*   _materia[4];
        int         _nbMateria;
};
#endif