/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:43:39 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/04 19:25:15 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    std::vector<int> numbers;

    for (int i = 0; i < 4; i++)
        numbers.push_back(i * 10);
        
    std::cout << "front: " << numbers.front();
    std::cout << "\nback: " << numbers.back() << '\n';

    std::cout << "full array: ";
    
    for (size_t i=0; i<numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;
    
    for (int i = 0; i < 50; i+=10)
    {
        try 
        {
            ::easyfind(numbers, i);
        }
        catch (std::exception & ex)
        {
            std::cout << "Element not found\n";
        }
    }
    return 0;
}