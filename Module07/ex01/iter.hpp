/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:45:08 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/02 18:24:36 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
#include <stdint.h>
#include <iostream>
#include <cstddef>
#include <iostream>
#include <string>

template <typename T>
void    iter(const T * array, int size, void (*fct)(T const &))
{
    for (int i = 0; i < size; i++)
        fct(array[i]);
    
    return;
}

template <typename T>
void    iter( T * array, int size, void (*fct)(T &))
{
    for (int i = 0; i < size; i++)
        fct(array[i]);
    
    return;
}

#endif