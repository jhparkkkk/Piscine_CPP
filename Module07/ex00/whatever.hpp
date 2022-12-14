/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:40:04 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/03 19:00:23 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP
#include <iostream>
#include <cstddef>
#include <iostream>
#include <string>

template < typename T >
void    swap(T & a, T &b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
    return;
}

template < typename T >
T const min(T const & a, T const & b)
{
    return (a < b) ? a : b;
}

template < typename T >
T const max(T const & a, T const & b)
{
    return (a > b) ? a : b;
}

#endif