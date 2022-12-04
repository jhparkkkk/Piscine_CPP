/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:20:32 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/03 22:29:55 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/
Span::Span() { return; }

Span::Span(unsigned int const & N) : _N(N)
{
    _tab = new int [_N]();
    std::cout << "Span created" << std::endl;
    return;
}

Span::Span( Span const & src)
{
      std::cout << "Span Copy constructor called" << std::endl;
      *this = src;
      return;
}

Span & Span::operator=(Span const & rhs)
{
      std::cout << "Span Copy assignment operator called" << std::endl;
      (void)rhs;
      if (_tab)
        delete [] _tab;
      _N = rhs.getN();
      _tab = new int [_N];
      for (unsigned int i = 0; i < _N; i++)
        _tab[i] = rhs._tab[i];
      return  *this;
}

Span::~Span( void )
{
      std::cout << "Span destroyed" << std::endl;
      return;
}
/************************** SETTERS & GETTERS *********************************/

unsigned int Span::getN( ) const { return _N; }

/************************** PUBLIC MEMBER FUNCTION ****************************/



/************************** NON MEMBER FUNCTION *******************************/
/************************** EXCEPTIONS ****************************************/