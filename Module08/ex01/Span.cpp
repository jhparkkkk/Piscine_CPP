/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:20:32 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/04 22:58:38 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include<algorithm>

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
      std::cout << "\n---addNumber---\n";
      std::cout << "real size: " << _N << " size: " << _tab.size() << std::endl;
      if (_N == _tab.size())
      {
            std::cout << "full\n";
            throw(FullException());
      } 
      else
            _tab.push_back(n);
}

void  Span::addNumber(unsigned int start, unsigned int end, int const n)
{
      std::cout << "\n-----------------------\n";
      std::cout << "start: " << start << std::endl;
      std::cout << "end: " << end << std::endl;
      std::vector<int>::iterator itPos = _tab.begin() + start;
      for (unsigned int i = start; i < end; i++)
      {
            _tab.insert(itPos, n);
            itPos = _tab.begin();
      }
            
      
      
}



int   Span::shortestSpan() const
{
      if (_tab.empty() || _tab.size() == 1)
      {
            throw(SpanException());
            return 0;
      }
      std::vector<int> tmp = _tab;
      for (unsigned long i = 0; i < tmp.size(); i++)
            std::cout << tmp[i] << std::endl;
      std::sort(tmp.begin(), tmp.end());
      for (unsigned long i = 0; i < tmp.size(); i++)
            std::cout << tmp[i] << std::endl;
      int   res = abs(tmp.at(0) - tmp.at(1));
      int   min = 0;  
      for (unsigned long i = 0; i + 1 < tmp.size(); i++)
      {
            min = tmp[i+1] - tmp[i];
            min = abs(min);
            if (min <= res)
                  res = min;
      }
      std::cout << "shortest distance: " <<  res << std::endl;
      return res;
      return 0;
}

int   Span::longestSpan() const
{
      if (_tab.empty() || _tab.size() == 1)
      {
            throw(SpanException());
            return 0;
      }
      std::vector<int> tmp = _tab;
      std::cout << "before sort:\n";
      for (unsigned long i = 0; i < tmp.size(); i++)
            std::cout << tmp[i] << std::endl;
            
      std::sort(tmp.begin(), tmp.end());
      std::cout << "after sort:\n";
      
      for (unsigned long i = 0; i < tmp.size(); i++)
            std::cout << tmp[i] << std::endl;
      
      return tmp[tmp.size() - 1] - tmp[0];
}


/************************** NON MEMBER FUNCTION *******************************/
std::ostream & operator<<( std::ostream & o, Span const & rhs)
{
      (void)rhs;
    o << "\nsize: " << rhs.getN() << std::endl;
      for (unsigned long i = 0; i < rhs.getTab().size(); i++) {
        o << rhs.getTab()[i] << std::endl;
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