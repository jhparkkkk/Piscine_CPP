/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:55:11 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/07 16:14:04 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

class Contact {
    public:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;  
    Contact( void );
    ~Contact( void );
    // private:
    
};

class Phonebook {
    public:
        Phonebook( void );
        ~Phonebook( void );
        Contact contact[8];
        void add(int idx);
        void search();
                  
};



#endif