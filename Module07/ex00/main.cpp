/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:39:59 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/01 22:41:37 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
    
    {
        std::cout << "* swap *" << std::endl;
        int a = 10;
        int b = 20;
        std::cout << "a: " << a << " b: " << b << std::endl;
        swap<int>(a, b); // explicit instanciation
        std::cout << "a: " << a << " b: " << b << std::endl;
        swap(a, b); // implicit instanciation
        std::cout << "a: " << a << " b: " << b << std::endl;
    
        float c = 42.5;
        float d = 1.9;  
        std::cout << "c: " << c << " d: " << d << std::endl;
        swap<float>(c, d); 
        std::cout << "c: " << c << " d: " << d << std::endl;
        swap(c, d);
        std::cout << "c: " << c << " d: " << d << std::endl;
    }
    
    {
        std::cout << "* min & max *" << std::endl;
        int a = 1;
        int b = 42;
        std::cout << "min: " << min<int>(a,b) << std::endl;
        std::cout << "max: " << max<int>(a,b) << std::endl;
    }
    

    return 0;

}
