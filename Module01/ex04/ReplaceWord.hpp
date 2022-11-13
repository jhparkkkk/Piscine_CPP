/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceWord.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:47:00 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/13 12:47:35 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef REPLACEWORD_H
 #define REPLACEWORD_H
#include <iostream>
#include <fstream>

class   ReplaceWord {
    public:
        ReplaceWord( std::string file_in, std::string s1, std::string s2);
        ~ReplaceWord( void );
        
        std::string getS1( void );
        std::string getS2( void );
        std::string getFileIn( void );
        void		textEdit(void);
	
    private:
		std::string _fileIn;
        std::string _s1;
        std::string _s2;

};

#endif