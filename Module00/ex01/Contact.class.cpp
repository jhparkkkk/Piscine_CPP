/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:52:31 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/14 16:17:40 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

/* Constructor */
Contact::Contact( void )
{
    std::cout << "Contact constructor." << std::endl;
    return; 
}

/* Destructor */
Contact::~Contact( void )
{
    std::cout << "Contact destructor." << std::endl;
    return; 
}

/* Setters */
void   Contact::setFirstName(std::string name) { _FirstName = name; }
void   Contact::setLastName(std::string name) { _LastName = name; }
void   Contact::setNickname(std::string name) { _Nickname = name; }
void   Contact::setPhoneNumber(std::string number) { _PhoneNumber = number; }
void   Contact::setDarkestSecret(std::string secret) { _DarkestSecret = secret; }

/* Getters */
std::string Contact::getFirstName() const { return _FirstName; }
std::string Contact::getLastName() const { return _LastName; }
std::string Contact::getNickname() const { return _Nickname; }
std::string Contact::getPhoneNumber() const { return _PhoneNumber; }
std::string Contact::getDarkestSecret() const { return _DarkestSecret; }