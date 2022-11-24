/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:37:12 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/24 15:00:40 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
 #define IMATERIASOURCE_HPP
#include <iostream>
#include "AMateria.hpp"

class   IMateriaSource
{
    public:
		virtual				~IMateriaSource() {}
    	virtual void		learnMateria(AMateria*) = 0;
    	virtual AMateria*	createMateria(std::string const & type) = 0;
};
#endif
