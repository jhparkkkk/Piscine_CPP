/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:54:50 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/23 13:32:11 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#include <iostream>

class Brain
{
    public:
        Brain( void );
        Brain(Brain const &);
        Brain& operator=(Brain const &);
        ~Brain();

        void        setIdeas(std::string);
        void        displayIdeas() const;
    private:
        std::string _ideas[100];

};
