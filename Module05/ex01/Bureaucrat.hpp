/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:40:29 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/25 15:53:37 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
 #define BUREAUCRAT_HPP
#include <iostream>
#include "Form.hpp"
#define LOWEST_GRADE 150
#define HIGHEST_GRADE 1

class   Form;

class   Bureaucrat {
    public:
        Bureaucrat();
        Bureaucrat(std::string const &, int);
        Bureaucrat(Bureaucrat const &);
        Bureaucrat& operator=(Bureaucrat const &);
        ~Bureaucrat();

        std::string const   getName() const;
        int                 getGrade() const;

        void                gradeUp();
        void                gradeDown();
        void                signForm(Form &);

    class   GradeTooHighException : public std::exception
    {
        public:
            virtual const char * what() const throw();
    };
    class   GradeTooLowException : public std::exception
    {
        public:
            virtual const char * what() const throw();
    };
    
    private:
        std::string const   _name;
        int                 _grade;  
};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs);

#endif