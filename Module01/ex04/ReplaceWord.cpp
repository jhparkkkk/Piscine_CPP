/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceWord.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:59:24 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/19 18:42:58 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceWord.hpp"

ReplaceWord::ReplaceWord(std::string file_in, std::string s1, std::string s2) : _fileIn(file_in), _s1(s1), _s2(s2)
{
    std::cout << "ReplaceWord created." << std::endl;
    std::cout << "Word to be replaced: " << s1 << std::endl;
    std::cout << "Word to replace the old one: " << s2 << std::endl;

    return ;
}

ReplaceWord::~ReplaceWord( void )
{
    std::cout << "ReplaceWord destroyed" << std::endl;
    return ;
}

std::string ReplaceWord::getFileIn( void )
{
    return _fileIn;
}


std::string ReplaceWord::getS1( void )
{
    return _s1;
}

std::string ReplaceWord::getS2( void )
{
    return _s2;
}

void    ReplaceWord::textEdit(void)
{
    std::cout <<std::endl <<  "text Edit" << std::endl;
    std::string old_s = getS1();
    std::string new_s = getS2();
    std::string file_out_name = getFileIn() + ".replace";
    std::string buffer;
    size_t key = 0;
    std::ifstream file_in = std::ifstream(getFileIn(), std::ios_base::in);
    std::ofstream file_out = std::ofstream(file_out_name, std::ios_base::out);
    
    // check if file is empty
    int c = file_in.peek();  // peek character
    if ( c == EOF )
    {
        std::cout << "File is empty" << std::endl;
        return ;
    }
    while(!file_in.eof())
    {
        
        std::getline(file_in, buffer); 
        while(1)    
        {
            key = buffer.find(old_s, key);
            std::cout << "buf: " << buffer << std::endl;
            std::cout << "key: " << key << std::endl;
            std::cout << "key + old_s : " << key + old_s.size() << std::endl;
            if (key == std::string::npos)
                break;
            if (buffer[key + old_s.size()] != '\0' && isspace(buffer[key + old_s.size()]) == 0)
            {
                while (isspace(buffer[key]) == 0)
                {
                    if (key == std::string::npos)
                        break;
                    key++;
                    key = buffer.find(old_s, key);
                    
                    if (isspace(buffer[key + old_s.size()]) != 0)
                    {
                        break ;                    
                    }


                }
            }
            // }
            else
            {
                buffer.erase(key, old_s.size());
                buffer.insert(key, new_s);
                key += new_s.size();
            }
        }
        file_out << buffer << std::endl;
        key = 0;
    }
    file_in.close();
    file_out.close();

    return ;
} 