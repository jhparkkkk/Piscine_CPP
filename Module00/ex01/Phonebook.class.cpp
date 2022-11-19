/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:14:56 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/14 16:26:07 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

Phonebook::Phonebook( void )
{
    std::cout << "Phonebook constructor." << std::endl;
    return;
}

Phonebook::~Phonebook( void )
{
    std::cout << "Phonebook destructor." << std::endl;
    return; 
}


void    Phonebook::displayContact(std::string arg1, std::string arg2,
        std::string arg3, std::string arg4) const
{
    const std::string sep = "|" ;
    const std::string space = " ";

    std::cout << std::right << std::setw(10)  << arg1 << sep
            << std::right << std::setw(10)  << arg2 << sep
            << std::right << std::setw(10)  << arg3 << sep
            << std::right << std::setw(10)  << arg4 << sep << std::endl;
}

bool    Phonebook::check_phone_number(std::string str) const
{ 
    for (int i = 0; i < (int)str.length(); i++) 
    {
        if (str[i] < '0' || str[i] > '9') 
        {
            std::cout << "invalid phone number" << std::endl;
            return false;
        }
    } 
    return true; 
} 

void    print_msg(int idx)
{
    if (idx == 0)
        std::cout << std::endl << "* Add new contact *" << std::endl << "first name: ";
    else if (idx == 1)
        std::cout << "last name: ";
    else if (idx == 2)
        std::cout << "nickname: ";
    else if (idx == 3)
        std::cout << "phone number: ";
    else if (idx == 4)
        std::cout << "darkest secret: ";
    
}

int Phonebook::retrieve_data(int idx, std::string data, int num)
{
    if (std::cin.eof())
        return (1);
    if (idx == 0)
        this->contact[num].setFirstName(data);
    else if (idx == 1)
        this->contact[num].setLastName(data);
    else if (idx == 2)
        this->contact[num].setNickname(data);
    else if (idx == 3)
    {
        if (check_phone_number(data) == false)
            return 1;
        this->contact[num].setPhoneNumber(data);
    }
    else if (idx == 4)
        this->contact[num].setDarkestSecret(data);
    return 0;
}

int    Phonebook::add(int idx)
{
    std::string data;
    
    for (int i = 0; i < 5; i++)
    {
        print_msg(i);
        std::cin >> data;
        if (retrieve_data(i, data, idx))
            return 1;

    }
    std::cout << "* contact saved *" << std::endl;
    return(0);
}

void	Phonebook::search(int i)
{
    int count = 0;
    std::string index;
    displayContact("index", "first name", "last name", "nickname");
    while (count <= i)
    {
        displayContact(std::to_string(count), this->contact[count].getFirstName(),
        this->contact[count].getLastName(), this->contact[count].getNickname());
        count++;
    }
    std::cout << "enter index for more information: ";
	std::cin >> index;
    
    return;
}
