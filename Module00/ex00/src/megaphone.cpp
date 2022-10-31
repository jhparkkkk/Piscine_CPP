/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:33:09 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/31 16:18:21 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (EXIT_FAILURE);
    }   
    for (int i = 1; i < ac; i++)
    {
        std::string str=av[i];
        std::transform(str.begin(), str.end(),str.begin(), ::toupper);
        std::cout << ""<< str <<" ";
    }
    std::cout << std::endl;
    return (EXIT_SUCCESS);
}