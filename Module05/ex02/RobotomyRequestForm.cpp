/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:08:55 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/26 17:00:06 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <unistd.h>
// Required grades: sign 72, exec 45
// Makes some drilling noises. Then, informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, informs that the robotomy failed.

RobotomyRequestForm::RobotomyRequestForm()
{
      std::cout << "RobotomyRequestForm created" << std::endl;
      return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) :
AForm(target, 72, 45),
_target(target)
{
    std::cout << "RobotomyRequestForm " <<target<< " created" << std::endl;
    return;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src)
{
      std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
      *this = src;
      return;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
      std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
      static_cast <void> (rhs);
      return  *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
      std::cout << "RobotomyRequestForm destroyed" << std::endl;
      return;
}
/************************** SETTERS & GETTERS *********************************/
std::string RobotomyRequestForm::getTarget() const { return _target; }
/************************** PUBLIC MEMBER FUNCTIONS ***************************/

/*
      Before executing form, check with base method AForm::execute(Bureaucrat const & )
      if required conditions are ok. 
      Then execute form : robotomization succeed 50% of the time.
*/

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
      AForm::execute(executor);
      std::cout << "* drilling noises *" << std::endl;
      srand(time(NULL));
      const int n = rand() % 2;
      if (n)
            std::cout << getTarget() << " has been robotomized successfully." << std::endl;
      else
            std::cout << getTarget() << "Robotomization failed." << std::endl;
      return;
}
/************************** NON MEMBER FUNCTIONS ******************************/
/************************** EXCEPTIONS ****************************************/