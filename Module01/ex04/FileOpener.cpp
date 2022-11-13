/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileOpener.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:22:09 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/13 18:51:27 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileOpener.hpp"
#include <filesystem>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


FileOpener::FileOpener( void )
{
    std::cout << "FileOpener created." << std::endl;
    return ;
}

FileOpener::~FileOpener( void )
{
    std::cout << "FileOpener destroyed" << std::endl;
    return ;
}

void    FileOpener::setFilename(char *av)
{    
    _fileName = av;
    return ;
}

std::string FileOpener::getFileName( void )
{
    return _fileName;
}

/*
    Checks is params are valid.
*/
bool    FileOpener::checkParam(int ac)
{
    if (ac != 4)
    {
        std::cout << "Error : enter 3 arguments [<namefile>, s1, s2]" << std:: endl;
        return false;
    }
    return true;
}

bool isDirectory(const char* fileName)
{
    struct stat path;

    stat(fileName, &path);

    return !S_ISREG(path.st_mode);
}


/*
    is params are valid, set _fileName as file to read
*/
bool    FileOpener::checkFile(int ac, char **av)
{
    if (checkParam(ac) == false)
        return false;
    setFilename(av[1]);   
     
    std::ifstream file_in = std::ifstream(_fileName);
    if (!file_in.is_open())
        return false;
    const char * name = _fileName.c_str();
    if (isDirectory(name) == true)
    {
        std::cout << "error: <" << _fileName << "> is a directory" << std::endl;
        return false;
    }
    file_in.close();
    return true;
}