/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:45:12 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/04 16:14:47 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cmath>

template <typename T>
void    test(T & n)
{
    n += n;
    return;
}

template <typename T>
void    toUpper(T & s)
{
    for (size_t i = 0; i < s.size(); i++)
        if (!isspace(s[i]))
            s[i] -= 32;       
}

int main()
{
    double tab[] = {0.10, 1.32, 2.2423, 3.5245, 4.523};

    for(int i = 0; i < 5; i++)
        std::cout << tab[i]<< std::endl;

    ::iter<double>(tab, 5, &::test);
    
    std::cout << std::endl;

    for(int i = 0; i < 5; i++)
        std::cout << tab[i]<< std::endl;
    
    std::string str[3] = {"jee", "park", "nice to meet you"};
    for(int i = 0; i < 3; i++)
        std::cout << str[i]<< " ";
        
    ::iter(str, 3, &::toUpper);
    
    std::cout << std::endl;

    for(int i = 0; i < 3; i++)
        std::cout << str[i]<< " ";

    std::cout << std::endl;

    return 0;
}
