/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:20:16 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/26 20:00:05 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/
Intern::Intern()
{
    std::cout << "Intern created" << std::endl;
    _f[0] = &Intern::makeShrubberyCreation;
    _f[1] = &Intern::makeRobotomyRequest;
    _f[2] = &Intern::makePresidentialPardon;
    return;
}

Intern::Intern( Intern const & src)
{
    std::cout << "Intern Copy constructor called" << std::endl;
    *this = src;
    return;
}

Intern & Intern::operator=(Intern const & rhs)
{
    (void)rhs;    
    std::cout << "Intern Copy assignment operator called" << std::endl;
    return  *this;
}

Intern::~Intern( void )
{
      std::cout << "Intern destroyed" << std::endl;
      return;
}
/************************** SETTERS & GETTERS *********************************/
/************************** PRIVATE MEMBER FUNCTION ****************************/
AForm*  Intern::makeShrubberyCreation(std::string target)
{
    return new ShrubberyCreationForm(target);
}
AForm*  Intern::makeRobotomyRequest(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardon(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm*  Intern::makeForm(std::string name, std::string target)
{
    AForm *form = NULL;
    int idx = 0;
    while (idx < 3 && _key[idx] != name)
        idx++;
    switch (idx)
    {
        case 0:
            form = (this->*_f[0])(target); break;
        case 1:
            form = (this->*_f[1])(target); break;
        case 2:
            form = (this->*_f[2])(target); break;
        default:
            throw InvalidFormException();    
    }
    return form;
}
/************************** NON MEMBER ATTRIBUTES *******************************/
std::string const Intern::_key[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
/************************** EXCEPTIONS ****************************************/
const char * Intern::InvalidFormException::what() const throw()
{
    return "Form does not exist";
}
