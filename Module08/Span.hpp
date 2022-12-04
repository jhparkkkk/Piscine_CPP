/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:19:27 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/03 22:27:28 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
 #define SPAN_HPP
#include <iostream>

class   Span 
{
    public:
        Span(unsigned int const &);
        Span(Span const &);
        Span& operator=(Span const &);
        ~Span();

        unsigned int    getN() const;

    private:
        unsigned int    _N;
        int*            _tab;         


        Span();
};
#endif