/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:13:36 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/02 21:57:57 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"
#include <limits>

int  main (int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Invalid input: only one argument authorized." << std::endl;
        exit(-1);
    }
    Convert convert;
    try
    {
        convert = Convert(av[1]);
    }
    catch (const Convert::InvalidInputException & ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}
