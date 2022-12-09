/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:20:18 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/08 23:18:39 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    Span span1(6);
    std::cout << span1;


    for (int i = 0; i < 100; i+=10)
    {
        try
        {
            span1.addNumber(i);
        }
        catch(Span::FullException & ex)
        {
            std::cout << ex.what();
            break;
        }
    }
    
    std::cout << span1 << std::endl;

    
    Span span2(5);
    span2.addNumber(-2);
    span2.addNumber(1);
    span2.addNumber(2);
    span2.addNumber(3);
    span2.addNumber(-2);
    
    span2.shortestSpan();
    span2.longestSpan();
    
    Span span3(2);
    span3.addNumber(3);
    try 
    {
        std::cout << span3.longestSpan() << std::endl;
    }
    catch (Span::SpanException & ex)
    {
        std::cout << ex.what() << std::endl;
    }

    try 
    {
        std::cout << span3.shortestSpan() << std::endl;
    }
    catch (Span::SpanException & ex)
    {
        std::cout << ex.what() << std::endl;
    }

    span3.addNumber(12);
    try 
    {
        std::cout << span3.shortestSpan() << std::endl;
    }
    catch (Span::SpanException & ex)
    {
        std::cout << ex.what() << std::endl;
    }

    Span span4(6);
    std::vector<int> span(4);
    try
    {
        span4.addNumber(static_cast <unsigned int>(-12), 9);
    }
    catch (Span::OutOfSpaceException & ex)
    {
        std::cout << ex.what() << std::endl;
    }
    try
    {
        span4.addNumber(static_cast <unsigned int>(6), 9);
    }
    catch (Span::OutOfSpaceException & ex)
    {
        std::cout << ex.what() << std::endl;
    }
    std::cout << span4;


    return  0;
}