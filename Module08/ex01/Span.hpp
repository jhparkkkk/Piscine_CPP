/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:19:27 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/08 22:53:00 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
 #define SPAN_HPP
#include <iostream>
#include <vector>
class   Span 
{
    public:
        Span(unsigned int const &);
        Span(Span const &);
        Span& operator=(Span const &);
        ~Span();

        unsigned int    getN() const;
        std::vector<int>    getTab() const;

        void            addNumber(int const n);
        int             shortestSpan() const;
        int             longestSpan() const;
        
        void            addNumber(unsigned int, int const n);

        class   FullException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };
        class   SpanException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };
        class   OutOfSpaceException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };

    private:
        unsigned int        _N;
        std::vector<int>    _tab;         


        Span();
};

std::ostream & operator<<( std::ostream & o, Span const & rhs);

#endif