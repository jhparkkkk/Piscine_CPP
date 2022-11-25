/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:36:15 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/25 15:21:42 by jeepark          ###   ########.fr       */
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

class   Form
{
    public:
        Form();
        Form(std::string const &, int, int);
        Form(Form const &);
        Form& operator=(Form const &);
        ~Form();

        std::string const   getName() const;
        bool				getSigned() const;
		int					getGradeTosign() const;
        int					getGradeToExecute() const;

		void				beSigned(Bureaucrat const &);
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{ return "grade is to high" ; }		
		};
	
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{ return "grade is too low" ;}
		};
    
    private:
        const std::string	_name;
        bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;            

};

std::ostream & operator<<( std::ostream & o, Form const & rhs);

#endif