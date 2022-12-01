/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:02:54 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/01 12:08:38 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialization.h"

uintptr_t serialize(Data *ptr)
{
    return reinterpret_cast <uintptr_t>(ptr);
}
