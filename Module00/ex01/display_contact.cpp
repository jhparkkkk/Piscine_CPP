/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_contact.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:08:50 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/10 17:18:25 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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