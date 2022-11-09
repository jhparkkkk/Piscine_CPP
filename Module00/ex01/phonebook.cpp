/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:14:56 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/09 15:08:42 by jeepark          ###   ########.fr       */
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

int Phonebook::retrieve_data(int idx, std::string data)
{
    if (std::cin.eof())
        return(1);
    if (idx == 0)
        this->contact->setFirstName(data);
    else if (idx == 1)
        this->contact->setLastName(data);
    else if (idx == 2)
        this->contact->setNickname(data);
    else if (idx == 3)
        this->contact->setPhoneNumber(data);
    else if (idx == 4)
        this->contact->setDarkestSecret(data);
    return 0;
}

int    Phonebook::add(int idx)
{
    std::string data;
    
    for (int i = 0; i < 5; i++)
    {
        print_msg(i);
        std::cin >> data;
        if (retrieve_data(i, data))
            return 1;

    }
    std::cout << "* contact saved *" << std::endl;

    // std::cout << "first name: " << std::endl;
    // std::cin >> data;
    //  if (std::cin.eof())
    //     return(1);
    // if (!data.empty() )
    //     this->contact->setFirstName(data);
    // std::cout << "last name: " << std::endl;
    // std::cin >> data;
    // if (std::cin.eof())
    //     return(1);
    // if (!data.empty())
    //     this->contact->setLastName(data);
    // std::cout << "nickname: " << std::endl;
    // std::cin >> data;
    //  if (std::cin.eof())
    //     return(1);
    // if (!data.empty())
    //     this->contact->setNickname(data);
    // std::cout << "phone number: " << std::endl;
    // std::cin >> data;
    //  if (std::cin.eof())
    //     return(1);
    // if (!is_phone_number(data))
    // {
    //     std::cout << "Invalid phone number" << std::endl;
    //     return(EXIT_FAILURE);
    // }
    // this->contact->setPhoneNumber(data);
    // std::cout << "darkest secret: " << std::endl;
    // std::cin >> data;
    //  if (std::cin.eof())
    //     return(1);
    // if (!data.empty())
    //     this->contact->setDarkestSecret(data);
    return(0);
}

int    set_space(std::string arg)
{
    if (arg.length() >= 10)
        return (0);
    return (10 - arg.length());
}

/*
    .....index|first name|.last name|..nickname
    .........0|.......jee|......park|.....jeejo

*/
void    display_contact(std::string arg1, std::string arg2, std::string arg3, std::string arg4)
{
    arg1.resize(9);
    arg2.resize(9);
    arg3.resize(9);
    arg4.resize(9);

    const std::string sep = "|" ;
    const std::string space = " ";

    std::cout << std::right << std::string(set_space(arg1), ' ')  << arg1 << sep
            << std::right << std::string(set_space(arg2), ' ')   << arg2 << sep
            << std::right << std::string(set_space(arg3), ' ') << arg3 << sep
            << std::right << std::string(set_space(arg4), ' ') << arg4 << '\n';
    
}

void	Phonebook::search(int i)
{
    int count = 0;
    std::string index;
    display_contact("index", "first name", "last name", "nickname");
    while (count <= i)
    {
        display_contact(std::to_string(count), this->contact[count].getFirstName(),
        this->contact[count].getLastName(), this->contact[i].getNickname());
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
            if (phonebook.add(++i) == 1)
                break;
		}
        else if (cmd == "SEARCH")
		{
            // std::cout << i;
            phonebook.search(i);
        }
		else
            std::cout <<"Wrong command, try again: " << std::endl;
	}   
    return 0;
}

// check phone number 
// ctrl -D -> cin.eof a chercher
// SEARCH : 10 carac a droite : methode existe deja str.resize 
