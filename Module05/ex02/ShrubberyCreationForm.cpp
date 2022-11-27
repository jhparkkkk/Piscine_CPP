/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:09:02 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/26 17:00:22 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
{
      std::cout << "ShrubberyCreationForm created" << std::endl;
      return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) :
AForm(target, 145, 137),
_target(target)
{
    std::cout << "ShrubberyCreationForm " <<target<< " created" << std::endl;
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src)
{
      std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
      *this = src;
      return;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
      std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
      static_cast <void> (rhs);
      return  *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
      std::cout << "ShrubberyCreationForm destroyed" << std::endl;
      return;
}
/************************** SETTERS & GETTERS *********************************/
std::string ShrubberyCreationForm::getTarget() const { return _target; }
/************************** PUBLIC MEMBER FUNCTIONS ***************************/

/*
      Before executing form, check with base method AForm::execute(Bureaucrat const & )
      if required conditions are ok. 
      Then execute form : writes ascii tree in <_name>_shrubbery
*/

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
      AForm::execute(executor);
      std::ofstream file = std::ofstream(getTarget() + "_shrubbery");
      file << "− ···· ·· ···  ·· ···  ·−  − ·−· · · " << std::endl;
      file.close();
      return;
}

/************************** NON MEMBER FUNCTIONS ******************************/
/************************** EXCEPTIONS ****************************************/