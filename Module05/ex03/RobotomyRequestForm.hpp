/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:08:58 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/25 18:13:40 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
 #define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include "AForm.hpp"

// class AForm;

class   RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const &);
        RobotomyRequestForm(RobotomyRequestForm const &);
        RobotomyRequestForm& operator=(RobotomyRequestForm const &);
        ~RobotomyRequestForm();
        
        std::string getTarget() const;

		virtual void	execute(Bureaucrat const &) const;

    private:
        std::string _target;
};
#endif