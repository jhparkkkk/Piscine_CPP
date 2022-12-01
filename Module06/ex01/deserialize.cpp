/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deserialize.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:55:55 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/01 12:43:53 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialization.h"

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast <Data*> (raw);
}
