/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:20:06 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/26 19:49:40 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
 #define INTERN_HPP
#include <iostream>
#include "AForm.hpp"
class   Intern 
{
    public:
        Intern();
        Intern(std::string const &);
        Intern(Intern const &);
        Intern& operator=(Intern const &);
        ~Intern();
        
        AForm*  makeForm(std::string, std::string);
        class   InvalidFormException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };
    private:
        AForm*  makeShrubberyCreation(std::string);
        AForm*  makeRobotomyRequest(std::string);
        AForm*  makePresidentialPardon(std::string);
        
        std::string static const    _key[3];
        AForm*                        (Intern::*_f[3])(std::string);
};
#endif