/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:42:57 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/13 18:48:26 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "FileOpener.hpp"
#include "ReplaceWord.hpp"


int main(int ac, char **av)
{
    FileOpener open = FileOpener();
    
    if (open.checkFile(ac, av) == false)
        return (EXIT_FAILURE);
    std::cout << "Valid file" << std::endl;
    ReplaceWord replace = ReplaceWord(av[1], av[2], av[3]);
    replace.textEdit();
    
    return 0;
}