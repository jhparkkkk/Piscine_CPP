/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:13:42 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/30 23:35:09 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <stdlib.h>

#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define NB_TYPE 4

class   Convert 
{
    public:
        Convert();
        Convert(std::string const &);
        Convert(Convert const &);
        Convert& operator=(Convert const &);
        ~Convert();

        std::string getLitteral() const;
        int         getType() const;
        char        getChar() const;
        int         getInt() const;
        float       getFloat() const;
        double      getDouble() const;

        int         findPrecision(std::string) const;

        
    class   InvalidInputException : public std::exception
    {
        public:
            virtual const char * what() const throw();
    };
    
    private:
        std::string _str;
        char        _char;
        int         _type;
        int         _int;
        float       _float;
        double      _double;
        double      _toConvert;

        void        detectType();
        void        makeConversion();
        bool        isChar();
        bool        isInt();
        bool        isFloat();
        bool        isDouble();

        void        castChar();
        void        castInt();
        void        castFloat();
        void        castDouble();
        bool        check_format(std::string str);
        int static const _key[4];
        bool        (Convert::*_is[4])();
        void        (Convert::*_cast[4])();
        
};

std::ostream & operator<<( std::ostream & o, Convert const & rhs);
// int         getPrecision(std::string);


#endif


