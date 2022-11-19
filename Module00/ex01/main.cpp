/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:50:03 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/14 16:16:36 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"
#include "Contact.class.hpp"

int main(int ac, char **av)
{
    (void)av;
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