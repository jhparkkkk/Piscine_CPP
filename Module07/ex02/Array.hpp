/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:36:46 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/04 19:29:21 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdint.h>
#include <bitset>
#include <climits>
#include <cstring>
#include <iostream>
template< typename T>
class   Array
{
    public:
        Array<T>() : _size(0)
        {
			_tab = new T[_size]();
			bzero(_tab, _size);
			std::cout << "Default Array< T > created" << std::endl;
    		return;
		}
        Array<T>(unsigned int const & size ) 
		{
            try{
                _size = size;
            }
            catch (std::exception & ex) {
                std::cout << ex.what() << std::endl;
                return;
            }
			_tab = new T[_size]();
			bzero(_tab, _size);
    		std::cout << "Array< T > created" << std::endl;
    		return;
		}
        Array<T>(Array<T> const & src)
		{
			*this = src;
		}
		T & operator[](int index)
		{
			if (index < 0 || static_cast <unsigned int>(index) >= _size)
				throw (std::exception());
			return _tab[index];
		} 
        Array<T> & operator=(Array<T> const & rhs)
		{
			if (this == &rhs)
				return *this;
			if (this->_size > 0)
				delete [] this->_tab;
			this->_tab = new T[rhs.size()]();
			for(unsigned int i = 0; i < rhs.size(); i++)
				this->_tab[i] = rhs._tab[i];
			
			this->_size = rhs.size();
			return *this;
		}
        ~Array<T>()
		{
			std::cout << "destructor" << std::endl;
			if (this->_tab)
			    delete[] this->_tab;
		}
		unsigned int size() const
		{
			return this->_size;
		} 
        T* _tab;
    private:
		unsigned int _size;
};

template< typename T>
std::ostream & operator<<(std::ostream & o, Array<T> const & rhs)
{

	o << "size: "<< rhs.size() <<  std::endl;
	try
	{
		for (unsigned int i = 0; i < rhs.size(); i++)
			o << rhs._tab[i] << std::endl;
		return o;
		
	}
	catch (std::exception & ex) { std::cout << ex.what(); }
	
	return o;
}

#endif