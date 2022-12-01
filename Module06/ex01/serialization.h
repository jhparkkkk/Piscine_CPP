/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialization.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:52:05 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/01 12:19:50 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_H
 #define SERIALIZATION_H
#include <stdint.h>

struct  Data  
{
    char    data1;
    int     data2;
    float   data3;
    double  data4;    
};

uintptr_t   serialize(Data *ptr);
Data*       deserialize(uintptr_t raw);            

#endif
