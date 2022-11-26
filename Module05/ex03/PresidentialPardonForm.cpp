/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:08:48 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/26 16:19:25 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox.

PresidentialPardonForm::PresidentialPardonForm() :
_target("default")
{
      std::cout << "PresidentialPardonForm created" << std::endl;
      return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) :
AForm(target, 25, 5),
_target(target)
{
    std::cout << "PresidentialPardonForm " <<target<< " created" << std::endl;
    return;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src)
{
      std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
      *this = src;
      return;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
      std::cout << "PresidentialPardonForm Copy assignment operator called" << std::endl;
      static_cast <void> (rhs);
      return  *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
      std::cout << "PresidentialPardonForm destroyed" << std::endl;
      return;
}
/************************** SETTERS & GETTERS *********************************/
std::string PresidentialPardonForm::getTarget() const { return _target; }
/************************** PUBLIC MEMBER FUNCTIONS ***************************/

/*
      Before executing form, check with base method AForm::execute(Bureaucrat const & )
      if required conditions are ok. 
      Then execute form : 
*/

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
      AForm::execute(executor);
      std::cout << getTarget() << "has been pardoned by Zaphod Beeblebrox." << std::endl;
      return;
}
/************************** NON MEMBER FUNCTIONS ******************************/
/************************** EXCEPTIONS ****************************************/