/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:43:39 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/03 18:31:13 by jeepark          ###   ########.fr       */
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
        
    std::cout << "\nfront: " << numbers.front();
    std::cout << "\nback: " << numbers.back() << '\n';

    ::easyfind(numbers, 10);

    return 0;
}