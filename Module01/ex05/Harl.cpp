/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:58:17 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/14 12:42:54 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/
Harl::Harl( void )
{
    std::cout << std::endl;
    std::cout << "* CONSTRUCTOR *" << std::endl;
    std::cout << "Harl " << " created." << std::endl;
    return ;
}

Harl::~Harl( void )
{
    std::cout << std::endl;
    std::cout << "* DESTRUCTOR *" << std::endl;
    std::cout << "Harl " << " destroyed." << std::endl;
    return ;
}

/*********************** PUBLIC MEMBER FUNCTIONS *****************************/

void	Harl::complain(std::string level)
{  
    /* pointer function table */
    void		(Harl::* f[4])( void );
    f[0] = &Harl::debug;
    f[1] = &Harl::info;
    f[2] = &Harl::warning;
    f[3] = &Harl::error;

    /* command label table */
    std::string key[4];
    key[0] = "DEBUG";
    key[1] = "INFO";
    key[2] = "WARNING";
    key[3] = "ERROR";

    /* find command */
    for (int i = 0; i < 4; i++)
    {
        if (key[i] == level)
        {
            (this->*f[i])();
            return;
        }
    }
    
    /* error message */
    std::cout << std::endl;
    std::cout << level;
    std::cout << ": invalid complain.";
    std::cout << std::endl;
    return ; 
}

/*********************** PRIVATE MEMBER FUNCTIONS *****************************/


void    Harl::debug( void)
{
    std::cout << std::endl;
    std::cout << "* DEBUG *" << std::endl;
    std::cout << "I love having extra bacon for my";
    std::cout << " 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!";
    std::cout << std::endl;
    return;
}

void	Harl::info( void )
{
    std::cout << std::endl;
    std::cout << "* INFO *" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. ";
    std::cout << "You didn’t put enough bacon in my burger! ";
    std::cout << "If you did, I wouldn’t be asking for more!";
    std::cout << std::endl;
    
    return ;
}

void	Harl::warning( void )
{
    std::cout << std::endl;
    std::cout << "* WARNING *" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. ";
    std::cout << "I’ve been coming for years whereas you started working here since last month.";
    std::cout << std::endl;
    return ;
}

void	Harl::error( void )
{
    std::cout << std::endl;
    std::cout << "* ERROR *" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now.";
    std::cout << std::endl;
    return;
}

