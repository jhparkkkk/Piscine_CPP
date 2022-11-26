/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:36:15 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/26 10:36:42 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
 #define FORM_HPP
#include "Bureaucrat.hpp"
#include <iostream>

#define	YES 1
#define NO	0
#define LOWEST_GRADE 150
#define HIGHEST_GRADE 1

class Bureaucrat;

class   AForm
{
    public:
        AForm();
        AForm(std::string const &, int, int);
        AForm(AForm const &);
        AForm& operator=(AForm const &);
        virtual ~AForm() = 0;

        std::string const   getName() const;
        bool				getSigned() const;
		int					getGradeTosign() const;
        int					getGradeToExecute() const;

		void			beSigned(Bureaucrat const &);
		virtual void	execute(Bureaucrat const & executor) const = 0;
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
    
    private:
        const std::string	_name;
        bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;            

};

std::ostream & operator<<( std::ostream & o, AForm const & rhs);

#endif