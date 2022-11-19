/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:55:11 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/14 16:25:42 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <vector>
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Contact.class.hpp"

class Phonebook {
    
    public:
        /* constructor */
        Phonebook( void );
        
        /* destructor */
        ~Phonebook( void );
        
        /* commands */ 
        int     add(int idx);
        void    search(int i);
        
        /* utils */
        int     retrieve_data(int i, std::string data, int idx);
        bool    check_phone_number(std::string str) const;
        void    displayContact(std::string d1, std::string d2, std::string d3, std::string d4 ) const;
    
    private:
        Contact contact[8];            
};


#endif