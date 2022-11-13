/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileOpener.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:15:08 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/13 12:26:07 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FILEOPENER_H
 #define FILEOPENER_H
#include <iostream>
#include <fstream>

class   FileOpener {
    public:
        			FileOpener( void );
        			~FileOpener( void );
					
        bool		checkFile(int ac, char **av);
        bool		checkParam(int ac);
        void		setFilename(char *av);
        std::string	getFileName( void );
    private:
        std::string _fileName;

};

#endif