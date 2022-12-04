/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:44:14 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/04 19:21:33 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void    easyfind(std::vector<T> p1, int p2)
{
    // for (size_t i=0; i<p1.size(); i++)
    //     std::cout << " " << p1[i];

    std::vector<int>::iterator it;    
    
    it = std::find(p1.begin(), p1.end(), p2);
    if (it != p1.end())
    {
        std::cout << "Element " << p2 << "found at position: ";
        std::cout << it - p1.begin() << '\n';
    }
    else
        throw(std::exception());
    return;
}

#endif