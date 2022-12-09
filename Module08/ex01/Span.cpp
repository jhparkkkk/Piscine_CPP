/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:20:32 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/08 23:15:23 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <algorithm>

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/
Span::Span() { return; }

Span::Span(unsigned int const & N) : _N(N)
{
      std::vector<int> _tab(_N);
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

      _N = rhs.getN();
      std::vector<int> _tab[_N];
   
      return  *this;
}

Span::~Span( void )
{
      std::cout << "Span destroyed" << std::endl;
      return;
}
/************************** SETTERS & GETTERS *********************************/

unsigned int Span::getN( ) const { return _N; }

std::vector<int> Span::getTab() const {return _tab; }

/************************** PUBLIC MEMBER FUNCTION ****************************/
void  Span::addNumber(int const n)
{
      if (_N == _tab.size())
      {
            throw(FullException());
      } 
      else
            _tab.push_back(n);
}

void  Span::addNumber(unsigned int range, int const n)
{
      if (range > _N)
            throw(OutOfSpaceException());
      else
      {
            std::vector<int> anothervector (range , n);
            _tab.insert(_tab.begin(), anothervector.begin(), anothervector.end());
      }
      return;
      
}

int   Span::shortestSpan() const
{
      if (_tab.empty() || _tab.size() == 1)
      {
            throw(SpanException());
            return 0;
      }
      std::vector<int> tmp = _tab;
      std::sort(tmp.begin(), tmp.end());
      int   res = abs(tmp.at(0) - tmp.at(1));
      int   min = 0;  
      for (unsigned long i = 0; i + 1 < tmp.size(); i++)
      {
            min = tmp[i+1] - tmp[i];
            min = abs(min);
            if (min <= res)
                  res = min;
      }
      return res;
}

int   Span::longestSpan() const
{
      if (_tab.empty() || _tab.size() == 1)
      {
            throw(SpanException());
            return 0;
      }
      std::vector<int> tmp = _tab;
      std::sort(tmp.begin(), tmp.end());
      int res = tmp[tmp.size() - 1] - tmp[0];
      return res;
}


/************************** NON MEMBER FUNCTION *******************************/
std::ostream & operator<<( std::ostream & o, Span const & rhs)
{
      (void)rhs;
    o << "\nsize: " << rhs.getN() << std::endl;
      for (unsigned long i = 0; i < rhs.getTab().size(); i++) {
        o << i << ": " << rhs.getTab()[i] << std::endl;
    }
    return o;
}
/************************** EXCEPTIONS ****************************************/

const char * Span::FullException::what() const throw()
{
    return "cannot add number: already full.";
}

const char * Span::SpanException::what() const throw()
{
    return "Span cannot be found: not enough number.";
}

const char * Span::OutOfSpaceException::what() const throw()
{
    return "cannot add number: range is invalid";
}