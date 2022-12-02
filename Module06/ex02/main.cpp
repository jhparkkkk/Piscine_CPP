/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:44:22 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/02 22:26:07 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>

/*
    instanciates object (A, B, C) inherited from class Base.  
*/
Base*   generate()
{
    srand(time(NULL));
    const int n = rand() % 3;
    std::cout << "generate class: " << n << std::endl;
    switch (n)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default: return NULL;
    }
}
/*
    test = dynamic_cast <A*> (p);
    if (test)
        std::cout << "A:" << test << std::endl;
    test = dynamic_cast <B*> (p);
    if (test)
        std::cout << "B:"  << test << std::endl;
    test = dynamic_cast <C*> (p);
    if (test)
        std::cout << "C:" << test << std::endl;
*/

/*
    initializes a pointers array[3], each index is casted dynamically. 
    Checks if test[i] is non null -> the cast has succeed. 
*/
void    identify(Base* p)
{
    std::cout << "-- identify --" << std::endl;
    Base*   test[3];
    test[0] = dynamic_cast <A*> (p);
    test[1] = dynamic_cast <B*> (p);
    test[2] = dynamic_cast <C*> (p);
    
    int i = -1;
    while (++i < 2)
        if (test[i])
            break;

    switch (i)
    {
        case 0:
            std::cout << "type is A" << std::endl; break;
        case 1:
            std::cout << "type is B" << std::endl; break;
        case 2:
            std::cout << "type is C" << std::endl; break;
        default:
            std::cout << "type is invalid" << std::endl; break;
    }
    return;
}

void    identify(Base & p)
{
    
    try
    {
        Base& test = dynamic_cast<A&>(p);
        (void)test;
        std::cout << "type is A" << std::endl;
        return; 
    }
    catch (std::exception & ex)
    {
        std::cout << ex.what() << std::endl;
    }
    try
    {
        Base& test = dynamic_cast<B&>(p);
        (void)test;
        std::cout << "type is B" << std::endl;
        return;  
    }
    catch (std::exception & ex)
    {
        std::cout << ex.what() << std::endl;
    }
    try
    {
        Base& test = dynamic_cast<C&>(p);
        (void)test;
        std::cout << "type is C" << std::endl;
        return;
    }
    catch (std::exception & ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return;
}

int main()
{
    Base* test;

    test = generate();
    
    identify(test);

    Base & testref = *generate();

    identify(testref);
    std::cout << "-- result --" << std::endl;
    std::cout << test << std::endl;
    std::cout << &testref << std::endl;
    
    delete test;
    delete &testref;
    return 0;
}
