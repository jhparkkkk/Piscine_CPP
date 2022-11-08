/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:14:56 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/08 18:07:50 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <iomanip>

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
    auto it = data.begin();
    while (it != data.end() && std::isdigit(*it)) {
        it++;
    }
    return !data.empty() && it == data.end();
}

void    Phonebook::add(int idx)
{
    std::string data;
    
	std::cout << "add : " << idx << std::endl;
    std::cout << "first name: " << std::endl;
    std::cin >> data;
	// if (cin.fail())
    if (!data.empty() )
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
    if (!is_phone_number(data))
    {
        std::cout << "Invalid phone number" << std::endl;
        exit(EXIT_FAILURE);
    }
    this->contact[idx].phone_number = data;
    std::cout << "darkest secret: " << std::endl;
    std::cin >> data;
    if (!data.empty())
        this->contact[idx].darkest_secret = data;
    return;
}

std::string    set_space(std::string arg)
{
    std::string space;

    space = string(10 - arg.size());
    return space;
}

/*
    .....index|first name|.last name|..nickname
    .........0|.......jee|......park|.....jeejo

*/
void    display_contact(std::string arg1, std::string arg2, std::string arg3, std::string arg4)
{
    arg1.resize(10);
    arg2.resize(10);
    arg3.resize(10);
    arg4.resize(10);

    const std::string sep = "|" ;
    const std::string space = " ";
    std::cout << std::right << set_space(2, " ")  << arg1 << sep
            << std::right << set_space(2, " ")  << arg2 << sep
            << std::right <<  set_space(2, " ") << arg3 << sep
            << std::right <<  set_space(2, " ") << arg4 << '\n';
    // std::cout << std::right << std::setw(10) << std::string(arg1.length() - 10, 32)  << arg1 << sep
    //         << std::right << std::setw(10)<< std::string(arg2.length() - 10, 32)   << arg2 << sep
    //         << std::right << std::setw(10) << arg3 << sep
    //         << std::right << std::setw(10) << arg4 << '\n';
    
}

void	Phonebook::search(int i)
{
    int count = 0;
    std::string index;
    display_contact("index", "first name", "last name", "nickname");
    while (count <= i)
    {
        if (this->contact->first_name.empty())
            return;
        display_contact(std::to_string(count), this->contact[count].first_name,
        this->contact[count].last_name, this->contact[i].nickname);
        count++;
    }
    std::cout << "enter index for more information: ";
	std::cin >> index;
    
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
    
    while (!std::cin.eof())
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
		{
            // std::cout << i;
            phonebook.search(i);
        }
		else
            std::cout <<"Wrong command, try again: " << std::endl;
	}
        // std::cout << "command ADD" << std::endl; 
        // phonebook.contact[0].first_name = "jee";
        // std::cout << phonebook.contact[1].first_name;
        
    return 0;
}

// check phone number 
// ctrl -D -> cin.eof a chercher
// SEARCH : 10 carac a droite : methode existe deja str.resize 
