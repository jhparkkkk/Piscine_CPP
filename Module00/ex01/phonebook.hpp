/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:55:11 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/09 14:59:56 by jeepark          ###   ########.fr       */
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
    /* constructor & destructor */
    Contact( void );
    ~Contact( void );

    /* set private var */
    void setFirstName(std::string first_name) { _FirstName = first_name; }
    void setLastName(std::string last_name) { _LastName = last_name; }
    void setNickname(std::string nickname) { _Nickname = nickname; }
    void setPhoneNumber(std::string phone_number) { _PhoneNumber = phone_number; }
    void setDarkestSecret(std::string darkest_secret) { _DarkestSecret = darkest_secret; }
    
    /* get private var */
    std::string getFirstName() const { return _FirstName; }
    std::string getLastName() const { return _LastName; }
    std::string getNickname() const { return _Nickname; }
    std::string getPhoneNumber() const { return _PhoneNumber; }
    std::string getDarkestSecret() const { return _DarkestSecret; }
    
    private:
    std::string _FirstName;
    std::string _LastName;
    std::string _Nickname;
    std::string _PhoneNumber;
    std::string _DarkestSecret;  
};


class Phonebook {
    public:
        Phonebook( void );
        ~Phonebook( void );
        int add(int idx);
        void search(int i);
        int retrieve_data(int i, std::string data);
    private:
        Contact contact[8];
            
};



#endif