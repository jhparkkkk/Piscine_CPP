/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:36:35 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/24 15:00:43 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
 #define AMATERIA_HPP
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
		std::string _type;
    public:
		AMateria( void );
		AMateria(std::string const & type);
        AMateria( AMateria const & src);
        AMateria & operator=(AMateria const & rhs);
        virtual ~AMateria( void );
	
	
    	std::string const & getType() const; //Returns the materia type
    	virtual AMateria* clone() const = 0;
    	virtual void use(ICharacter & target);
};
#endif