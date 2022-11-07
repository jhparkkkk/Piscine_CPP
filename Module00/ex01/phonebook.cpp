/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:14:56 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/07 16:54:54 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

#include "phonebook.hpp"

Contact::Contact( void )
{
    std::cout << "Contact constructor." << std::endl;
    return; 
}

Contact::~Contact( void )
{
    std::cout << "Contact destructor." << std::endl;
    return; 
}

Phonebook::Phonebook( void )
{
    std::cout << "Phonebook constructor." << std::endl;
    // Contact contact[8] = new Contact();
    return;
}

Phonebook::~Phonebook( void )
{
    std::cout << "Phonebook destructor." << std::endl;
    return; 
}



bool	is_phone_number(std::string data)
{
	
}

void    Phonebook::add(int idx)
{
    std::string data;
    
	std::cout << "add : " << idx << std::endl;
    std::cout << "first name: " << std::endl;
    std::cin >> data;
	// if (cin.fail())
    if (!data.empty())
        this->contact[idx].first_name = data;
    std::cout << "last name: " << std::endl;
    std::cin >> data;
    if (!data.empty())
        this->contact[idx].last_name = data;
    std::cout << "nickname: " << std::endl;
    std::cin >> data;
    if (!data.empty())
        this->contact[idx].nickname = data;
    std::cout << "phone number: " << std::endl;
    std::cin >> data;
    if (!data.empty())
        this->contact[idx].phone_number = data;
    std::cout << "darkest secret: " << std::endl;
    std::cin >> data;
    if (!data.empty())
        this->contact[idx].darkest_secret = data;
    return;
}

void	Phonebook::search()
{
	std::cout << "command search" << std::endl;
	return;
}





int main(int ac, char **av)
{
    if (ac != 1)
    {
		std::cout << "Argument not permitted" << std::endl;
		return (EXIT_FAILURE);
	}
    Phonebook phonebook = Phonebook();
    std::string cmd;
    int i = -1;

    while (1)
    {
        std::cout << "Enter command: ";
        std::cin >> cmd;
        if (cmd == "ADD")
        {
			if (i == 7)
				i = -1;
            phonebook.add(++i);
		}
        else if (cmd == "SEARCH")
			phonebook.search();
		else
            std::cout <<"Wrong command, try again: ";
	}
        // std::cout << "command ADD" << std::endl; 
        // phonebook.contact[0].first_name = "jee";
        // std::cout << phonebook.contact[1].first_name;
        
    return 0;
}

// ctrl -D -> cin.eof a chercher
// SEARCH : 10 carac a droite : methode existe deja
