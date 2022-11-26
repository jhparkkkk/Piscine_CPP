/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:09:05 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/25 18:13:22 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ShrubberyCreationForm: Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees
// inside it.

#ifndef SHRUBBERYCREATIONFORM_HPP
 #define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include "AForm.hpp"

class AForm;

class   ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const &);
        ShrubberyCreationForm(ShrubberyCreationForm const &);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm const &);
        ~ShrubberyCreationForm();
        
        std::string getTarget() const;

		virtual void	execute(Bureaucrat const &) const;
    private:
        std::string _target;
};
#endif