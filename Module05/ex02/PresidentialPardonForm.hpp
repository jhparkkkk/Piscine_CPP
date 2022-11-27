/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:08:41 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/25 18:13:52 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
 #define PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include "AForm.hpp"

// class AForm;

class   PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const &);
        PresidentialPardonForm(PresidentialPardonForm const &);
        PresidentialPardonForm& operator=(PresidentialPardonForm const &);
        ~PresidentialPardonForm();
        
        std::string getTarget() const;

		virtual void	execute(Bureaucrat const & executor) const;

    private:
        std::string _target;
};
#endif
