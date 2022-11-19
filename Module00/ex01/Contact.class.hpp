/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:06:10 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/14 16:16:11 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_CLASS_HPP
 #define CONTACT_CLASS_HPP

#include <iostream>

class Contact {
    
    public:
    /* constructor */
    Contact( void );
    
    /* destructor */
    ~Contact( void );

    /* setters */
    void setFirstName(std::string first_name);
    void setLastName(std::string last_name); 
    void setNickname(std::string nickname);
    void setPhoneNumber(std::string phone_number);
    void setDarkestSecret(std::string darkest_secret);
    
    /* getters */
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

        
    private:
    std::string _FirstName;
    std::string _LastName;
    std::string _Nickname;
    std::string _PhoneNumber;
    std::string _DarkestSecret;  
};


#endif