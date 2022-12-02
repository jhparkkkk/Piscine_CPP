/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:56:20 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/02 22:08:48 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialization.h"
#include <iostream>

void    create_data(Data *set, char d1, int d2, float d3, double d4)
{
    set->data1 = d1;
    set->data2 = d2;
    set->data3 = d3;
    set->data4 = d4;
}

void    display_data(Data *set)
{
    std::cout << "Char: " << set->data1 << std::endl;
    std::cout << "Int: " << set->data2 << std::endl;
    std::cout << "Float: " << set->data3 << std::endl;
    std::cout << "Double: " << set->data4 << std::endl;
}


int main()
{
    Data set; 
    create_data(&set, 'A', 65, 65.0, 65.0);
    display_data(&set);

    /* serialiization */   
    uintptr_t serialized_data = serialize(&set);
    
    /* deserialization */
    Data * deserialized_data = deserialize(serialized_data);
    display_data(deserialized_data);
    
    return 0;
}
