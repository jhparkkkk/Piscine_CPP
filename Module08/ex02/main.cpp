/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:21:31 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/09 02:19:19 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    MutantStack <int>test;

    for (size_t i = 0; i <= 10; i++)
        test.push(i * 10);

    std::cout << "displaying data from front to back with iterator:\n";
    MutantStack<int>::iterator it_front = test.begin();
    for (size_t i = 0; i < test.size(); i++)
        std::cout << *it_front++ << ' ';

    std::cout << "\n\ndisplaying data from back to front with iterator:\n";
    MutantStack<int>::iterator it_back = test.end();
    for (size_t i = 0; i < test.size(); i++)
        std::cout << *--it_back << ' ';

    std::cout << "\n\ntop element is:\n";
    std::cout << test.top() << '\n';
    std::cout << "\nsize is:\n";
    std::cout << test.size() << '\n';
    test.pop();
    std::cout << "\ntop element after popping 1 element:\n";
    std::cout << test.top() << '\n';
    std::cout << test.size() << '\n';

    return 0;
}
