/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:20:18 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/04 22:57:40 by jeepark          ###   ########.fr       */
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
        span3.longestSpan();
    }
    catch (Span::SpanException & ex)
    {
        std::cout << ex.what() << std::endl;
    }

    try 
    {
        span3.shortestSpan();
    }
    catch (Span::SpanException & ex)
    {
        std::cout << ex.what() << std::endl;
    }

    span3.addNumber(12);
    try 
    {
        span3.shortestSpan();
    }
    catch (Span::SpanException & ex)
    {
        std::cout << ex.what() << std::endl;
    }

    Span span4(6);
    span4.addNumber(0, 3, 10);

    std::cout << span4;
    return  0;
}