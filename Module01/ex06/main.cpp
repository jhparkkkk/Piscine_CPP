/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:15:19 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/14 14:52:19 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (int ac, char **av)
{
    Harl harl = Harl();
    
    if (ac != 2)
    {
        std::cout << "Invalid argument: ./halFilter <complain>" << std::endl;
        return(EXIT_FAILURE);
    }

    harl.complain(av[1]);    


    return(EXIT_SUCCESS);
}