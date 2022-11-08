/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:55:11 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/08 18:09:54 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

// info contact dans prive 

class Contact {
    public:
    Contact( );
    ~Contact( void );
    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getPhoneNumber();
    std::string getFirstName();
    
    private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;  
};

class Phonebook {
    public:
        Phonebook( void );
        ~Phonebook( void );
        void add(int idx);
        void search(int i);
    private:
        Contact contact[8];
            
};



#endif