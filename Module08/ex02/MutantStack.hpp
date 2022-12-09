/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:21:37 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/09 02:19:56 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T, typename UnderlyingContainer = std::deque<T> >
class   MutantStack : public std::stack<T, UnderlyingContainer>
{
    public:
        MutantStack() : std::stack<T>()
        {
            std::cout << "MutantStack created." << std::endl;
        }
        MutantStack(MutantStack const & src)
        {
            *this = std::stack<T, UnderlyingContainer>(src);
        }
        MutantStack& operator=(MutantStack const & rhs)
        {
            if (this == &rhs)
				return *this;
            std::stack<T, UnderlyingContainer>::operator=(rhs);
            return *this;
        }
        ~MutantStack()
        {
            std::cout << "MutantStack destroyed." << std::endl;
        }

        typedef typename UnderlyingContainer::iterator iterator;
        iterator begin()
        {
            return std::stack<T>::c.begin();
        }
        iterator end()
        {
            return std::stack<T>::c.end();
        }
    private:
};
#endif

