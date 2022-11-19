/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:54:28 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/14 12:54:34 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_H
 #define HARL_H
#include <iostream>
#include <fstream>
#define NB_COMPLAIN 4
class Harl {
    public:
        Harl( void );
        ~Harl( void );

		void	complain(std::string level);
	
    private:
    	void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
    
};


#endif 