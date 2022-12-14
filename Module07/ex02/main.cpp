/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:37:27 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/03 20:42:24 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <stdlib.h> 

int main()
{

    Array <int> test(4);
    Array <int> test2(3);
    
    std::cout << "* first array *" << '\n';
    std::cout << test << std::endl;
    
    std::cout << "* second array *" << '\n';
    std::cout << test2 << std::endl;

    // std::cout << "* assignment *" << '\n';
    test2 = test;
    std::cout << test2 << std::endl;

    Array <int> test3(-1);
    std::cout << test3 << std::endl;

    return 0;
}